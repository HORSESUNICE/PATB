//1043. 输出PATest(20)
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

//给定一个长度不超过10000的、仅由英文字母构成的字符串。
//请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。
//当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，
//直到所有字符都被输出。
//
//输入格式：
//
//输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。
//
//输出格式：
//
//在一行中按题目要求输出排序后的字符串。题目保证输出非空。
//
//输入样例：
//redlesPayBestPATTopTeePHPereatitAPPT
//输出样例：
//PATestPATestPTetPTePePee

//idea:
//这题只要统计六个字母的个数就可以
//然后依次输出
//每输出一个字母就将计数--就可以

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	istringstream is(s);

	int patest[6] = { 0 };

	char c;
	while (is >> c)
	{
		if (c == 'P')
			++patest[0];
		if (c == 'A')
			++patest[1];
		if (c == 'T')
			++patest[2];
		if (c == 'e')
			++patest[3];
		if (c == 's')
			++patest[4];
		if (c == 't')
			++patest[5];
	}

	while (patest[0] > 0 || patest[1] > 0 || patest[2] > 0 || patest[3] > 0 || patest[4] > 0 || patest[5] > 0)
	{
		if (patest[0] > 0)
		{
			cout << "P";
			--patest[0];
		}
		if (patest[1] > 0)
		{
			cout << "A";
			--patest[1];
		}
		if (patest[2] > 0)
		{
			cout << "T";
			--patest[2];
		}
		if (patest[3] > 0)
		{
			cout << "e";
			--patest[3];
		}
		if (patest[4] > 0)
		{
			cout << "s";
			--patest[4];
		}
		if (patest[5] > 0)
		{
			cout << "t";
			--patest[5];
		}
	}
}