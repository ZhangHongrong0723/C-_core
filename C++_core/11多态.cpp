#include <iostream>
using namespace std;
/*
	多态：
	1、静态多态
	2、动态多态
	静态多态：函数重载进行运算符重载属于静态多态，复用函数名
	动态多态：派生类和虚函数实现运行时多态
	区别：
	静态多态的函数地址早绑定-编译阶段确定函数地址
	动态多态的函数地址晚绑定-运行阶段确定函数地址

	父类的引用可以包含孩子的引用
	比如我定义的对象为孩子，但是方法的形参是父亲，则调用父亲的方法。
							因为这是静态多态，编译时候绑定

    如果想定义时的对象为孩子，方法虽然形参也是父亲
	但是调用的也是孩子，则需要再方法前加上virtual
	这样就是动态多态，地址晚绑定，运行确定

	父类的指针或引用指向子类的对象

	（子类需要重写父类的虚函数，记住想运行时多态，必须在父类的方法前加virtual，子类随便加不加）

	纯虚函数语法
	virtual 返回值类型 函数名（参数列表）=0；
	当类中拥有了纯虚函数，这个类也是抽象类

	抽象类特点
	1、无法实例化对象
	2、子类必须重写抽象类中的纯虚函数，否则也属于抽象类

	抽象类中可以有非抽象的方法
	
	*/

class Person {
	//纯虚函数
public:
	virtual void speak() = 0;
	void get() {
		cout << "hello" << endl;
	}
};
class boy:public Person {
public:
	 void speak() {
		cout << "boyhello" << endl;
	}
	void frees() {
		cout << "hi" << endl;
	}

};
int main11() {
	Person *b = new boy;
	b->speak();
	system("pause");
	return 0;
}