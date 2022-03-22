#include <iostream>
#include <string>
using namespace std;
/*
	继承的语法：
	class 基类{};
	class 派生类:继承方式 基类{};
	多继承语法：
	class 派生类：继承方法 基类1，继承方法  基类2...{};

	派生类的继承方式为public 其中继承来的属性为原有的不变
					  private				 为private
					  protect				 为protect

	继承中构造和析构顺序
	构造中先有父类然后子类
	析构是先有子类再父类

	如果父子参数(方法)同名，访问本身的可以用son.a
					  访问父亲的则用 son.base::a
	或者Som::a		Base::a(Son::Base::a)

	虚继承，主要是防止菱形继承导致的问题，因为当两个中间的类继承基类时，会使得基类初始化两次，所以当这种问题出现
	使用虚继承，节约开支，如果不用虚继承，最后一个派生类的数值会传给之前的数值。并且全部改变。
	而在最后的派生类中不仅要负责对其直接基类进行初始化，还要负责对虚基类初始化

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