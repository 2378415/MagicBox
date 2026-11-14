# app_right - MAKCU host side (corresponds to firmware V3.7, app version "7d19c5c-dirty")
cmake_minimum_required(VERSION 3.16)

set(EXTRA_COMPONENT_DIRS "${CMAKE_CURRENT_LIST_DIR}/../components")

# The right chip is the USB *host*: it has no HID device stack, so makcu_hiddev
# (which REQUIRES the managed espressif__tinyusb, installed under app_left/) must
# stay out of this build - otherwise requirement resolution fails here.  Listing
# the components explicitly keeps the two apps independent.
set(COMPONENTS main makcu_link makcu_right makcu_proto makcu_dev makcu_hidhost)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(makcu_right)

