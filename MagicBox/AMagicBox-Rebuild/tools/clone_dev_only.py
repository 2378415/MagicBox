p="components/makcu_hiddev/src/usb_descriptors.c"
t=open(p,encoding="utf-8").read()
if "desc_device_runtime" not in t:
    # Device descriptor: copy the proven built-in one and overwrite the identity
    # fields.  Returning a fully synthesised descriptor made TinyUSB fail to
    # enumerate (no device on the bus at all), so the config block stays ours and
    # only VID/PID/bcdDevice come from the clone; the report descriptor is cloned.
    t=t.replace("""uint8_t const *tud_descriptor_device_cb(void)
{
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid) {
        return c->device;                  /* cloned identity (P5) */
    }
    return (uint8_t const *)&desc_device;
}""","""static tusb_desc_device_t desc_device_runtime;

uint8_t const *tud_descriptor_device_cb(void)
{
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid) {
        desc_device_runtime = desc_device;
        desc_device_runtime.idVendor  = (uint16_t)(c->device[8] | (c->device[9] << 8));
        desc_device_runtime.idProduct = (uint16_t)(c->device[10] | (c->device[11] << 8));
        desc_device_runtime.bcdDevice = (uint16_t)(c->device[12] | (c->device[13] << 8));
        return (uint8_t const *)&desc_device_runtime;
    }
    return (uint8_t const *)&desc_device;
}""")
    t=t.replace("""uint8_t const *tud_descriptor_configuration_cb(uint8_t index)
{
    (void)index;
    const makcu_clone_t *c = makcu_clone_get();
    if (c != NULL && c->valid && c->config_len > 0) {
        return c->config;
    }
    return desc_configuration;
}""","""uint8_t const *tud_descriptor_configuration_cb(uint8_t index)
{
    (void)index;
    /* The configuration block stays the built-in (proven) one: a synthesised
     * clone configuration failed to enumerate, see docs D23. */
    return desc_configuration;
}""")
    open(p,"w",encoding="utf-8").write(t)
print("device descriptor now overrides identity only")
