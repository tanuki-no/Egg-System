# Project presets
#
# Configurure the server now as: "cmake <OPTIONS> <FLAGS>  .."
#
# Options:
#
# Flags:
#
# -DCMAKE_CXX_COMPILER= /usr/bin/g++
# -DCMAKE_INSTALL_PREFIX=/opt/phoenix
# -DCMAKE_BUILD_TYPE=debug | -DCMAKE_BUILD_TYPE=release

# Commons
PROJECT("Egg::System" CXX C)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0 FATAL_ERROR)

# Describe project
SET ( PROJECT_VERSION_MAJOR	0					)
SET ( PROJECT_VERSION_MINOR	0					)
SET ( PROJECT_VERSION_PATCH	1					)
SET ( PROJECT_VERSION_TWEAK	2				 	)
SET ( PROJECT_VERSION           ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK} )

STRING( TIMESTAMP TODAY "%d/%m/%Y"							)

SET ( Alias		"Go cat go"							)
SET ( Author		"Vladislav \\\"Tanuki\\\" Mikhailikov"				)
SET ( Copyright		"GNU GPLv3"							)
SET ( Description	"Egg (Linux Daemon SDK) system and compiler configuration"	)
SET ( SDKName		"EggSDK"							)

# Options
OPTION ( BUILD_PKGCONFIG      "Generate pkgconfig configuration files"        ON  )

# Project directories
SET ( Project_Include_Dir     "${CMAKE_SOURCE_DIR}/include" )

# GNU install dirs
INCLUDE ( GNUInstallDirs )

# Configure compiler
INCLUDE ( ${CMAKE_SOURCE_DIR}/cmake/ConfigureCompiler.cmake )

# Includes
ADD_SUBDIRECTORY ( include )

# CMake scripts
CONFIGURE_FILE(
  egg-common.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/egg-common.cmake
  @ONLY )

INSTALL(
  FILES       ${CMAKE_CURRENT_BINARY_DIR}/egg-common.cmake
  DESTINATION ${CMAKE_INSTALL_FULL_DATAROOTDIR}/cmake/${SDKName} )

# Pkg-config configuration
IF (BUILD_PKGCONFIG)

  CONFIGURE_FILE(
    egg-compiler.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/egg-compiler.pc
    @ONLY )

  INSTALL(
    FILES       ${CMAKE_CURRENT_BINARY_DIR}/egg-compiler.pc
    DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}/pkgconfig)

ENDIF ()

# End of file
