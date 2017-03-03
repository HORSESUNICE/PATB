//1033. 旧键盘打字(20)
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
//现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？
//
//输入格式：
//
//输入在2行中分别给出坏掉的那些键、以及应该输入的文字。
//其中对应英文字母的坏键以大写给出；每段文字是不超过105个字符的串。
//可用的字符包括字母[a - z, A - Z]、数字0 - 9、
//以及下划线“_”（代表空格）、“, ”、“.”、“ - ”、“ + ”（代表上档键）。
//题目保证第2行输入的文字串非空。
//
//注意：如果上档键坏掉了，那么大写的英文字母无法被打出。
//
//输出格式：
//
//在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
//
//7+IE.
//7_This_is_a_test.
//输出样例：
//_hs_s_a_tst

//idea:
//这题和1029正好相反
//但我们用一样的处理方式
//用一个数组记录下坏键
//对输入按顺序判断后输出
//这里有个测试点是没有坏键的情况要小心

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string error, stringin, stringout;
	//cin >> error >> stringin;
	//要注意第一行为空的情况
	getline(cin, error);
	cin >> stringin;

	int sym[41] = { 0 };

	for (string::size_type i = 0; i != error.size(); ++i)
	{
		if (error[i] >= 'A'&&error[i] <= 'Z')
			sym[error[i] - 'A'] = 1;
		else if (error[i] >= '0'&&error[i] <= '9')
			sym[26 + error[i] - '0'] = 1;
		else if (error[i] == '_')
			sym[36] = 1;
		else if (error[i] == ',')
			sym[37] = 1;
		else if (error[i] == '.')
			sym[38] = 1;
		else if (error[i] == '-')
			sym[39] = 1;
		else if (error[i] == '+')
			sym[40] = 1;
	}


	for (string::size_type i = 0; i != stringin.size(); ++i)
	{
		if (stringin[i] >= 'A'&&stringin[i] <= 'Z')
		{
			if (sym[stringin[i] - 'A'] == 0 && sym[40] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] >= 'a'&&stringin[i] <= 'z')
		{
			if (sym[stringin[i] - 'a'] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] >= '0'&&stringin[i] <= '9')
		{
			if (sym[26 + stringin[i] - '0'] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] == '_')
		{
			if (sym[36] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] == ',')
		{
			if (sym[37] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] == '.')
		{
			if (sym[38] == 0)
				stringout.push_back(stringin[i]);
		}
		else if (stringin[i] == '-')
		{
			if (sym[39] == 0)
				stringout.push_back(stringin[i]);
		}
		//else if (stringin[i] == '+')
		//{
		//	if (sym[40] == 0)
		//		stringout.push_back(stringin[i]);
		//}
	}

	if (stringout.empty())
		cout << endl;
	else
		cout << stringout;
}