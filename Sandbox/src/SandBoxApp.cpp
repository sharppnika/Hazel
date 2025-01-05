
#include <Hazel.h>


class Sandbox : public Hazel::Application 
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};


//创建应用程序实例供入口点调用。入口点实际上在引擎内部，但具体的APP类需要在对应的app文件中创建。
Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}