cmake_minimum_required(VERSION 3.20.0)
find_package(zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(dht22)

# Add the DHT22 driver source to your application

target_sources(app PRIVATE 
  src/main.c
  # ${CMAKE_CURRENT_SOURCE_DIR}/sensor/dht/src/dht.c
)

# # Include the DHT22 header directory
# target_include_directories(app PRIVATE
#   ${CMAKE_CURRENT_SOURCE_DIR}/sensor/dht/include
# )