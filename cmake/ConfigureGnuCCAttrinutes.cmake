# Detect GCC attributes
MACRO (CheckAttribute _ATTRIBUTE _RESULT)

  CHECK_CXX_SOURCE_COMPILES (
    " int somefunc() __attribute__((${_ATTRIBUTE}));
      int main() {}" ${_RESULT} )

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "${_ATTRIBUTE} not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributeAlias _RESULT)

  CHECK_CXX_SOURCE_COMPILES (
    " extern \"C\" void __f () { /* Do something. */; }
      void f () __attribute__ ((weak, alias (\"__f\")));
      int main() {} " ${_RESULT} )

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "${_ATTRIBUTE} not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributeFormatArg _RESULT)

  CHECK_CXX_SOURCE_COMPILES(
    "extern char *
     my_dgettext (char *my_domain, const char *my_format)
     __attribute__ ((format_arg (2)));
     int main() {}" ${_RESULT})

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "format_arg(X) not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributePointer _ATTRIBUTE _RESULT)

  CHECK_CXX_SOURCE_COMPILES (
    " void* somefunc() __attribute__((${_ATTRIBUTE}));
      int main() {}" ${_RESULT} )

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "${_ATTRIBUTE} not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributeCleanUp _RESULT)

  CHECK_C_SOURCE_COMPILES(
    "#include <stdlib.h>
     #include <stdio.h>

     #define autofree __attribute((cleanup(__autofree)))

     void __autofree(void *p)
     {
        void **_p = (void**)p;
        free(*_p);
     }

    void *myalloc(size_t sz)
    {
        void *ptr;
        if ((ptr = malloc(sz)) == NULL) {  exit(1); }
        return ptr;
    }

    int main(int argc, char **argv)
    {
        autofree char *x = myalloc(32);

        {
          autofree int *y = myalloc(64);
        }

        return 0;
    }" ${_RESULT})

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "cleanup(X) not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributeNonString _RESULT)

  CHECK_C_SOURCE_COMPILES(
    "struct Data
    {
      char name [32] __attribute__ ((nonstring));
    };

    int main() {}" ${_RESULT})

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "cleanup(X) not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributePrintf _RESULT)

  CHECK_CXX_SOURCE_COMPILES(

"#include <cstdlib>
 int somefunc(
 int severity,
 const char* file,
 int line,
 const char* format, ...)
 __attribute__((__format__ (__printf__, 4, 5)));
 int main() {}" ${_RESULT})

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "${_ATTRIBUTE} not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributeSection _RESULT)

  CHECK_C_SOURCE_COMPILES(

"int variable __attribute__((section(\"foo\"))) = 10;
 int main() {}" ${_RESULT})

IF(NOT ${_RESULT})
  MESSAGE(STATUS  "Attribute \"section\" not supported!")
ENDIF()

ENDMACRO()

MACRO (CheckAttributeTlsModel _RESULT)

  CHECK_C_SOURCE_COMPILES(

"__thread int i __attribute__((tls_model(\"local-exec\")));
 int main() { return 0; }" ${_RESULT})

IF(NOT ${_RESULT})
  MESSAGE(STATUS  "Attribute \"section\" not supported!")
ENDIF()

ENDMACRO()

MACRO (CheckAttributeFallthrough _RESULT)

  CHECK_C_SOURCE_COMPILES(

"__thread int i __attribute__((tls_model(\"local-exec\")));
 int main() { return 0; }" ${_RESULT})

IF(NOT ${_RESULT})
  MESSAGE(STATUS  "Attribute \"section\" not supported!")
ENDIF()

ENDMACRO()

MACRO (CheckAttributeDesignedInit _RESULT)

  CHECK_CXX_SOURCE_COMPILES (
    " struct S {
        int a;
        union { int b; int c; };
    } __attribute__((designated_init));
      int main() {}" ${_RESULT} )

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "Attribute \"designated_init\" not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributeMayAlias _RESULT)

  CHECK_CXX_SOURCE_COMPILES (
    "typedef short __attribute__((__may_alias__)) short_a;
     int main() {}" ${_RESULT} )

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "Attribute \"may_alias\" not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributeScalarStorageOrder _RESULT)

  CHECK_CXX_SOURCE_COMPILES (
    "struct __attribute__((packed, scalar_storage_order(\"big-endian\")))
     mystruct { unsigned char a; unsigned short b; unsigned int c; };
     int main() {}" ${_RESULT} )

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "Attribute \"scalar_storage_order\" not supported!")
  ENDIF()

ENDMACRO()

MACRO (CheckAttributeTransparentUnion _RESULT)

  CHECK_CXX_SOURCE_COMPILES (
    "typedef union __attribute__ ((__transparent_union__))
     {
        int *__ip;
        union wait *__up;
     }  wait_status_ptr_t;

     int main() {}" ${_RESULT} )

  IF(NOT ${_RESULT})
    MESSAGE(STATUS  "Attribute \"transparent_union\" not supported!")
  ENDIF()

ENDMACRO()

# ---------------------------------------------------------------------------------------
# Check
# ---------------------------------------------------------------------------------------
IF (COMPILER_IS_GCC)

  # Common attributes
  CheckAttribute ("aligned(16)"               GCC_HAS_ATTR_ALIGNED)
  CheckAttribute ("cold"                      GCC_HAS_ATTR_COLD)
  CheckAttribute ("deprecated"                GCC_HAS_ATTR_DEPRECATED)
  CheckAttribute ("hot"                       GCC_HAS_ATTR_HOT)
  CheckAttribute ("packed"                    GCC_HAS_ATTR_PACKED)
  CheckAttribute ("unused"                    GCC_HAS_ATTR_UNUSED)
  CheckAttribute ("used"                      GCC_HAS_ATTR_USED)
  CheckAttribute ("visibility(\"hidden\")"    GCC_HAS_ATTR_VISIBILITY)
  CheckAttribute ("weak"                      GCC_HAS_ATTR_WEAK)
  CheckAttribute ("warn_if_not_aligned(16)"   GCC_HAS_ATTR_WARN_IF_NOT_ALIGNED)

  # Function attributes
  CheckAttributeAlias (                       GCC_FUNCTION_HAS_ATTR_ALIAS)
  CheckAttribute ("alloc_align(1)"            GCC_FUNCTION_HAS_ATTR_ALLOC_ALIGNED)
  CheckAttribute ("alloc_size(4)"             GCC_FUNCTION_HAS_ATTR_ALLOC_SIZE)
  CheckAttribute ("always_inline"             GCC_FUNCTION_HAS_ATTR_ALWAYS_INLINE)
  CheckAttribute ("artificial"                GCC_FUNCTION_HAS_ATTR_ARTIFICIAL)
  CheckAttribute ("assume_aligned(16)"        GCC_FUNCTION_HAS_ATTR_ASSUME_ALIGNED)
  CheckAttribute ("bnd_instrument"            GCC_FUNCTION_HAS_ATTR_BOUND_INSTRUMENT)
  CheckAttribute ("bnd_legacy"                GCC_FUNCTION_HAS_ATTR_BOUND_LEGACY)
  CheckAttribute ("const"                     GCC_FUNCTION_HAS_ATTR_CONST)
  CheckAttribute ("constructor(1)"            GCC_FUNCTION_HAS_ATTR_CONSTRUCTOR)
  CheckAttribute ("destructor(1)"             GCC_FUNCTION_HAS_ATTR_DESTRUCTOR)
  CheckAttribute ("error (\"message\")"       GCC_FUNCTION_HAS_ATTR_ERROR)
  CheckAttribute ("warning (\"message\")"     GCC_FUNCTION_HAS_ATTR_WARNING)
  CheckAttribute ("externally_visible"        GCC_FUNCTION_HAS_ATTR_EXTERNALY_VISIBLE)
  CheckAttributePrintf (GCC_FUNCTION_HAS_ATTR_FORMAT)
  CheckAttributeFormatArg (GCC_FUNCTION_HAS_ATTR_FORMAT_ARG)
  CheckAttribute ("gnu_inline"                GCC_FUNCTION_HAS_ATTR_GNU_INLINE)
  CheckAttribute ("interrupt"                 GCC_FUNCTION_HAS_ATTR_INTERRUPT)
  CheckAttribute ("leaf"                      GCC_FUNCTION_HAS_ATTR_LEAF)
  CheckAttribute ("malloc"                    GCC_FUNCTION_HAS_ATTR_MALLOC)
  CheckAttribute ("no_icf"                    GCC_FUNCTION_HAS_ATTR_NO_ICF)
  CheckAttribute ("no_instrument_function"    GCC_FUNCTION_HAS_ATTR_NO_INSTRUMENT_FUNC)
  CheckAttribute ("no_profile_instrument_function"  GCC_FUNCTION_HAS_ATTR_NO_PROFILE_INSTRUMENT_FUNC)
  CheckAttribute ("no_reorder"                GCC_FUNCTION_HAS_ATTR_NO_REORDER)
  CheckAttribute ("no_sanitize_address"       GCC_FUNCTION_HAS_ATTR_NO_SANITIZE_ADDR)
  CheckAttribute ("no_sanitize_thread"        GCC_FUNCTION_HAS_ATTR_NO_SANITIZE_THREAD)
  CheckAttribute ("no_sanitize_undefined"     GCC_FUNCTION_HAS_ATTR_NO_SANITIZE_UNDEF)
  CheckAttribute ("no_split_stack"            GCC_FUNCTION_HAS_ATTR_NO_SPLIT_STACK)
  CheckAttribute ("no_stack_limit"            GCC_FUNCTION_HAS_ATTR_NO_STACK_LIMIT)
  CheckAttribute ("noclone"                   GCC_FUNCTION_HAS_ATTR_NO_CLONE)
  CheckAttribute ("noinline"                  GCC_FUNCTION_HAS_ATTR_NO_INLINE)
  CheckAttribute ("noipa"                     GCC_FUNCTION_HAS_ATTR_NO_IPA)
  CheckAttribute ("nonnull"                   GCC_FUNCTION_HAS_ATTR_NON_NULL)
  CheckAttribute ("noplt"                     GCC_FUNCTION_HAS_ATTR_NO_PLT)
  CheckAttribute ("noreturn"                  GCC_FUNCTION_HAS_ATTR_NO_RETURN)
  CheckAttribute ("nothrow"                   GCC_FUNCTION_HAS_ATTR_NO_THROW)
  CheckAttribute ("pure"                      GCC_FUNCTION_HAS_ATTR_PURE)
  CheckAttributePointer ("returns_nonnull"    GCC_FUNCTION_HAS_ATTR_RETURNS_NON_NULL)
  CheckAttribute ("returns_twice"             GCC_FUNCTION_HAS_ATTR_RETURNS_TWICE)
  CheckAttribute ("section (\"bar\")"         GCC_FUNCTION_HAS_ATTR_SECTION)
  CheckAttribute ("sentinel"                  GCC_FUNCTION_HAS_ATTR_SENTINEL)
  CheckAttribute ("simd"                      GCC_FUNCTION_HAS_ATTR_SIMD)
  CheckAttribute ("stack_protect"             GCC_FUNCTION_HAS_ATTR_STACK_PROTECT)
  CheckAttribute ("target(\"default\")"       GCC_FUNCTION_HAS_ATTR_TARGET)
  CheckAttribute ("target_clones(\"sse3\")"   GCC_FUNCTION_HAS_ATTR_TARGET_CLONES)
  CheckAttribute ("warn_unused_result"        GCC_FUNCTION_HAS_ATTR_WARN_UNUSED_RESULT)
  CheckAttribute ("weakref"                   GCC_FUNCTION_HAS_ATTR_WEAK_REF)

  IF (CPU_IS_X86)

    MESSAGE (STATUS  "--------------------------------------------------------------------------------------")
    MESSAGE (STATUS  "X86 architecture detected")
    MESSAGE (STATUS  "--------------------------------------------------------------------------------------")

    CheckAttribute ("cdecl"                   GCC_FUNCTION_HAS_X86_ATTR_CDECL)
    CheckAttribute ("fastcall"                GCC_FUNCTION_HAS_X86_ATTR_FASTCALL)
    CheckAttribute ("thiscall"                GCC_FUNCTION_HAS_X86_ATTR_THISCALL)
    CheckAttribute ("ms_abi"                  GCC_FUNCTION_HAS_X86_ATTR_ABI)
    CheckAttribute ("callee_pop_aggregate_return(1)"  GCC_FUNCTION_HAS_X86_ATTR_CALLEE_POP_AGGREGATE_RETURN)
    CheckAttribute ("ms_hook_prologue"        GCC_FUNCTION_HAS_X86_ATTR_MS_HOOK_PROLOGUE)
    CheckAttribute ("naked"                   GCC_FUNCTION_HAS_X86_ATTR_NAKED)
    CheckAttribute ("regparm(3)"              GCC_FUNCTION_HAS_X86_ATTR_REGPARM)
    CheckAttribute ("sseregparm"              GCC_FUNCTION_HAS_X86_ATTR_SSE_REGPARM)
    CheckAttribute ("force_align_arg_pointer" GCC_FUNCTION_HAS_X86_ATTR_FORCE_ALIGN_ARG_POINTER)
    CheckAttribute ("stdcall"                 GCC_FUNCTION_HAS_X86_ATTR_STD_CALL)
    CheckAttribute ("no_caller_saved_registers" GCC_FUNCTION_HAS_X86_ATTR_NO_CALLER_SAVED_REGISTERS)
    CheckAttribute ("interrupt"               GCC_FUNCTION_HAS_X86_ATTR_INTERRUPT)
    CheckAttribute ("target ( \"abm\" )"      GCC_HAS_ATTR_X86_TGT_ABM)
    CheckAttribute ("target ( \"aes\" )"      GCC_HAS_ATTR_X86_TGT_AES)
    CheckAttribute ("target ( \"default\" )"  GCC_HAS_ATTR_X86_TGT_DEFAULT)
    CheckAttribute ("target ( \"mmx\" )"      GCC_HAS_ATTR_X86_TGT_MMX)
    CheckAttribute ("target ( \"pclmul\" )"   GCC_HAS_ATTR_X86_TGT_PCLMUL)
    CheckAttribute ("target ( \"popcnt\" )"   GCC_HAS_ATTR_X86_TGT_POP_CNT)
    CheckAttribute ("target ( \"sse\" )"      GCC_HAS_ATTR_X86_TGT_SSE)
    CheckAttribute ("target ( \"sse2\" )"     GCC_HAS_ATTR_X86_TGT_SSE2)
    CheckAttribute ("target ( \"sse3\" )"     GCC_HAS_ATTR_X86_TGT_SSE3)
    CheckAttribute ("target ( \"sse4\" )"     GCC_HAS_ATTR_X86_TGT_SSE4)
    CheckAttribute ("target ( \"sse4.1\" )"   GCC_HAS_ATTR_X86_TGT_SSE4_1)
    CheckAttribute ("target ( \"sse4.2\" )"   GCC_HAS_ATTR_X86_TGT_SSE4_2)
    CheckAttribute ("target ( \"sse4a\" )"    GCC_HAS_ATTR_X86_TGT_SSE4_a)
    CheckAttribute ("target ( \"fma4\" )"     GCC_HAS_ATTR_X86_TGT_FMA_4)
    CheckAttribute ("target ( \"xop\" )"      GCC_HAS_ATTR_X86_TGT_XOP)
    CheckAttribute ("target ( \"lwp\" )"      GCC_HAS_ATTR_X86_TGT_LWP)
    CheckAttribute ("target ( \"ssse3\" )"    GCC_HAS_ATTR_X86_TGT_SSSE3)
    CheckAttribute ("target ( \"cld\" )"      GCC_HAS_ATTR_X86_TGT_CLD)
    CheckAttribute ("target ( \"fancy-math-387\" )"               GCC_HAS_ATTR_X86_TGT_FANCY_MATH_387)
    CheckAttribute ("target ( \"ieee-fp\" )"  GCC_HAS_ATTR_X86_TGT_IEEE_FP)
    CheckAttribute ("target ( \"inline-all-stringops\" )"         GCC_HAS_ATTR_X86_TGT_INLINE_ALL_STRINGOPS)
    CheckAttribute ("target ( \"inline-stringops-dynamically\" )" GCC_HAS_ATTR_X86_TGT_INLINE_STRINGOPS_DYNAMICALLY)
    CheckAttribute ("target ( \"align-stringops\" )"              GCC_HAS_ATTR_X86_TGT_ALIGN_STRINGOPS)
    CheckAttribute ("target ( \"recip\" )"    GCC_HAS_ATTR_X86_TGT_RECIP)
  ENDIF ()

  # Variable attributes
  MESSAGE (STATUS  "--------------------------------------------------------------------------------------")
  MESSAGE (STATUS  "Detecting GCC variable attributes")
  MESSAGE (STATUS  "--------------------------------------------------------------------------------------")
  CheckAttributeCleanUp (                     GCC_VARIABLE_HAS_ATTR_CLEAN_UP)
  CheckAttribute ("common"                    GCC_VARIABLE_HAS_ATTR_COMMON)
  CheckAttributeNonString (                   GCC_VARIABLE_HAS_ATTR_NO_STRING)
  CheckAttributeSection (                     GCC_VARIABLE_HAS_ATTR_SECTION)
  CheckAttributeTlsModel (                    GCC_VARIABLE_HAS_ATTR_TLS_MODEL)
  CheckAttribute ("vector_size(8)"            GCC_VARIABLE_HAS_ATTR_VECTOR_SIZE)

  # Statement attributes
  MESSAGE (STATUS  "--------------------------------------------------------------------------------------")
  MESSAGE (STATUS  "Detecting GCC statement attributes")
  MESSAGE (STATUS  "--------------------------------------------------------------------------------------")
  CheckAttribute ("fallthrough"               GCC_STATEMENT_HAS_ATTR_FALLTHROUGH)

  # Type attributes
  MESSAGE (STATUS  "--------------------------------------------------------------------------------------")
  MESSAGE (STATUS  "Detecting GCC type attributes")
  MESSAGE (STATUS  "--------------------------------------------------------------------------------------")
  CheckAttribute ("bnd_variable_size"         GCC_TYPE_HAS_ATTR_BOUND_VAR_SIZE)
  CheckAttributeDesignedInit (                GCC_TYPE_HAS_ATTR_DESIGNATED_INIT)
  CheckAttributeMayAlias (                    GCC_TYPE_HAS_ATTR_MAY_ALIAS)
  CheckAttributeScalarStorageOrder (          GCC_TYPE_HAS_ATTR_SCALAR_STORAGE_ORDER)
  CheckAttributeTransparentUnion (            GCC_TYPE_HAS_ATTR_TRANSPARENT_UNION)

ELSE ()

  MESSAGE(FATAL_ERROR  "GCC compiler not found!")

ENDIF ()

# End of file
