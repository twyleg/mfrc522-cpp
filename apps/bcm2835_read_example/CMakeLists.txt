set(TARGET_NAME bcm2835_read_example)

#
# set cmake settings
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#
# add source files to target
#
add_executable(${TARGET_NAME}
	main.cc
	bcm2835.h
	bcm2835_spi_impl.h
	bcm2835_gpio_impl.h
)

#
# link against libs
#
target_link_libraries(${TARGET_NAME}
	bcm2835
	mfrc522
)
