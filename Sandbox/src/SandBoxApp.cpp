
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


//创建应用程序实例供入口点调用。入口点实际上在引擎内部，但具体的APP类需要在对应的app文件中创建。
Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}