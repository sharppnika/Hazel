
#include <Hazel.h>


class Sandbox : public Hazel::Application 
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};


//����Ӧ�ó���ʵ������ڵ���á���ڵ�ʵ�����������ڲ����������APP����Ҫ�ڶ�Ӧ��app�ļ��д�����
Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}