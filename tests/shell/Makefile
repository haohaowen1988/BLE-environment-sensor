DEVELHELP=0
include ../Makefile.tests_common

USEMODULE += app_metadata
USEMODULE += shell
USEMODULE += shell_commands
USEMODULE += ps

# Use a terminal that does not introduce extra characters into the stream.
RIOT_TERMINAL ?= socat

DISABLE_MODULE += auto_init

# chronos is missing a getchar implementation
BOARD_BLACKLIST += chronos

BOARD_INSUFFICIENT_MEMORY := arduino-duemilanove \
                             arduino-leonardo \
                             arduino-nano \
                             arduino-uno

TEST_ON_CI_WHITELIST += all

APP_SHELL_FMT ?= NONE

include $(RIOTBASE)/Makefile.include
