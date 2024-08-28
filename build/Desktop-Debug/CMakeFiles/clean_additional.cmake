# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\primeFinder_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\primeFinder_autogen.dir\\ParseCache.txt"
  "primeFinder_autogen"
  )
endif()
