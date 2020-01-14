/*!
 *	\file		egg/common.hpp
 *	\brief		Egg (Linux SDK) common declarations and attributes
 *	\author		Vladislav "Tanuki" Mikhailikov \<vmikhailikov\@gmail.com\>
 *	\copyright	GNU GPL v3
 *	\date		19/09/2017
 *	\version	1.0
 */

#pragma once

#include <egg/compiler/gcc.h>

#ifndef EGG_COMMON
#define EGG_COMMON

/* ------------------------------------------------------------
 * COMMON ATTRIBUTES
 * ------------------------------------------------------------ */
#ifdef GCC_HAS_ATTR_ALIGNED
#define EGG_ATTR_ALIGNED(X)				__attribute__ ((aligned (X)))
#else
#define EGG_ATTR_ALIGNED(X)
#endif

#ifdef GCC_HAS_ATTR_COLD
#define EGG_ATTR_COLD					__attribute__ ((cold))
#else
#define EGG_ATTR_COLD
#endif

#ifdef GCC_HAS_ATTR_DEPRECATED
#define EGG_ATTR_DEPRECATED(MSG)			__attribute__ ((deprecated(MSG)))
#else
#define EGG_ATTR_DEPRECATED(MSG)
#endif

#ifdef GCC_HAS_ATTR_HOT
#define EGG_ATTR_HOT					__attribute__ ((hot))
#else
#define EGG_ATTR_HOT
#endif

#ifdef GCC_HAS_ATTR_PACKED
#define EGG_ATTR_PACKED					__attribute__ ((packed))
#else
#define EGG_ATTR_PACKED
#endif

#ifdef GCC_HAS_ATTR_UNUSED
#define EGG_ATTR_UNUSED					__attribute__ ((unused))
#else
#define EGG_ATTR_UNUSED
#endif

#ifdef GCC_HAS_ATTR_USED
#define EGG_ATTR_USED					__attribute__ ((used))
#else
#define EGG_ATTR_USED
#endif

#ifdef GCC_HAS_ATTR_VISIBILITY
#define EGG_ATTR_VISIBILITY(X)				__attribute__((visibility(X)))
#define EGG_PUBLIC					EGG_ATTR_VISIBILITY("default")
#define EGG_INTERNAL					EGG_ATTR_VISIBILITY("internal")
#define EGG_PRIVATE					EGG_ATTR_VISIBILITY("hidden")
#define EGG_PROTECTED					EGG_ATTR_VISIBILITY("protected")
#else
#define EGG_ATTR_VISIBILITY(X)
#define EGG_PUBLIC					extern
#define EGG_INTERNAL
#define EGG_PRIVATE
#define EGG_PROTECTED
#endif

#ifdef GCC_HAS_ATTR_WEAK
#define EGG_ATTR_WEAK					__attribute__ ((weak))
#else
#define EGG_ATTR_WEAK
#endif

#ifdef GCC_HAS_ATTR_WARN_IF_NOT_ALIGNED
#define EGG_ATTR_WARN_IF_NOT_ALIGNED(X)			__attribute__ ((warn_if_not_aligned (X)))
#else
#define EGG_ATTR_WARN_IF_NOT_ALIGNED(X)
#endif

/* ------------------------------------------------------------
 * FUNCTION ATTRIBUTES
 * ------------------------------------------------------------ */

