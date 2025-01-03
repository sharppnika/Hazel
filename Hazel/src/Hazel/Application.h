#pragma once
#include "Core.h"

namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
	}; 

	//定义一个应用类，并返回实例，在入口点执行run方法。返回的应用类将在客户端执行
   HAZEL_API Application* CreateApplication();
}

