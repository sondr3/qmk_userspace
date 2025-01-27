# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = no
SPACE_CADET_ENABLE = no

DEFERRED_EXEC_ENABLE = yes

SM_TAP_DANCE_ENABLE ?= yes
ifeq ($(strip $(SM_TAP_DANCE_ENABLE)), yes)
	OPT_DEFS += -DSM_TAP_DANCE_ENABLE
endif

ACHORDION_ENABLE ?= no
ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	OPT_DEFS += -DACHORDION_ENABLE
	SRC += features/achordion.c
endif