#ifdef GCC_FUNCTION_HAS_ATTR_ALIAS
#define EGG_FUNC_ATTR_ALIAS(X)				__attribute__ ((alias ("X")))
#else
#define EGG_FUNC_ATTR_ALIAS(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_ALLOC_ALIGNED
#define EGG_FUNC_ATTR_ALLOC_ALIGNED(X)			__attribute__ ((alloc_align (X)))
#else
#define EGG_FUNC_ATTR_ALLOC_ALIGNED(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_ALLOC_SIZE
#define EGG_FUNC_ATTR_ALLOC_SIZE(X)			__attribute__ ((alloc_size (X)))
#else
#define EGG_FUNC_ATTR_ALLOC_SIZE(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_ALWAYS_INLINE
#define EGG_FUNC_ATTR_ALWAYS_INLINE			__attribute__ ((always_inline))
#else
#define EGG_FUNC_ATTR_ALWAYS_INLINE
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_ARTIFICIAL
#define EGG_FUNC_ATTR_ARTIFICIAL			__attribute__ ((artificial))
#else
#define EGG_FUNC_ATTR_ARTIFICIAL
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_ASSUME_ALIGNED
#define EGG_FUNC_ATTR_ASSUME_ALIGNED1(X)		__attribute__ ((assume_aligned(X)))
#define EGG_FUNC_ATTR_ASSUME_ALIGNED2(X,Y)		__attribute__ ((assume_aligned(X, Y)))
#else
#define EGG_FUNC_ATTR_ASSUME_ALIGNED1(X)
#define EGG_FUNC_ATTR_ASSUME_ALIGNED2(X, Y)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_BOUND_INSTRUMENT
#define EGG_FUNC_ATTR_BOUND_INSTRUMENT			__attribute__ ((bnd_instrument))
#else
#define EGG_FUNC_ATTR_BOUND_INSTRUMENT
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_BOUND_LEGACY
#define EGG_FUNC_ATTR_BOUND_LEGACY			__attribute__ ((bnd_legacy))
#else
#define EGG_FUNC_ATTR_BOUND_LEGACY
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_CONST
#define EGG_FUNC_ATTR_CONST				__attribute__ ((const))
#else
#define EGG_FUNC_ATTR_CONST
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_CONSTRUCTOR
#define EGG_FUNC_ATTR_CONSTRUCTOR0			__attribute__ ((constructor))
#define EGG_FUNC_ATTR_CONSTRUCTOR(X)			__attribute__ ((constructor(X)))
#else
#define EGG_FUNC_ATTR_CONSTRUCTOR0
#define EGG_FUNC_ATTR_CONSTRUCTOR(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_DESTRUCTOR
#define EGG_FUNC_ATTR_DESTRUCTOR0			__attribute__ ((destructor))
#define EGG_FUNC_ATTR_DESTRUCTOR(X)			__attribute__ ((destructor(X)))
#else
#define EGG_FUNC_ATTR_DESTRUCTOR0
#define EGG_FUNC_ATTR_DESTRUCTOR(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_ERROR
#define EGG_FUNC_ATTR_ERROR(X)				__attribute__ ((error(X)))
#else
#define EGG_FUNC_ATTR_ERROR(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_WARNING
#define EGG_FUNC_ATTR_WARNING(X)			__attribute__ ((warning(X)))
#else
#define EGG_FUNC_ATTR_WARNING(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_EXTERNALY_VISIBLE
#define EGG_FUNC_ATTR_EXTERNALY_VISIBLE			__attribute__ ((externally_visible))
#else
#define EGG_FUNC_ATTR_EXTERNALY_VISIBLE
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_FLATTEN
#define EGG_FUNC_ATTR_FLATTEN				__attribute__ ((flatten))
#else
#define EGG_FUNC_ATTR_FLATTEN
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_FORMAT
#define EGG_FUNC_ATTR_FORMAT(X,Y,Z)			__attribute__ ((format(X,Y,Z)))
#else
#define EGG_FUNC_ATTR_FORMAT(X,Y,Z)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_FORMAT_ARG
#define EGG_FUNC_ATTR_FORMAT_ARG(X)			__attribute__ ((format_arg(X)))
#else
#define EGG_FUNC_ATTR_FORMAT_ARG(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_GNU_INLINE
#define EGG_FUNC_ATTR_GNU_INLINE			__attribute__ ((gnu_inline))
#else
#define EGG_FUNC_ATTR_GNU_INLINE
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_INTERRUPT
#define EGG_FUNC_ATTR_INTERRUPT				__attribute__ ((interrupt))
#else
#define EGG_FUNC_ATTR_INTERRUPT
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_LEAF
#define EGG_FUNC_ATTR_LEAF				__attribute__ ((leaf))
#else
#define EGG_FUNC_ATTR_LEAF
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_MALLOC
#define EGG_FUNC_ATTR_MALLOC				__attribute__ ((malloc))
#else
#define EGG_FUNC_ATTR_MALLOC
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_ICF
#define EGG_FUNC_ATTR_NO_ICF				__attribute__ ((no_icf))
#else
#define EGG_FUNC_ATTR_NO_ICF
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_INSTRUMENT_FUNC
#define EGG_FUNC_ATTR_NO_INSTRUMENT_FUNC		__attribute__ ((no_instrument_function))
#else
#define EGG_FUNC_ATTR_NO_INSTRUMENT_FUNC
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_PROFILE_INSTRUMENT_FUNC
#define EGG_FUNC_ATTR_NO_PROFILE_INSTRUMENT_FUNC	__attribute__ ((no_profile_instrument_function))
#else
#define EGG_FUNC_ATTR_NO_PROFILE_INSTRUMENT_FUNC
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_REORDER
#define EGG_FUNC_ATTR_NO_REORDER			__attribute__ ((no_reorder))
#else
#define EGG_FUNC_ATTR_NO_REORDER
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_SANITIZE_ADDR
#define EGG_FUNC_ATTR_NO_SANITIZE_ADDR			__attribute__ ((no_sanitize_address))
#else
#define EGG_FUNC_ATTR_NO_SANITIZE_ADDR
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_SANITIZE_THREAD
#define EGG_FUNC_ATTR_NO_SANITIZE_THREAD		__attribute__ ((no_sanitize_thread))
#else
#define EGG_FUNC_ATTR_NO_SANITIZE_THREAD
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_SANITIZE_UNDEF
#define EGG_FUNC_ATTR_NO_SANITIZE_UNDEF			__attribute__ ((no_sanitize_undefined))
#else
#define EGG_FUNC_ATTR_NO_SANITIZE_UNDEF
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_SPLIT_STACK
#define EGG_FUNC_ATTR_NO_SPLIT_STACK			__attribute__ ((no_split_stack))
#else
#define EGG_FUNC_ATTR_NO_SPLIT_STACK
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_STACK_LIMIT
#define EGG_FUNC_ATTR_NO_STACK_LIMIT			__attribute__ ((no_stack_limit))
#else
#define EGG_FUNC_ATTR_NO_STACK_LIMIT
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_CLONE
#define EGG_FUNC_ATTR_NO_CLONE				__attribute__ ((noclone))
#else
#define EGG_FUNC_ATTR_NO_CLONE
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_INLINE
#define EGG_FUNC_ATTR_NO_INLINE				__attribute__ ((noinline))
#else
#define EGG_FUNC_ATTR_NO_INLINE
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_IPA
#define EGG_FUNC_ATTR_NO_IPA				__attribute__ ((noipa))
#else
#define EGG_FUNC_ATTR_NO_IPA
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NON_NULL
#define EGG_FUNC_ATTR_NON_NULL				__attribute__ ((nonnull))
#else
#define EGG_FUNC_ATTR_NON_NULL
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_PLT
#define EGG_FUNC_ATTR_NO_PLT				__attribute__ ((noplt))
#else
#define EGG_FUNC_ATTR_NO_PLT
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_RETURN
#define EGG_FUNC_ATTR_NO_RETURN				__attribute__ ((noreturn))
#else
#define EGG_FUNC_ATTR_NO_RETURN
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_NO_THROW
#define EGG_FUNC_ATTR_NO_THROW				__attribute__ ((nothrow))
#else
#define EGG_FUNC_ATTR_NO_THROW
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_PURE
#define EGG_FUNC_ATTR_PURE				__attribute__ ((pure))
#else
#define EGG_FUNC_ATTR_PURE
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_RETURNS_NON_NULL
#define EGG_FUNC_ATTR_RETURNS_NON_NULL			__attribute__ ((returns_nonnull))
#else
#define EGG_FUNC_ATTR_RETURNS_NON_NULL
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_RETURNS_TWICE
#define EGG_FUNC_ATTR_RETURNS_TWICE			__attribute__ ((returns_twice))
#else
#define EGG_FUNC_ATTR_RETURNS_TWICE
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_SECTION
#define EGG_FUNC_ATTR_SECTION(X)			__attribute__ ((section(X)))
#else
#define EGG_FUNC_ATTR_SECTION(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_SENTINEL
#define EGG_FUNC_ATTR_SENTINEL0				__attribute__ ((sentinel))
#define EGG_FUNC_ATTR_SENTINEL(X)			__attribute__ ((sentinel(X)))
#else
#define EGG_FUNC_ATTR_SENTINEL0
#define EGG_FUNC_ATTR_SENTINEL(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_SIMD
#define EGG_FUNC_ATTR_SIMD				__attribute__ ((simd))
#else
#define EGG_FUNC_ATTR_SIMD
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_STACK_PROTECT
#define EGG_FUNC_ATTR_STACK_PROTECT			__attribute__ ((stack_protect))
#else
#define EGG_FUNC_ATTR_STACK_PROTECT
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_TARGET
#define EGG_FUNC_ATTR_TARGET(X)				__attribute__ ((target (X)))
#else
#define EGG_FUNC_ATTR_TARGET(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_TARGET_CLONES
#define EGG_FUNC_ATTR_TARGET_CLONES(X)			__attribute__ ((target_clones (X)))
#else
#define EGG_FUNC_ATTR_TARGET_CLONES(X)
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_WARN_UNUSED_RESULT
#define EGG_FUNC_ATTR_WARN_UNUSED_RESULT		__attribute__ ((warn_unused_result))
#else
#define EGG_FUNC_ATTR_WARN_UNUSED_RESULT
#endif

