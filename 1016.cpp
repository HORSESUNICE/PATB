//1016. 部分A+B (15)
//
//时间限制
//100 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。
//例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。
//
//现给定A、DA、B、DB，请编写程序计算PA + PB。
//
//输入格式：
//
//输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。
//
//输出格式：
//
//在一行中输出PA + PB的值。
//
//输入样例1：
//3862767 6 13530293 3
//输出样例1：
//399
//输入样例2：
//3862767 1 13530293 8
//输出样例2：
//0

//idea:
//只要将输入的数字转换为按要求的数字就可以
//还要当心可能没有符合要求的数字那就为0

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string a, b, da, db;
	cin >> a >> da >> b >> db;
	string s1, s2;
	for (string::size_type i = 0; i != a.size(); ++i)
	{
		if (a[i] == da[0])
			s1.push_back(da[0]);
	}

	for (string::size_type i = 0; i != b.size(); ++i)
	{
		if (b[i] == db[0])
			s2.push_back(db[0]);
	}

	long long pa = 0, pb = 0;

	//自己写的处理函数可以直接用stoi代替
	//for (string::size_type i = 0; i != s1.size(); ++i)
	//{
	//	pa += (da[0] - '0')*static_cast<int>(pow(10, i));
	//}
	//
	//for (string::size_type i = 0; i != s2.size(); ++i)
	//{
	//	pb += (db[0] - '0')*static_cast<int>(pow(10, i));
	//}

	//字符串如果为空会有异常，要注意
	if (s1.empty())
		pa = 0;
	else
		pa = stoll(s1);

	if (s2.empty())
		pb = 0;
	else
		pb = stoll(s2);

	cout << pa + pb;
}