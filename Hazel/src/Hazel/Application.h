#pragma once
#include "Core.h"
#include "Hazel/Events/Event.h"
#include "Window.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/LayerStack.h"


namespace Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;	
		bool m_Runing = true;
		LayerStack m_LayerStack;
	}; 

	//定义一个应用类，并返回实例，在入口点执行run方法。返回的应用类将在客户端执行
    Application* CreateApplication();
}

