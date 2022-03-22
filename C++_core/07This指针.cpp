#include <iostream>
using namespace std;


//1、解决名称冲突


class Person {
public:
	Person(int age) {
		//age = age; 错误，因为编译器会认为包括括号里的三个age为同一个
		this->age = age;//正确
	}
	int age;
	//2、返回对象本身用 *this
	//链式编程思想
	Person& getPersonAdd(Person& p) {//如果函数方法第一个不用&，而用值，
						//则返回的数值是相当于拷贝构造函数中的对象的副本，是一个新的对象，并没有进行叠加
		this->age += p.age;
		return *this;
	}

	void showClassName() {
	
		cout << "this is classname" << endl;
	}

	/*void showClassName3(int age) {

		cout << this->age << endl;
	}
	int agge;
	*/
};

/*
	常函数中不可以修改成员属性的值
	如：void s()const{
	}
	常函数中如果要修改成员变量，则该成员变量需要加上 mutable修饰，如：mutable int s;
	常对象 如 const Person p;也可以修改加上mutable修改的值 

	常对象只能调用常函数

*/


	

int main7() {

	Person p(19);
	cout << p.age << endl;

	Person p1(20);
	p1.getPersonAdd(p).getPersonAdd(p);

	/*
	空指针可以访问不需要类成员变量的方法。但是需要访问到类成员变量的
	方法时候，不可以空指针
	*/
	Person * p2 = NULL;
	p2->showClassName();
	//p2->showClassName3(13);

	cout << p1.age << endl;
	system("pause");
	return 0;
}