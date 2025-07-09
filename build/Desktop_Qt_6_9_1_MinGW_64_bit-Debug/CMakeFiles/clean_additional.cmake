# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\bruteEngine_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\bruteEngine_autogen.dir\\ParseCache.txt"
  "bruteEngine_autogen"
  )
endif()