#ifdef GCC_FUNCTION_HAS_ATTR_WEAK_REF
#define EGG_FUNC_ATTR_WEAK_REF0				__attribute__ ((weakref))
#define EGG_FUNC_ATTR_WEAK_REF(X)			__attribute__ ((weakref(X)))
#else
#define EGG_FUNC_ATTR_WEAK_REF0
#define EGG_FUNC_ATTR_WEAK_REF(X)
#endif

/* X86 function attributes */
#ifdef GCC_FUNCTION_HAS_X86_ATTR_CDECL
#define EGG_X86_ATTR_CDECL				__attribute__ ((cdecl))
#else
#define EGG_X86_ATTR_CDECL
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_FASTCALL
#define EGG_X86_ATTR_FASTCALL				__attribute__ ((fastcall))
#else
#define EGG_X86_ATTR_FASTCALL
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_THISCALL
#define EGG_X86_ATTR_THISCALL				__attribute__ ((thiscall))
#else
#define EGG_X86_ATTR_THISCALL
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_ABI
#define EGG_X86_ATTR_MSABI				__attribute__ ((ms_abi))
#define EGG_X86_ATTR_SYSV_ABI				__attribute__ ((sysv_abi))
#else
#define EGG_X86_ATTR_MSABI
#define EGG_X86_ATTR_SYSV_ABI
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_CALLEE_POP_AGGREGATE_RETURN
#define EGG_X86_ATTR_CALLEE_POP_AGGREGATE_RETURN(X)	__attribute__ ((callee_pop_aggregate_return(X)))
#else
#define EGG_X86_ATTR_CALLEE_POP_AGGREGATE_RETURN(X)
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_MS_HOOK_PROLOGUE
#define EGG_X86_ATTR_MS_HOOK_PROLOGUE			__attribute__ ((ms_hook_prologue))
#else
#define EGG_X86_ATTR_MS_HOOK_PROLOGUE
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_NAKED
#define EGG_X86_ATTR_NAKED				__attribute__ ((naked))
#else
#define EGG_X86_ATTR_NAKED
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_REGPARM
#define EGG_X86_ATTR_REGPARM(X)				__attribute__ ((regparm(X)))
#else
#define EGG_X86_ATTR_REGPARM(X)
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_SSE_REGPARM
#define EGG_X86_ATTR_SSE_REGPARM			__attribute__ ((sseregparm))
#else
#define EGG_X86_ATTR_SSE_REGPARM
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_FORCE_ALIGN_ARG_POINTER
#define EGG_X86_ATTR_FORCE_ALIGN_ARG_POINTER		__attribute__ ((force_align_arg_pointer))
#else
#define EGG_X86_ATTR_FORCE_ALIGN_ARG_POINTER
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_STD_CALL
#define EGG_X86_ATTR_STD_CALL				__attribute__ ((stdcall))
#else
#define EGG_X86_ATTR_STD_CALL
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_NO_CALLER_SAVED_REGISTERS
#define EGG_X86_ATTR_NO_CALLER_SAVED_REGISTERS		__attribute__ ((no_caller_saved_registers))
#else
#define EGG_X86_ATTR_NO_CALLER_SAVED_REGISTERS
#endif

