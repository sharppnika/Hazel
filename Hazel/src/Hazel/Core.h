#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error Hazel only support Windows!
#endif // HZ_PLATFORM_WINDOWS


#ifdef HZ_DEBUG
	#define HZ_ENABLE_ASSERTS
#endif // HZ_DEBUG




//断言宏，若未启用则进行空定义 
#ifdef HZ_ENABLE_ASSERTS
	#define HZ_ASSERT(x,...)	{if(!(x)){HZ_ERROR("Assertion Faild:{0}", __VA_ARGS__); __debugbreak();} }
	#define HZ_CORE_ASSERT(x,...)	{if(!(x)){HZ_CORE_ERROR("Assertion Faild:{0}", __VA_ARGS__); __debugbreak();} }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif // HZ_ENABLE_ASSERTS




#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(className,fn)		std::bind(&className::fn, this, std::placeholders::_1)