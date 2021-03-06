//1029. 旧键盘(20)
//
//时间限制
//200 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
//现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。
//
//输入格式：
//
//输入在2行中分别给出应该输入的文字、以及实际被输入的文字。
//每段文字是不超过80个字符的串，由字母A - Z（包括大、小写）、数字0 - 9、以及下划线“_”（代表空格）组成。
//题目保证2个字符串均非空。
//
//输出格式：
//
//按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有1个坏键。
//
//输入样例：
//7_This_is_a_test
//_hs_s_a_es
//输出样例：
//7TI

//idea:
//这题我是用输入的字符串的每一个字符和输出的每一个字符比较是否为坏键盘
//这里没超时真是万幸
//要稍微改良一下的话可以用map来记录输出的字符

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	string s;
	for (string::size_type i = 0; i != s1.size(); ++i)
	{
		string::size_type j = 0;
		for (; j != s2.size(); ++j)
		{
			if (s1[i] == s2[j])
				break;
		}
		if (j == s2.size())
		{
			if (s1[i] >= 'a'&&s1[i] <= 'z')
				s.push_back(static_cast<char>(s1[i] - 32));
			else
				s.push_back(s1[i]);
		}
	}

	//cout << s;

	//因为记录的s的坏键盘中可能存在重复输入，将数字只输出一遍
	int sym[37] = { 0 };

	for (string::size_type i = 0; i != s.size(); ++i)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			if (sym[s[i] - 'A'] == 0)
			{
				cout << s[i];
				sym[s[i] - 'A'] = 1;
				continue;
			}
		}
		if (s[i] >= '0'&&s[i] <= '9')
		{
			if (sym[26+s[i] - '0'] == 0)
			{
				cout << s[i];
				sym[26+s[i] - '0'] = 1;
				continue;
			}
		}
		if (s[i]=='_')
		{
			if (sym[36] == 0)
			{
				cout << s[i];
				sym[36] = 1;
				continue;
			}
		}
	}

}