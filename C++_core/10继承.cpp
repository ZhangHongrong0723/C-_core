#include <iostream>
#include <string>
using namespace std;
/*
	�̳е��﷨��
	class ����{};
	class ������:�̳з�ʽ ����{};
	��̳��﷨��
	class �����ࣺ�̳з��� ����1���̳з���  ����2...{};

	������ļ̳з�ʽΪpublic ���м̳���������Ϊԭ�еĲ���
					  private				 Ϊprivate
					  protect				 Ϊprotect

	�̳��й��������˳��
	���������и���Ȼ������
	���������������ٸ���

	������Ӳ���(����)ͬ�������ʱ���Ŀ�����son.a
					  ���ʸ��׵����� son.base::a
	����Som::a		Base::a(Son::Base::a)

	��̳У���Ҫ�Ƿ�ֹ���μ̳е��µ����⣬��Ϊ�������м����̳л���ʱ����ʹ�û����ʼ�����Σ����Ե������������
	ʹ����̳У���Լ��֧�����������̳У����һ�����������ֵ�ᴫ��֮ǰ����ֵ������ȫ���ı䡣
	���������������в���Ҫ�������ֱ�ӻ�����г�ʼ������Ҫ�����������ʼ��

*/
class Person {
public:
	string m_color;
	Person(string color="blue") {
		m_color =color;
	}
	void eat() {
		cout << m_color <<endl;
		cout << "Person --eat" << endl;
	}
	~Person() {
		cout << "Person delete" << endl;
	}



};

class Worker:virtual public Person {
public :
	string m_name;
	Worker(string name,string color):Person(color) {
		m_name=name ;
		cout << "worker" << endl;
	}
	void work() {
		cout << m_name << endl;
		cout << "work" << endl;
	}
	~Worker() {
		cout << "worker delete" << endl;
	}
};

class Child : virtual public Person {
public:
	int m_age;
	Child(int age,string color) :Person(color) {
		m_age = age;
		cout << "children" << endl;
	}
	void play() {
		cout << m_age << endl;
		cout << "play" << endl;
	}
	~Child() {
		cout << "~Child" << endl;
	}

};

class chi :public Worker, public Child {
public:
	chi(string name,int age,string color):Worker( name, color) ,Child(age,color) {
		cout << "chi" << endl;
	}
	~chi() {
		cout << "chi delete" << endl;
	}

};

int main10() {
	chi * p = new chi("qq", 14, "yellow");
	p->Worker::eat();
	p->Child::eat();
	p->work();
	p->play();
	



	system("pause");
	return 0;
}