MCU = atmega32u4
BOOTLOADER = caterina
EXTRAFLAGS = -flto -mcall-prologues
BOOTMAGIC_ENABLE = no
MAGIC_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = no
STENO_ENABLE = no

CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = no
LTO_ENABLE = yes

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = no
AUDIO_ENABLE = no
KEY_LOCK_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE   = no
RGB_MATRIX_ENABLE = yes