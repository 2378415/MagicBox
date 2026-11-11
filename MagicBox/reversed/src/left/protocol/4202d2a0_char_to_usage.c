int char_to_usage(byte param_1)

{
  if (param_1 == 0x61) {
    return 4;
  }
  if (param_1 < 0x62) {
    if (param_1 != 0x4e) {
      if (0x4e < param_1) {
        if (param_1 == 0x55) {
          return 0x18;
        }
        if (0x55 < param_1) {
          if (param_1 == 0x58) {
            return 0x1b;
          }
          if (param_1 < 0x59) {
            if (param_1 == 0x56) {
              return 0x19;
            }
            return 0x1a;
          }
          if (param_1 == 0x59) {
            return 0x1c;
          }
          if (param_1 == 0x5a) {
            return 0x1d;
          }
          return 0;
        }
        if (param_1 == 0x52) {
          return 0x15;
        }
        if (0x52 < param_1) {
          if (param_1 == 0x53) {
            return 0x16;
          }
          return 0x17;
        }
        if (param_1 == 0x50) {
          return 0x13;
        }
        if (param_1 == 0x51) {
          return 0x14;
        }
        return 0x12;
      }
      if (param_1 == 0x47) {
        return 10;
      }
      if (param_1 < 0x48) {
        if (param_1 == 0x44) {
          return 7;
        }
        if (0x44 < param_1) {
          if (param_1 == 0x45) {
            return 8;
          }
          return 9;
        }
        if (param_1 == 0x42) {
          return 5;
        }
        if (param_1 == 0x43) {
          return 6;
        }
        return (uint)(param_1 == 0x41) << 2;
      }
      if (param_1 == 0x4b) {
        return 0xe;
      }
      if (0x4b < param_1) {
        if (param_1 == 0x4c) {
          return 0xf;
        }
        return 0x10;
      }
      if (param_1 == 0x49) {
        return 0xc;
      }
      if (param_1 == 0x4a) {
        return 0xd;
      }
      return 0xb;
    }
  }
  else if (param_1 != 0x6e) {
    if (param_1 < 0x6f) {
      if (param_1 == 0x68) {
        return 0xb;
      }
      if (0x68 < param_1) {
        if (param_1 == 0x6b) {
          return 0xe;
        }
        if (param_1 < 0x6c) {
          if (param_1 == 0x69) {
            return 0xc;
          }
          return 0xd;
        }
        if (param_1 == 0x6c) {
          return 0xf;
        }
        return 0x10;
      }
      if (param_1 == 0x65) {
        return 8;
      }
      if (0x65 < param_1) {
        if (param_1 == 0x66) {
          return 9;
        }
        return 10;
      }
      if (param_1 == 99) {
        return 6;
      }
      if (param_1 == 100) {
        return 7;
      }
      return 5;
    }
    if (param_1 == 0x75) {
      return 0x18;
    }
    if (0x75 < param_1) {
      if (param_1 == 0x78) {
        return 0x1b;
      }
      if (param_1 < 0x79) {
        if (param_1 == 0x76) {
          return 0x19;
        }
        return 0x1a;
      }
      if (param_1 == 0x79) {
        return 0x1c;
      }
      if (param_1 == 0x7a) {
        return 0x1d;
      }
      return 0;
    }
    if (param_1 == 0x72) {
      return 0x15;
    }
    if (0x72 < param_1) {
      if (param_1 == 0x73) {
        return 0x16;
      }
      return 0x17;
    }
    if (param_1 == 0x70) {
      return 0x13;
    }
    if (param_1 == 0x71) {
      return 0x14;
    }
    return 0x12;
  }
  return 0x11;
}