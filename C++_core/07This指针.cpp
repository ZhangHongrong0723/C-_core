#include <iostream>
using namespace std;


//1��������Ƴ�ͻ


class Person {
public:
	Person(int age) {
		//age = age; ������Ϊ����������Ϊ���������������ageΪͬһ��
		this->age = age;//��ȷ
	}
	int age;
	//2�����ض������� *this
	//��ʽ���˼��
	Person& getPersonAdd(Person& p) {//�������������һ������&������ֵ��
						//�򷵻ص���ֵ���൱�ڿ������캯���еĶ���ĸ�������һ���µĶ��󣬲�û�н��е���
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
	�������в������޸ĳ�Ա���Ե�ֵ
	�磺void s()const{
	}
	�����������Ҫ�޸ĳ�Ա��������ó�Ա������Ҫ���� mutable���Σ��磺mutable int s;
	������ �� const Person p;Ҳ�����޸ļ���mutable�޸ĵ�ֵ 

	������ֻ�ܵ��ó�����

*/


	

int main7() {

	Person p(19);
	cout << p.age << endl;

	Person p1(20);
	p1.getPersonAdd(p).getPersonAdd(p);

	/*
	��ָ����Է��ʲ���Ҫ���Ա�����ķ�����������Ҫ���ʵ����Ա������
	����ʱ�򣬲����Կ�ָ��
	*/
	Person * p2 = NULL;
	p2->showClassName();
	//p2->showClassName3(13);

	cout << p1.age << endl;
	system("pause");
	return 0;
}