#ifdef GCC_FUNCTION_HAS_X86_ATTR_INTERRUPT
#define EGG_X86_ATTR_INTERRUPT				__attribute__ ((interrupt))
#else
#define EGG_X86_ATTR_INTERRUPT
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_ABM
#define EGG_X86_ATTR_TGT_ABM				EGG_FUNC_ATTR_TARGET("abm")
#else
#define EGG_X86_ATTR_TGT_ABM
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_AES
#define EGG_X86_ATTR_TGT_AES				EGG_FUNC_ATTR_TARGET("aes")
#else
#define EGG_X86_ATTR_TGT_AES
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_DEFAULT
#define EGG_X86_ATTR_TGT_DEFAULT			EGG_FUNC_ATTR_TARGET("default")
#else
#define EGG_X86_ATTR_TGT_DEFAULT
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_MMX
#define EGG_X86_ATTR_TGT_MMX				EGG_FUNC_ATTR_TARGET("mmx")
#else
#define EGG_X86_ATTR_TGT_MMX
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_PCLMUL
#define EGG_X86_ATTR_TGT_PCLMUL				EGG_FUNC_ATTR_TARGET("pclmul")
#else
#define EGG_X86_ATTR_TGT_PCLMUL
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_POP_CNT
#define EGG_X86_ATTR_TGT_POP_CNT			EGG_FUNC_ATTR_TARGET("popcnt")
#else
#define EGG_X86_ATTR_TGT_POP_CNT
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_SSE
#define EGG_X86_ATTR_TGT_SSE				EGG_FUNC_ATTR_TARGET("sse")
#else
#define EGG_X86_ATTR_TGT_SSE
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_SSE2
#define EGG_X86_ATTR_TGT_SSE2				EGG_FUNC_ATTR_TARGET("sse2")
#else
#define EGG_X86_ATTR_TGT_SSE2
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_SSE3
#define EGG_X86_ATTR_TGT_SSE3				GG_FUNC_ATTR_TARGET("sse3")
#else
#define EGG_X86_ATTR_TGT_SSE3
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_SSE4
#define EGG_X86_ATTR_TGT_SSE4				EGG_FUNC_ATTR_TARGET("sse4")
#else
#define EGG_X86_ATTR_TGT_SSE4
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_SSE4_1
#define EGG_X86_ATTR_TGT_SSE4_1				EGG_FUNC_ATTR_TARGET("sse4.1")
#else
#define EGG_X86_ATTR_TGT_SSE4_1
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_SSE4_2
#define EGG_X86_ATTR_TGT_SSE4_2				EGG_FUNC_ATTR_TARGET("sse4.2")
#else
#define EGG_X86_ATTR_TGT_SSE4_2
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_SSE4_a
#define EGG_X86_ATTR_TGT_SSE4_a				EGG_FUNC_ATTR_TARGET("sse4a")
#else
#define EGG_X86_ATTR_TGT_SSE4_a
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_FMA_4
#define EGG_X86_ATTR_TGT_FMA_4				EGG_FUNC_ATTR_TARGET("fma4")
#else
#define EGG_X86_ATTR_TGT_FMA_4
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_XOP
#define EGG_X86_ATTR_TGT_XOP				EGG_FUNC_ATTR_TARGET("xop")
#else
#define EGG_X86_ATTR_TGT_XOP
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_LWP
#define EGG_X86_ATTR_TGT_LWP				EGG_FUNC_ATTR_TARGET("lwp")
#else
#define EGG_X86_ATTR_TGT_LWP
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_SSSE3
#define EGG_X86_ATTR_TGT_SSSE3				EGG_FUNC_ATTR_TARGET("ssse3")
#else
#define EGG_X86_ATTR_TGT_SSSE3
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_CLD
#define EGG_X86_ATTR_TGT_CLD				EGG_FUNC_ATTR_TARGET("cld")
#else
#define EGG_X86_ATTR_TGT_CLD
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_FANCY_MATH_387
#define EGG_X86_ATTR_TGT_FANCY_MATH_387			EGG_FUNC_ATTR_TARGET("fancy-math-387")
#else
#define EGG_X86_ATTR_TGT_FANCY_MATH_387
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_IEEE_FP
#define EGG_X86_ATTR_TGT_IEEE_FP			EGG_FUNC_ATTR_TARGET("ieee-fp")
#else
#define EGG_X86_ATTR_TGT_IEEE_FP
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_INLINE_ALL_STRINGOPS
#define EGG_X86_ATTR_TGT_INLINE_ALL_STRINGOPS		EGG_FUNC_ATTR_TARGET("inline-all-stringops")
#else
#define EGG_X86_ATTR_TGT_INLINE_ALL_STRINGOPS
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_INLINE_STRINGOPS_DYNAMICALLY
#define EGG_X86_ATTR_TGT_INLINE_ALL_STRINGOPS_DYNAMICALLY EGG_FUNC_ATTR_TARGET("inline-stringops-dynamically")
#else
#define EGG_X86_ATTR_TGT_INLINE_ALL_STRINGOPS_DYNAMICALLY
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_ALIGN_STRINGOPS
#define EGG_X86_ATTR_TGT_INLINE_ALIGN_STRINGOPS		EGG_FUNC_ATTR_TARGET("align-stringops")
#else
#define EGG_X86_ATTR_TGT_INLINE_ALIGN_STRINGOPS
#endif

