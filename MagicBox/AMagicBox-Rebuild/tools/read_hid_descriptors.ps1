# read_hid_descriptors.ps1 - dump HID identity and the raw report descriptor.
#
# Used to clone a real mouse: the report descriptor gives the exact field layout
# (this mouse packs X/Y as 12-bit fields), and VID/PID + product string let the
# left chip present itself as the same device.
#
#   powershell -NoProfile -File tools\read_hid_descriptors.ps1
#   powershell -NoProfile -File tools\read_hid_descriptors.ps1 -Filter 'c077'
param(
    [string]$Filter = ''
)

$ErrorActionPreference = 'Stop'

$sig = @'
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using Microsoft.Win32.SafeHandles;

public static class HidTool
{
    [StructLayout(LayoutKind.Sequential)]
    public struct HIDD_ATTRIBUTES { public int Size; public ushort VendorID; public ushort ProductID; public ushort VersionNumber; }

    [StructLayout(LayoutKind.Sequential)]
    public struct HIDP_CAPS
    {
        public ushort Usage, UsagePage, InputReportByteLength, OutputReportByteLength, FeatureReportByteLength;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 17)] public ushort[] Reserved;
        public ushort NumberLinkCollectionNodes, NumberInputButtonCaps, NumberInputValueCaps, NumberInputDataIndices;
        public ushort NumberOutputButtonCaps, NumberOutputValueCaps, NumberOutputDataIndices;
        public ushort NumberFeatureButtonCaps, NumberFeatureValueCaps, NumberFeatureDataIndices;
    }

    [StructLayout(LayoutKind.Sequential)]
    struct SP_DEVICE_INTERFACE_DATA { public int cbSize; public Guid InterfaceClassGuid; public int Flags; public IntPtr Reserved; }

    [StructLayout(LayoutKind.Sequential)]
    struct SP_DEVICE_INTERFACE_DETAIL_DATA { public int cbSize; public char DevicePath; }

    [DllImport("hid.dll")] static extern bool HidD_GetAttributes(SafeFileHandle h, ref HIDD_ATTRIBUTES a);
    [DllImport("hid.dll")] static extern bool HidD_GetPreparsedData(SafeFileHandle h, out IntPtr pp);
    [DllImport("hid.dll")] static extern bool HidD_FreePreparsedData(IntPtr p);
    [DllImport("hid.dll")] static extern int HidP_GetCaps(IntPtr p, ref HIDP_CAPS caps);
    [DllImport("hid.dll", CharSet = CharSet.Unicode)] static extern bool HidD_GetProductString(SafeFileHandle h, StringBuilder b, int len);

    [DllImport("setupapi.dll", CharSet = CharSet.Unicode)]
    static extern IntPtr SetupDiGetClassDevs(ref Guid g, IntPtr en, IntPtr hwnd, int flags);
    [DllImport("setupapi.dll")]
    static extern bool SetupDiEnumDeviceInterfaces(IntPtr set, IntPtr dev, ref Guid g, int idx, ref SP_DEVICE_INTERFACE_DATA data);
    [DllImport("setupapi.dll", CharSet = CharSet.Unicode)]
    static extern bool SetupDiGetDeviceInterfaceDetail(IntPtr set, ref SP_DEVICE_INTERFACE_DATA data,
        IntPtr detail, int size, out int needed, IntPtr dev);
    [DllImport("setupapi.dll")] static extern bool SetupDiDestroyDeviceInfoList(IntPtr set);

    [DllImport("kernel32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    static extern SafeFileHandle CreateFile(string name, uint access, uint share, IntPtr sec, uint disp, uint flags, IntPtr tpl);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool DeviceIoControl(SafeFileHandle h, uint code, IntPtr inBuf, int inSize, byte[] outBuf, int outSize, out int ret, IntPtr ov);

    public static uint HidCtl(int id) { return (uint)((0x0B << 16) | (id << 2) | 3); }

    public static List<string> Interfaces()
    {
        var list = new List<string>();
        var hidGuid = new Guid("4d1e55b2-f16f-11cf-88cb-001111000030");
        IntPtr set = SetupDiGetClassDevs(ref hidGuid, IntPtr.Zero, IntPtr.Zero, 0x12 /*PRESENT|DEVICEINTERFACE*/);
        if (set == new IntPtr(-1)) { return list; }
        var did = new SP_DEVICE_INTERFACE_DATA();
        did.cbSize = Marshal.SizeOf(did);
        for (int i = 0; SetupDiEnumDeviceInterfaces(set, IntPtr.Zero, ref hidGuid, i, ref did); i++)
        {
            int needed;
            SetupDiGetDeviceInterfaceDetail(set, ref did, IntPtr.Zero, 0, out needed, IntPtr.Zero);
            IntPtr buf = Marshal.AllocHGlobal(needed);
            try
            {
                Marshal.WriteInt32(buf, IntPtr.Size == 8 ? 8 : 6);      // cbSize
                if (SetupDiGetDeviceInterfaceDetail(set, ref did, buf, needed, out needed, IntPtr.Zero))
                {
                    list.Add(Marshal.PtrToStringUni((IntPtr)((long)buf + 4)));
                }
            }
            finally { Marshal.FreeHGlobal(buf); }
        }
        SetupDiDestroyDeviceInfoList(set);
        return list;
    }

    public static string Dump(string path)
    {
        var sb = new StringBuilder();
        var h = CreateFile(path, 0x80000000u | 0x40000000u, 3, IntPtr.Zero, 3, 0, IntPtr.Zero);
        if (h.IsInvalid) { h = CreateFile(path, 0, 3, IntPtr.Zero, 3, 0, IntPtr.Zero); }
        if (h.IsInvalid) { return "  open failed: " + Marshal.GetLastWin32Error() + "\n"; }

        var a = new HIDD_ATTRIBUTES(); a.Size = Marshal.SizeOf(a);
        if (HidD_GetAttributes(h, ref a))
        {
            sb.AppendLine(string.Format("  vid_pid   {0:x4}:{1:x4}  bcd {2:x4}", a.VendorID, a.ProductID, a.VersionNumber));
        }
        var name = new StringBuilder(256);
        if (HidD_GetProductString(h, name, 512)) { sb.AppendLine("  product   " + name.ToString()); }

        IntPtr prep;
        if (HidD_GetPreparsedData(h, out prep))
        {
            var caps = new HIDP_CAPS(); caps.Reserved = new ushort[17];
            if (HidP_GetCaps(prep, ref caps) == 0)
            {
                sb.AppendLine(string.Format("  report    in={0} out={1} feature={2}  usage_page={3:x4} usage={4:x4}",
                    caps.InputReportByteLength, caps.OutputReportByteLength, caps.FeatureReportByteLength,
                    caps.UsagePage, caps.Usage));
                sb.AppendLine(string.Format("  caps      in_buttons={0} in_values={1}",
                    caps.NumberInputButtonCaps, caps.NumberInputValueCaps));
            }
            HidD_FreePreparsedData(prep);
        }

        foreach (int id in new[] { 7, 4, 3, 0 })
        {
            var buf = new byte[4096];
            int got;
            uint code = id >= 4 ? (uint)((0x0B << 16) | ((id == 7 ? 1 : 0) << 2) | 3) : HidCtl(id);
            if (DeviceIoControl(h, code, IntPtr.Zero, 0, buf, buf.Length, out got, IntPtr.Zero) && got > 0)
            {
                sb.AppendLine(string.Format("  descriptor ({0} bytes):", got));
                var hex = new StringBuilder();
                for (int i = 0; i < got; i++)
                {
                    hex.Append(buf[i].ToString("x2"));
                    if ((i & 15) == 15) hex.Append('\n');
                }
                sb.AppendLine("  " + hex.ToString().Replace("\n", "\n  "));
                break;
            }
        }
        h.Close();
        return sb.ToString();
    }
}
'@

Add-Type -TypeDefinition $sig -Language CSharp

foreach ($p in [HidTool]::Interfaces()) {
    if ($Filter -ne '' -and $p -notmatch $Filter) { continue }
    Write-Host "=== $p"
    Write-Host ([HidTool]::Dump($p))
}
