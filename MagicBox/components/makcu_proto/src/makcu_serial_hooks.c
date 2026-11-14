/* Serial hook storage - NULL until makcu_hiddev installs a backend. */
#include "makcu_serial_hooks.h"

makcu_serial_read_fn makcu_serial_read_hook;
