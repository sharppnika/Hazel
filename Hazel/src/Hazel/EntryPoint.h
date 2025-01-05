#pragma once
#ifdef HZ_PLATFORM_WINDOWS

//入口点，通俗理解就是main函数。我们需要提供一个入口点供引擎运行，而这个入口点不应当由应用程序端提供，通过这种方式将入口点封装在引擎内部。
//app实际上是一个类


extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	
	Hazel::Log::Init();
	HZ_CORE_ERROR("Initialized Log");
	HZ_INFO("Hello");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOWS
