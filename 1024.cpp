//1024. 科学计数法(20)
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
//HOU, Qiming

//科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，
//其满足正则表达式[+-][1 - 9]"."[0 - 9] + E[+-][0 - 9] + ，
//即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确给出。
//
//现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
//
//输入格式：
//
//每个输入包含1个测试用例，即一个以科学计数法表示的实数A。
//该数字的存储长度不超过9999字节，且其指数的绝对值不超过9999。
//
//输出格式：
//
//对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。
//
//输入样例1：
//+ 1.23400E-03
//输出样例1：
//0.00123400
//输入样例2：
//- 1.2E+10
//输出样例2：
//- 12000000000

//idea:
//首先理解题目的科学计数法的表达方式
//+-[1,10)E+-(-10000,10000)
//输入的第一位字符用于决定数字的正负
//然后按指数的正负区分
//如果E=0,直接输出E之前部分的字符
//如果E<0,输出0.然后输出指数绝对值-1个1，再输出E之前部分的数字（不含.）
//如果E>0,如果指数的大小大于E之前数字的小数点后的有效长度，则输出E之前部分的数字（不含.）后补0
//或者将小数点向后移动指数大小的位数

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int fuhao = 0;
	if (s[0] == '-')
		fuhao = 1;

	//n是E之前的数字部分（含.）
	string n;
	
	int i = 1;
	for (; i != s.size(); ++i)
	{
		if (s[i] == 'E')
			break;
		else
			n.push_back(s[i]);
	}

	//这里转double想偷懒直接num*pow来得出结果的
	//结果发现C++对于大数字也是科学计数法表示的
	//就失败了
	//double num = stod(n);

	++i;

	//n是E之后的指数部分
	string e;
	while (i != s.size())
	{
		e.push_back(s[i]);
		++i;
	}

	int exp = stoi(e);

	if (fuhao)
		cout << "-";
	
	if (exp == 0)
		cout << n;
	else if (exp < 0)
	{
		cout << "0.";
		for (int i = 1; i != -exp; ++i)
			cout << "0";

		for (int i = 0; i != n.size(); ++i)
		{
			if(n[i]!='.')
				cout << n[i];
		}
	}
	else
	{
		if (exp >= static_cast<int>(n.size() - 2))
		{
			for (int i = 0; i != n.size(); ++i)
				if (n[i] != '.')
					cout << n[i];
			for (int i = 0; i != (exp - static_cast<int>(n.size() - 2)); ++i)
				cout << "0";
		}
		else
		{
			int k = -1;
			for (int i = 0; i != n.size(); ++i)
			{

				if (n[i] != '.')
				{
					if (i == k)
					{
						cout << n[i];
						cout << ".";
					}
					else
						cout << n[i];
				}
				else
				{
					k = i + exp;
				}

			}
		}
	}
}