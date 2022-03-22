#include<iostream>
using namespace std;
#include <fstream>
class Person {
public:
	char m_name[20];
	int m_age;

	

};
int main13() {
	ofstream ofst;
	ofst.open("C:/test/abc.txt",ios::binary|ios::out);
	Person p = {"张三",18};
	ofst.write((const  char*)&p,sizeof(p));
	ofst.close();

	ifstream ifst;
	ifst.open("C:/test/abc.txt",ios::binary|ios::in);
	if (!ifst.is_open()) {
		cout << "文件未打开" << endl;
	}
	else {
		Person p;
		ifst.read(( char *)&p,sizeof(p));
		cout << "姓名是" << p.m_name << endl;
		cout << "年龄是" << p.m_age << endl;
	}
	ifst.close();
	system("pause");
	return 0;
}