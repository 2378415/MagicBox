// 42002200  esp_efuse_read_field_bit  FUN_42002200  size=53
// strings: err == ESP_OK | esp_efuse_api.c | esp_efuse_read_field_bit

bool FUN_42002200(int param_1)

{
  int iVar1;
  char local_30 [48];
  
  local_30[0] = '\0';
  if (param_1 != 0) goto LAB_4200221f;
  do {
    param_1 = (*(code *)PTR_FUN_420000a8)
                        (PTR_s_esp_efuse_api_c_3c030320_0x1b_420000a4,0x38,
                         PTR_s_esp_efuse_read_field_bit_420000a0,PTR_s_err____ESP_OK_4200009c);
LAB_4200221f:
    iVar1 = FUN_42002190(param_1,local_30,1);
  } while (iVar1 != 0);
  return local_30[0] != '\0';
}


