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

	//����һ��Ӧ���࣬������ʵ��������ڵ�ִ��run���������ص�Ӧ���ཫ�ڿͻ���ִ��
   HAZEL_API Application* CreateApplication();
}