#ifdef GCC_HAS_ATTR_X86_TGT_RECIP
#define EGG_X86_ATTR_TGT_RECIP				EGG_FUNC_ATTR_TARGET("recip")
#else
#define EGG_X86_ATTR_TGT_RECIP
#endif

/* ------------------------------------------------------------
 * VARIABLE ATTRIBUTES
 * ------------------------------------------------------------ */

#ifdef GCC_VARIABLE_HAS_ATTR_CLEAN_UP
#define EGG_VAR_ATTR_CLEAN_UP(X)			__attribute__ ((cleanup(X)))
#else
#define EGG_VAR_ATTR_CLEAN_UP(X)
#endif

#ifdef GCC_VARIABLE_HAS_ATTR_COMMON
#define EGG_VAR_ATTR_COMMON				__attribute__ ((common))
#define EGG_VAR_ATTR_NO_COMMON				__attribute__ ((nocommon))
#else
#define EGG_VAR_ATTR_COMMON
#define EGG_VAR_ATTR_NO_COMMON
#endif

#ifdef GCC_VARIABLE_HAS_ATTR_NO_STRING
#define EGG_VAR_ATTR_NO_STRING(X)			__attribute__ ((nonstring(X)))
#else
#define EGG_VAR_ATTR_NO_STRING(X)
#endif

