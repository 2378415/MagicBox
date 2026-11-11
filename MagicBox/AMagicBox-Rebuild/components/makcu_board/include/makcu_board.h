/* Board-level helpers (LED, eFuse, coredump, NVS keys) - placeholder surface.
 *
 * The component is registered with an `include` directory, so that directory has
 * to exist and export at least one header.  Nothing is ported yet: the two board
 * functions of the original firmware (LED status, eFuse serial read) come with
 * P5/P6, see docs/30-decisions.md D7 and docs/HANDOVER.md §10.2.
 *
 * Keep this file as the anchor for the future API instead of deleting the
 * directory: component discovery fails with "Include directory ... is not a
 * directory" when it is missing.
 */
#ifndef MAKCU_BOARD_H
#define MAKCU_BOARD_H

/* Nothing is exported yet: src/makcu_board_stub.c only records the six port
 * targets (led_init 0x42012a74, efuse_burn 0x42011188, ...).  The first real
 * function lands here with its header. */

#endif /* MAKCU_BOARD_H */
