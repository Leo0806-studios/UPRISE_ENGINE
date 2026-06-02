#pragma once
#define UE_FINLINE __forceinline
#define UE_INLINE __inline
#define UE_DEFAUL(TypeName) TypeName() noexept = default;
#define UE_VEC_CALL __vectorcall
#define UE_FINLINE_VEC_CALL __forceinline __vectorcall
#define UE_INLINE_VEC_CALL __inline __vectorcall
#define UE_CONST_NOEXCEPT const noexcept
#define UE_SIMD_ALIGN__M128 alignas(16) //-V3547
#define UE_SIMD_ALIGN__M256 alignas(32) //-V3547
#define UE_SIMD_ALIGN__M512 alignas(64) //-V3547
#define UE_ALIGN_PTR alignas(alignof(void*))
#define UE_ALIGN_SHORT alignas(alignof(short))
#define UE_CONST_PTR(Name,...)  __VA_ARGS__* const Name
#define UE_PTR_TO_CONST(Name,...)  const __VA_ARGS__* Name