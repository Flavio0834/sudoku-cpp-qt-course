# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appsudoku_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appsudoku_autogen.dir\\ParseCache.txt"
  "appsudoku_autogen"
  )
endif()
