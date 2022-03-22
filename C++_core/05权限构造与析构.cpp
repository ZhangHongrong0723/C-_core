#include <iostream>
using namespace std;
/*
	访问权限：
	public ：公共权限，成员类内可以访问，类外也可以访问
	private：私有权限，成员类内可以访问，类外不可以访问
	protected：保护权限，成员类内可以访问，类外不可以访问   
						 派生类可以访问基类的内容

	class和struct的区别：
		struct的成员变量默认权限是公共权限 public

		class 的成员变量默认权限是私有权限 private

	构造与析构：如果不提供构造和析构，编译器会提供，但是是空实现
		构造：
			构造主要作用于创建对象时为对象的成员属性赋值，
			构造函数由编译器自动调用，无需手动调用
			类名（）{} 可以重载，只调用一次
		析构：
			主要作用于对象销毁前系统自动调用，执行一些清理工作
			~类名（）{}不可以重载，只调用一次

		

		拷贝构造函数的调用时机

		1、使用一个已经创建完毕的对象来初始化一个新对象
		2、值传递的方式给函数参数传值
		3、值方式返回局部对象 


		默认情况下，C++编译起给一个类添加三个函数
		构造，析构和拷贝构造


		深拷贝与浅拷贝

*/

//构造函数的分类及调用
//分类
class Circle {
public:
	//构造函数
	Circle() {
		cout << "无参的构造函数调用" << endl;
	
	}
	Circle(int sum) {
		m = sum;
		cout << "有参的构造函数调用" << endl;
	}
	//拷贝构造函数
	//拷贝的时候相当于把一个对象复制到此，自然这个对象是里面的数值是不能修改的
	//然后就是拷贝的话是起一个别名，也就是引用
	Circle(const Circle &c) {
		m = c.m;
		cout << "拷贝的构造函数调用" << endl;
		
	}
	~Circle() {
	
	}
	int m;
	double get() {
		return 2 * m * 3.14;
	}
};

class Person {
public:
	Person() {
		cout << "Person的无参构造" << endl;
	}
	Person(int age,int hei) {
		mage = age;
		height=new int(hei);
		cout << "Person的有参构造" << endl;
	}
	~Person() {
		//将堆区开辟的数据进行释放操作
		//浅拷贝的问题是堆区的内存重复释放
		if (height != NULL) {
			delete height;
			height = NULL;
		}
		cout << "Person的析构" << endl;
	}
	//自己实现的拷贝构造函数，解决浅拷贝带来的问题

	Person(const Person& p) {
		cout << "Person的拷贝" << endl;
		mage = p.mage;

		//深拷贝，在堆区重新申请空间，进行拷贝操作
		//如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
		 height=new int(*p.height);

	}
	int mage;

	int* height;

};

void test02() {
	Person p1(18,178);
	Person p2(p1);
	cout << p1.mage <<"\t" << *p1.height << endl;

	cout <<"编译器进行浅拷贝操作。构造p2:		" << p1.mage << endl;
}
void test01() {
	//1、括号法
	Circle c;//调用默认构造函数的时候，不要加()，因为加了括号会认为是函数的声明，不会认为是创建对象过程
	Circle cs(10);
	Circle c3(c);
	//2、显示法
	Circle c4;
	Circle c5 = Circle(10);//有参
	Circle c6 = Circle(c5);//拷贝
	//Circle(100);//匿名对象，特点：当本行结束完成后，自动释放析构
				//且不要用拷贝构造初始化匿名对象

	//3、隐式转换法
	Circle c7 = 200;//相当于有参构造
	Circle c8 = c7;//相当于拷贝构造
}
int main5() {
	//Circle *c1=new Circle();
	//c1->m = 10;
	//test01();
	test02();
	system("pause");
	return 0;
} 