// strings: bus overflow

undefined4 FUN_4200df3c(char param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_42000b30;
  if (param_1 == '\0') {
    FUN_4200de08(DAT_42000b30,0,param_2);
    *DAT_42000b98 = PTR_DAT_42000bdc;
    *DAT_42000b9c = PTR_DAT_42000be0;
    FUN_4200f12c(uVar1);
    return 0;
  }
  (*DAT_42000634)(PTR_DAT_42000ba0);
  (*DAT_42000634)(PTR_s_bus_overflow_42000bd8);
  (*DAT_42000634)(PTR_DAT_42000ba8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}