#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel {
	class HAZEL_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
		Log();
		~Log();
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//日志宏，将原本包装在Hazel命名空间下的日志调用简化为宏函数 一方面可以避免繁琐的调用过程，另一方面，当被编辑为宏时，可以使用#if来在发行版中统一将宏定义为空，达到删除所有日志的功能。


//Core Log Macros
#define HZ_CORE_TRACE(...)     ::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)      ::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)      ::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)     ::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)     ::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define HZ_TRACE(...)          ::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)           ::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)           ::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)          ::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)          ::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
