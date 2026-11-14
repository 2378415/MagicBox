# app_left - MAKCU device side (corresponds to firmware V3.2, app version "1")
cmake_minimum_required(VERSION 3.16)

set(EXTRA_COMPONENT_DIRS "${CMAKE_CURRENT_LIST_DIR}/../components"
                         "${CMAKE_CURRENT_LIST_DIR}/../mouse")

# Test-only harness: exposes "mx.<hex opcode> <args>" so the hidden opcodes can
# be exercised from the control port.  OFF for any shipped build.
option(MB_DEBUG_OPCODE "enable the mx.<opcode> test harness" OFF)

# USB HID device (OTG).  Shares D+/D- with USB-Serial-JTAG on the ESP32-S3, so
# enabling it forces the control console onto UART0.
option(MB_HID_DEVICE "enumerate as a USB HID mouse" ON)

# Bench only: load clone fixture N (1 = 046D:C077, 2 = 046D:C52F) at boot so the
# first enumeration already uses the cloned identity.
set(MB_CLONE_FIXTURE "" CACHE STRING "clone fixture loaded at boot (1 or 2)")

# Bench only: TinyUSB debug level (1 = warnings, 2 = everything).
set(MB_TUSB_DEBUG "" CACHE STRING "CFG_TUSB_DEBUG level")

# Bench/experiment: serve the cloned device's *full* composite configuration
# (mouse + keyboard/vendor interface) with CFG_TUD_HID=2.  Off by default: the
# single-interface build is the verified one (see D38).
option(MB_DUAL_IF "serve the cloned composite configuration (2 HID interfaces)" OFF)

# Vendor channel (HECATE / G3M PRO).  Unset = staged R1 behaviour: the vendor
# module owns the protocol but frames still travel on the legacy 0xA5 path.
# Defined = R2: dedicated 0xB0/0xB1/0xB2 link frames (requires the matching
# right-chip firmware).  See mouse/README.md.
option(MB_VENDOR_CHANNEL "use the dedicated 0xB0/0xB1/0xB2 vendor channel" OFF)

# Bench: force the cloned identity (e.g. 320f706e) instead of whatever VID/PID the
# device reports.  Needed because the mouse behind the box reports varying ids in
# some modes, and the host's INF matches on VID/PID.
# DEPRECATED (2026-11-10): the identity alias policy in makcu_clone now maps the
# receiver id families onto the INF-backed vendor id automatically, so forcing the
# vid/pid is no longer needed.  Kept only for emergencies; leave it empty.
set(MB_FORCE_VIDPID "" CACHE STRING "DEPRECATED - use the alias policy instead")

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(makcu_left)

