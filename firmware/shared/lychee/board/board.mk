# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/Lychee/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/Lychee

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
