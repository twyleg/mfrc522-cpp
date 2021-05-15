cmake_minimum_required(VERSION 3.1.0)

project(mfrc522_cpp)

# Externals
add_subdirectory(external/spidevpp/libs/)

# Libs
add_subdirectory(libs/)

# Apos
add_subdirectory(apps/spidev_read_example/)
add_subdirectory(apps/bcm2835_read_example/)
