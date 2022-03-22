#include<iostream>
using namespace std;
#include <fstream>
#include <string>
/*
	包含头文件<fstream>
	文件操作一般包含有文本文件的读写和二进制文件的读写
	文本文件：以文本的ASCII码的方式存在计算机中
	二进制文件：文件以二进制的形式存在于计算机中，用户一般不能直接读懂

	文件操作三大类：
	ofstream:写文件
	ifstream：读文件
	fstream：读写文件

	打开方式    解释
	ios::in	    为读文件而打开
	ios::out    为写文件而打开
	ios::ate    初始位置：文件尾
	ios::app    追加方式写文件
	ios::trunc  如果文件存在，先删除在创建
	ios::binary 二进制方式
	

	如果想用二进制方式写一个文件，需要使用|
	ios::binary|ios::in
*/
int main12() {
	ofstream ofst;
	ofst.open("C:/test/as.txt", ios::out);
	string word;
	cin >> word;
	ofst << word;
	ofst.close();
	cout << "写入成功" << endl;

	ifstream ifst;
	ifst.open("C:/test/ss.txt", ios::in);
	if (!ifst.is_open()) {
		cout << "文件打开失败" << endl;
	}
	//读文件的四种方式
	/* 1、
	char buf[1024]={0};
	while (ifst>>buf) {
		cout << buf << endl;
	}*/

	/*2、
	char buf[1024] = { 0 };
	while (ifst.getline(buf,sizeof(buf))) {
		cout << buf << endl;
	}*/


	string buf;
	while (getline(ifst, buf)) {
		cout << buf<<endl;
	}

	/*
		4、不常用
	char c;
	while (c=ifst.get()!=EOF) {
		cout << c;
	}*/
	ifst.close();

	system("pause");
	return 0;
}