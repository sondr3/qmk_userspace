# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../../features/rules.mk
