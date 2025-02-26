#include "hzpch.h"
#include "Application.h"
#include "Hazel/Log.h"
#include "Hazel/Events/MouseEvent.h"
#include <glad/glad.h>

//Hazel 命名空间 其中包含了App类的实现

namespace Hazel {  

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)

	//app类的单例
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		
		HZ_CORE_ASSERT(s_Instance == nullptr, "Application is Already exists")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		unsigned int id;
		glGenVertexArrays(1,&id);
  	}

	Application::~Application()
	{
	}

	//层栈系统。
	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer); 
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer) {
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		//HZ_CORE_TRACE("{0}",e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run() {

		while (m_Runing) {
			glClearColor(0.5, 0.6, 0.9, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate();
			}

			m_Window->OnUpdate();


		}
	}

	bool Application::OnWindowClose(WindowCloseEvent &e) {
		m_Runing = false;
		return true;
	}


}