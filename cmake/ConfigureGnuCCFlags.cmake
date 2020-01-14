# Detect C++ optimizations
#
# CPU_OPTIMIZATION_FLAGS  - detected CPU optimizations
# CXX_CUSTOM_FLAGS        - C++ custom flags
# C_CUSTOM_FLAGS          - C custom flags
# COMMON_CUSTOM_FLAGS     - C/C++ common custom flags
#
# CUSTOM_CXX_CFLAGS       - result C++ custom flags
#
# Copyright (c) 2014, Vladislav G. Mikhailikov, <vmikhailikov@gmail.com>

# Check builtins support
FUNCTION (
  CheckCompiler
  Option
  Flag
  Msg)

  CHECK_CXX_COMPILER_FLAG ("${Option}" Result)

  IF (Result)
    MESSAGE(STATUS  "${Msg} supported!")
    SET (${Flag} "${Option}" PARENT_SCOPE)
  ELSE()
    MESSAGE(STATUS  "${Msg} not supported!")
  ENDIF ()

ENDFUNCTION()

# Check builtins support
FUNCTION (
  CheckLinker
  Option
  Flag
  Msg)

  CHECK_CXX_COMPILER_FLAG ("${Option}" Result)

  IF (Result)
    MESSAGE(STATUS  "${Msg} supported!")
    SET (${Flag} "${Option}" PARENT_SCOPE)
  ELSE()
    MESSAGE(STATUS  "${Msg} not supported!")
  ENDIF ()

ENDFUNCTION()

# Detect C++ standards
CHECK_C_COMPILER_FLAG   ("-std=c90"      STD_C_1990_FLAGS       )
CHECK_C_COMPILER_FLAG   ("-std=gnu90"    STD_GNU_C_1990_FLAGS   )
CHECK_C_COMPILER_FLAG   ("-std=c99"      STD_C_1999_FLAGS       )
CHECK_C_COMPILER_FLAG   ("-std=gnu99"    STD_GNU_C_1999_FLAGS   )
CHECK_C_COMPILER_FLAG   ("-std=c11"      STD_C_2011_FLAGS       )
CHECK_C_COMPILER_FLAG   ("-std=gnu11"    STD_GNU_C_2011_FLAGS   )

CHECK_CXX_COMPILER_FLAG ("-std=c++98"    STD_CXX_1998_FLAGS     )
CHECK_CXX_COMPILER_FLAG ("-std=gnu++98"  STD_GNU_CXX_1998_FLAGS )
CHECK_CXX_COMPILER_FLAG ("-std=c++0x"    STD_CXX_200X_FLAGS     )
CHECK_CXX_COMPILER_FLAG ("-std=c++11"    STD_CXX_2011_FLAGS     )
CHECK_CXX_COMPILER_FLAG ("-std=gnu++11"  STD_GNU_CXX_2011_FLAGS )
CHECK_CXX_COMPILER_FLAG ("-std=c++14"    STD_CXX_2014_FLAGS     )
CHECK_CXX_COMPILER_FLAG ("-std=gnu++14"  STD_GNU_CXX_2014_FLAGS )
CHECK_CXX_COMPILER_FLAG ("-std=c++1z"    STD_CXX_201z_FLAGS     )
CHECK_CXX_COMPILER_FLAG ("-std=gnu++1z"  STD_GNU_CXX_201z_FLAGS )

IF (NOT STD_CXX_2011_FLAGS)
  MESSAGE (FATAL "Phoenix project requires C++ 2011 or better!")
ENDIF ()

# Set maximum C++ flag
IF ( STD_CXX_201z_FLAGS )
  SET ( COMMON_CUSTOM_CXX_FLAGS "-std=c++1z" )
ELSEIF ( STD_CXX_2014_FLAGS )
  SET ( COMMON_CUSTOM_CXX_FLAGS "-std=c++14" )
ELSEIF ( STD_CXX_2011_FLAGS )
  SET ( COMMON_CUSTOM_CXX_FLAGS "-std=c++11" )
