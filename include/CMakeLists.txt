# Define language

CONFIGURE_FILE (
  "${CMAKE_CURRENT_SOURCE_DIR}/egg/compiler/gcc.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/egg/compiler/gcc.h"
  NEWLINE_STYLE UNIX )

# Public headers

# Egg
FILE (
  COPY "${CMAKE_CURRENT_SOURCE_DIR}/egg/common.hpp"
  DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/egg" )

# Egg public includes

SET (
  Public_Include_Compiler

  "${CMAKE_CURRENT_BINARY_DIR}/egg/compiler/gcc.h"

  CACHE INTERNAL "Compiler headers (generated)" )


SET (
  Public_Include

  "${CMAKE_CURRENT_BINARY_DIR}/egg/common.hpp"

  CACHE INTERNAL "Common headers" )


# Install the Egg::Compiler headers
INSTALL(
  FILES       ${Public_Include_Compiler}
  DESTINATION "${CMAKE_INSTALL_FULL_INCLUDEDIR}/egg/compiler" )

INSTALL(
  FILES       ${Public_Include}
  DESTINATION "${CMAKE_INSTALL_FULL_INCLUDEDIR}/egg" )

# End of file
