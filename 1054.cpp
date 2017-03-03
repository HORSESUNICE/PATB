//1054. 求平均值 (20)
//
//时间限制
//400 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//本题的基本要求非常简单：给定N个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。
//一个“合法”的输入是[-1000，1000]区间内的实数，并且最多精确到小数点后2位。
//当你计算平均值的时候，不能把那些非法的数据算在内。
//
//输入格式：
//
//输入第一行给出正整数N（<=100）。随后一行给出N个实数，数字间以一个空格分隔。
//
//输出格式：
//
//对每个非法输入，在一行中输出“ERROR: X is not a legal number”，其中X是输入。
//最后在一行中输出结果：“The average of K numbers is Y”，
//其中K是合法输入的个数，Y是它们的平均值，精确到小数点后2位。
//如果平均值无法计算，则用“Undefined”替换Y。如果K为1，则输出“The average of 1 number is Y”。
//
//输入样例1：
//7
//5 -3.2 aaa 9999 2.3.4 7.123 2.35
//输出样例1：
//ERROR: aaa is not a legal number
//ERROR: 9999 is not a legal number
//ERROR: 2.3.4 is not a legal number
//ERROR: 7.123 is not a legal number
//The average of 3 numbers is 1.38
//输入样例2：
//2
//aaa -9999
//输出样例2：
//ERROR: aaa is not a legal number
//ERROR: -9999 is not a legal number
//The average of 0 numbers is Undefined

//idea:
//这题关键在于合法数据的判断
//首先合法数据的组成只能是+- 0-9 ,
//另外.只能有一个且最多两位小数

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	string line;
	getline(cin, line);
	int n;
	n = stoi(line);

	getline(cin, line);
	istringstream is(line);
	string s;
	int legal = 0;
	double sum = 0;
	
	for (int i = 0; i != n; ++i)
	{
		is >> s;
		int dotcount = 0;
		int j = 0;
		for (; j != s.size(); ++j)
		{
			if ((s[j] >= '0'&&s[j] <= '9') || (s[j] == '+' || s[j] == '-' || s[j] == '.'))
			{
				if (s[j] == '-' || s[j] == '+')
				{
					if (j == 0)
						continue;
					else
						break;
				}
				if (s[j] >= '0'&&s[j] <= '9')
					continue;
				if (s[j] == '.')
				{
					++dotcount;
					if (s.size() - j > 3)
						break;
				}
				if (dotcount > 1)
					break;
				else
					continue;
			}
			else
				break;
		}

		if (j == s.size())
		{
			double nn = stod(s);
			if (nn >= -1000 && nn <= 1000)
			{
				++legal;
				sum += nn;
			}
			else
				cout << "ERROR: " << s << " is not a legal number" << endl;
		}
		else
		{
			cout << "ERROR: " << s << " is not a legal number" << endl;
		}
	}
	cout << "The average of " << legal;
	if (legal == 1)
		//注意看题目一个合法输入的时候不能加s
		cout << " number is ";
	else
		cout << " numbers is ";
	if (legal == 0)
		cout << "Undefined" << endl;
	else
	{
		double avg = sum / legal;
		printf("%.2lf\n", avg);
	}
}