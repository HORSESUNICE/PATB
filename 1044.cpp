//1044. 火星数字(20)
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
//火星人是以13进制计数的：
//
//地球人的0被火星人称为tret。
//地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
//火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
//例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。
//为了方便交流，请你编写程序实现地球和火星数字之间的互译。
//
//输入格式：
//
//输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 
//或者是地球文，或者是火星文。
//
//输出格式：
//
//对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
//
//输入样例：
//4
//29
//5
//elo nov
//tam
//输出样例：
//hel mar
//may
//115
//13

//idea:
//这题本质上还是进制转换的问题
//只要注意一些输出的格式的问题就可以了尤其是0的问题

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string m1[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string m2[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void num(string &s)
{
	int n = 0;
	if (s[0] >= '0'&&s[0] <= '9')
	{
		n = stoi(s);
		int s, g;
		s = n / 13;
		g = n % 13;
		if (s > 0)
		{
			cout << m2[s - 1];
			//要当心刚好被13整除的时候个位的0不需要输出tret
			if (g > 0)
				cout << " " << m1[g] << endl;
			else
				cout << endl;
		}
		else
		{
			cout << m1[g] << endl;
		}
	}
	else
	{
		istringstream is(s);
		vector<string> vs;
		string hx;
		while (is >> hx)
			vs.push_back(hx);

		if (vs.size() == 1)
		{
			int i = 0, j = 0;
			for (; i != 13; ++i)
			{
				if (m1[i] == vs[0])
				{
					n = i;
					break;
				}
			}
			if (i == 13)
			{
				for (; j != 12; ++j)
				{
					if (m2[j] == vs[0])
					{
						n += 13*(j+1);
						break;
					}
				}
			}
		}

		if (vs.size() == 2)
		{
			int i = 0, j = 0;
			for (; i != 12; ++i)
			{
				if (m2[i] == vs[0])
				{
					n += 13 * (i + 1);
					break;
				}
			}
			for (; j != 13; ++j)
			{
				if (m1[j] == vs[1])
				{
					n += j;
					break;
				}
			}

		}

		cout << n << endl;
	}
}

int main()
{
	int n;
	string count;
	getline(cin, count);
	n = stoi(count);

	for (int i = 0; i != n; ++i)
	{
		string s;
		getline(cin, s);
		num(s);
	}
}