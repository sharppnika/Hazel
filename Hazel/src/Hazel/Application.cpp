#include "hzpch.h"
#include "Application.h"
#include "Hazel/Log.h"
#include "GLFW/glfw3.h"


//Hazel 命名空间 其中包含了App类的实现

namespace Hazel {  

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}
	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		HZ_CORE_TRACE("{0}",e);
	}

	void Application::Run() {

		while (m_Runing) {
			glClearColor(0.5, 0.7, 0.5, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent &e) {
		m_Runing = false;
		return true;
	}


}