ENDIF ()

IF ( STD_C_2011_FLAGS )
  SET ( COMMON_CUSTOM_C_FLAGS "-std=c11" )
ELSEIF ( STD_C_1999_FLAGS )
  SET ( COMMON_CUSTOM_C_FLAGS "-std=c99" )
ELSE ()
  SET ( COMMON_CUSTOM_C_FLAGS "-std=c90" )
ENDIF ()

# Set initial custom flags
MESSAGE(STATUS  "Configure GNU compiler ...")
SET(COMMON_CUSTOM_CXX_FLAGS "${COMMON_CUSTOM_CXX_FLAGS} -march=native -mtune=native")
SET(COMMON_CUSTOM_C_FLAGS   "${COMMON_CUSTOM_C_FLAGS} -march=native -mtune=native")

# Detect 32/64 bit architecture
IF (${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64")

  MESSAGE (STATUS  "64-bit system detected ...")
  SET (COMMON_CUSTOM_CXX_FLAGS "${COMMON_CUSTOM_CXX_FLAGS} -m64")
  SET (COMMON_CUSTOM_C_FLAGS   "${COMMON_CUSTOM_C_FLAGS} -m64")

ELSE ()

  MESSAGE (STATUS  "32-bit system detected ...")
  SET (COMMON_CUSTOM_CXX_FLAGS "${COMMON_CUSTOM_CXX_FLAGS} -m32")
  SET (COMMON_CUSTOM_C_FLAGS   "${COMMON_CUSTOM_C_FLAGS} -m32")

ENDIF ()


# Check PIC
CheckCompiler("-fPIC -DPIC"   CXX_PIC_FLAG  "PIC mode")

# Check PIE
CheckCompiler("-pie"          CXX_PIE_FLAG  "PIE mode")

# Check compiler flags
CHECK_CXX_COMPILER_FLAG ("-Wl,--no-undefined"   LINKER_HAS_NO_UNDEFINED         )
IF (LINKER_HAS_NO_UNDEFINED)
  SET ( COMMON_CUSTOM_LD_FLAGS      "-Wl,--no-undefined" )
ENDIF ()

CHECK_CXX_COMPILER_FLAG ("-Wl,--enable-new-dtags" LINKER_HAS_NEW_DTAGS          )
IF (LINKER_HAS_NEW_DTAGS)
  SET ( COMMON_CUSTOM_LD_FLAGS      "${COMMON_CUSTOM_LD_FLAGS} -Wl,--enable-new-dtags" )
ENDIF ()

CHECK_CXX_COMPILER_FLAG ("-Wl,--as-needed"      LINKER_HAS_AS_NEEDED            )
IF (LINKER_HAS_AS_NEEDED)
  SET ( COMMON_CUSTOM_LD_FLAGS      "${COMMON_CUSTOM_LD_FLAGS} -Wl,--as-needed" )
ENDIF ()

CHECK_CXX_COMPILER_FLAG ("-z combreloc"         LINKER_HAS_COMBINED_RELOCATION  )
IF (LINKER_HAS_COMBINED_RELOCATION)
  SET ( COMMON_CUSTOM_LD_FLAGS      "${COMMON_CUSTOM_LD_FLAGS} -z combreloc" )
ENDIF ()

CHECK_CXX_COMPILER_FLAG ("-z noexecstack"       LINKER_HAS_NO_EXEC_STACK        )
IF (LINKER_HAS_NO_EXEC_STACK)
  SET ( COMMON_CUSTOM_LD_FLAGS      "${COMMON_CUSTOM_LD_FLAGS} -z noexecstack" )
ENDIF ()

CHECK_CXX_COMPILER_FLAG ("-pie"                 LINKER_HAS_PIE                  )
IF (LINKER_HAS_PIE)
  SET ( COMMON_CUSTOM_LD_FLAGS      "${COMMON_CUSTOM_LD_FLAGS} -pie" )
ENDIF ()

# End of file
