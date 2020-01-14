# Detect compiler
IF (NOT CMAKE_CXX_COMPILER_WORKS)

  INCLUDE (CMakeTestCXXCompiler.cmake)

ENDIF ()

IF (NOT CMAKE_C_COMPILER_WORKS)

  INCLUDE (CMakeTestCCompiler.cmake)

ENDIF ()

# Processor
IF (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
  SET (CPU_IS_X86 TRUE)
ELSE ()
  SET (CPU_IS_X86 FALSE)
ENDIF ()

# Select
IF (CMAKE_CXX_COMPILER_WORKS AND CMAKE_C_COMPILER_WORKS)

  INCLUDE (CheckCCompilerFlag)
  INCLUDE (CheckCXXCompilerFlag)

  # Compiler
  IF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

    MESSAGE(FATAL_ERROR  "CLang not supported")

  ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")

    SET ( COMPILER_IS_GCC 1 CACHE INTERNAL "Compiler is GCC")

    # Configure GCC attributes
    INCLUDE (${CMAKE_SOURCE_DIR}/cmake/ConfigureGnuCCAttrinutes.cmake)

    # Configure GCC flags
    INCLUDE (${CMAKE_SOURCE_DIR}/cmake/ConfigureGnuCCFlags.cmake)

  ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")

    # using Intel C++
    MESSAGE(FATAL_ERROR  "Intel C++ not supported")

  ELSEIF ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  
    # using Visual Studio C++
    MESSAGE(FATAL_ERROR  "Visual Studio C++ not supported")

  ELSE ()

    MESSAGE(FATAL_ERROR  "Compiler not supported")

  ENDIF ()

ENDIF ()

# End of file
