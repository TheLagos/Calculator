# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\superdupercalc_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\superdupercalc_autogen.dir\\ParseCache.txt"
  "superdupercalc_autogen"
  )
endif()
