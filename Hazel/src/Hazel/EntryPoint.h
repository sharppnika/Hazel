#pragma once
#ifdef HZ_PLATFORM_WINDOWS

//��ڵ㣬ͨ��������main������������Ҫ�ṩһ����ڵ㹩�������У��������ڵ㲻Ӧ����Ӧ�ó�����ṩ��ͨ�����ַ�ʽ����ڵ��װ�������ڲ���
//appʵ������һ����


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