#ifdef GCC_VARIABLE_HAS_ATTR_SECTION
#define EGG_VAR_ATTR_SECTION(X)				__attribute__ ((section(X)))
#else
#define EGG_VAR_ATTR_SECTION(X)
#endif

#ifdef GCC_VARIABLE_HAS_ATTR_TLS_MODEL
#define EGG_VAR_ATTR_TLS_MODEL(X)			__attribute__ ((tls_model(X)))
#else
#define EGG_VAR_ATTR_TLS_MODEL(X)
#endif

#ifdef GCC_VARIABLE_HAS_ATTR_VECTOR_SIZE
#define EGG_VAR_ATTR_VECTOR_SIZE(X)			__attribute__ ((vector_size(X)))
#else
#define EGG_VAR_ATTR_VECTOR_SIZE(X)
#endif

#ifdef GCC_STATEMENT_HAS_ATTR_FALLTHROUGH
#define EGG_STATEMENT_ATTR_FALLTHROUGH			__attribute__ ((fallthrough))
#else
#define EGG_STATEMENT_ATTR_FALLTHROUGH
#endif

#ifdef GCC_TYPE_HAS_ATTR_BOUND_VAR_SIZE
#define EGG_TYPE_ATTR_BOUND_VAR_SIZE			__attribute__ ((bnd_variable_size))
#else
#define EGG_TYPE_ATTR_BOUND_VAR_SIZE
#endif

#ifdef GCC_TYPE_HAS_ATTR_DESIGNATED_INIT
#define EGG_TYPE_ATTR_DESIGNATED_INIT			__attribute__ ((designated_init))
#else
#define EGG_TYPE_ATTR_DESIGNATED_INIT
#endif

#ifdef GCC_TYPE_HAS_ATTR_MAY_ALIAS
#define EGG_TYPE_ATTR_MAY_ALIAS				__attribute__ ((may_alias))
#else
#define EGG_TYPE_ATTR_MAY_ALIAS
#endif

#ifdef GCC_TYPE_HAS_ATTR_SCALAR_STORAGE_ORDER
#define EGG_TYPE_ATTR_SCALAR_STORAGE_ORDER(X)		__attribute__ ((scalar_storage_order(X)))
#else
#define EGG_TYPE_ATTR_SCALAR_STORAGE_ORDER(X)
#endif

#ifdef GCC_TYPE_HAS_ATTR_TRANSPARENT_UNION
#define EGG_TYPE_ATTR_TRANSPARENT_UNION			__attribute__ ((transparent_union))
#else
#define EGG_TYPE_ATTR_TRANSPARENT_UNION
#endif

#endif // EGG_COMMON

/* End of file */
