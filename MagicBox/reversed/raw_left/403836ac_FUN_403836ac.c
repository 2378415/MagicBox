// 403836ac  FUN_403836ac  FUN_403836ac  size=65
// strings: Octal Flash

undefined4 FUN_403836ac(uint param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 >> 0x10 == 0xc2) {
    if ((param_1 >> 0xc & 0xf) << 0xc == DAT_40374464) {
      *param_2 = 0xc2;
      return 0;
    }
    if (*(int *)PTR_DAT_40374414 != 0) {
      uVar1 = FUN_40381bb0();
      (*DAT_40374438)(PTR_DAT_403753a8,uVar1,PTR_s_Octal_Flash_403753a4);
    }
  }
  return 0x105;
}


