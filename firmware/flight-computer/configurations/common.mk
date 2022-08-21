# combine all configuration options into a single variable
# supported options are:
# - ENABLE_LED
# - ENABLE_MPU
# - ENABLE_MPU_ACCEL
# - ENABLE_MPU_GYRO
# - ENABLE_MPU_COMPASS
# - ENABLE_BARO
# - ENABLE_RADIO
# - ENABLE_RADIO_EC
# - ENABLE_GPS
# - ENABLE_BLACKBOX
# - ENABLE_USB
# - ENABLE_USB_READOUT
# - ENABLE_USB_SHELL
# - ENABLE_STATE_ESTIMATION

ifndef BOARD_CONFIG
$(error BOARD_CONFIG not found: please define a board configuration)
endif

include configurations/$(BOARD_CONFIG).mk

CFGDEFS = -DENABLE_GPS=$(ENABLE_GPS)                           \
          -DENABLE_LED=$(ENABLE_LED)                           \
          -DENABLE_MPU=$(ENABLE_MPU)                           \
          -DENABLE_MPU_ACCEL=$(ENABLE_MPU_ACCEL)               \
          -DENABLE_MPU_GYRO=$(ENABLE_MPU_GYRO)                 \
          -DENABLE_MPU_COMPASS=$(ENABLE_MPU_COMPASS)           \
          -DENABLE_BARO=$(ENABLE_BARO)                         \
          -DENABLE_RADIO=$(ENABLE_RADIO)                       \
          -DENABLE_RADIO_EC=$(ENABLE_RADIO_EC)                 \
          -DENABLE_GPS=$(ENABLE_GPS)                           \
          -DENABLE_BLACKBOX=$(ENABLE_BLACKBOX)                 \
          -DENABLE_USB=$(ENABLE_USB)                           \
          -DENABLE_USB_READOUT=$(ENABLE_USB_READOUT)           \
          -DENABLE_USB_SHELL=$(ENABLE_USB_SHELL)               \
          -DENABLE_STATE_ESTIMATION=$(ENABLE_STATE_ESTIMATION) 
			