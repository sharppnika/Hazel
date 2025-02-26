
#include <Hazel.h>

class ExampleLayer : public Hazel::Layer 
{
public:
	ExampleLayer() :Layer("Example") {
		
	}

	void OnUpdate() override {
		//HZ_INFO("ExampleLayer::UPdate");
	}

	void OnEvent(Hazel::Event &e) override{
		//HZ_INFO("{0}",e);
	}
};




class Sandbox : public Hazel::Application 
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}
	~Sandbox() {

	}
};


//����Ӧ�ó���ʵ������ڵ���á���ڵ�ʵ�����������ڲ����������APP����Ҫ�ڶ�Ӧ��app�ļ��д�����
Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}