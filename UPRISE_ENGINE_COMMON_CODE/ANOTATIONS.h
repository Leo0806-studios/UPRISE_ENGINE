#pragma once


#define UE_NODISCARD [[nodiscard]]
#define UE_NODISCARD_MSG(msg) [[nodiscard(msg)]]
#define UE_FALLTROUGH [[fallthrough]]
#define UE_MAYBE_UNUSED [[maybe_unused]]
#define UE_DEPRECATED [[deprecated]]
#define UE_DEPRECATED_MSG(msg) [[deprecated(msg)]]
#define UE_NORETURN [[noreturn]]
#define UE_NO_UNIQUE_ADDRESS [[no_unique_address]]
#ifdef __clang__

#define UE_UNUSED_PARAMETER(X) (void)X 
#else

#define UE_UNUSED_PARAMETER(X) (void)X __pragma(message("ignoring parameter " #X " in function " __FUNCSIG__ " in file "  __FILE__))
#endif // __clang__


