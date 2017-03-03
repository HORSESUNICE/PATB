//1017. A除以B(20)
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

//本题要求计算A / B，其中A是不超过1000位的正整数，B是1位正整数。
//你需要输出商数Q和余数R，使得A = B * Q + R成立。
//
//输入格式：
//
//输入在1行中依次给出A和B，中间以1空格分隔。
//
//输出格式：
//
//在1行中依次输出Q和R，中间以1空格分隔。
//
//输入样例：
//123456789050987654321 7
//输出样例：
//17636684150141093474 3

//idea:
//由于题目要求被除数的范围远远超过内置整型
//我们只能按照除法的计算方法来得出答案
//对于输出的结果要小心处理

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	int b = s2[0] - '0';

	//答案为0余X的情况要分开考虑
	if (s1.size() == 1 && s1[0] < s2[0])
		cout << "0 " << s1[0] - '0';
	else
	{
		vector<int> num;
		for (vector<int>::size_type i = 0; i != s1.size(); ++i)
		{
			num.push_back(s1[i] - '0');
		}

		vector<int>::size_type i = 0;
		int sz = 0;
		//judge用于记录是否为开头的0
		//若是结果开头的0则不输出
		int judge = 0;

		ostringstream os;

		while (i != num.size())
		{
			sz = sz * 10 + num[i];

			os << sz / b;
			sz %= b;


			++i;
		}
		os << " " << sz;

		string s = os.str();
		string::size_type j = 0;
		while (j != s.size())
		{
			//处理输出
			//如果Q的第一位是0，那这个0不输出
			if (s[j] == '0')
			{
				if (judge == 0)
					;
				else
					cout << s[j];
			}
			else
			{
				cout << s[j];
				++judge;
			}
			++j;
		}
	}
}