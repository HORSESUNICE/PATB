//1048. 数字加密(20)
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

//本题要求实现一种数字加密方法。首先固定一个加密用正整数A，
//对任一正整数B，将其每1位数字与A的对应位置上的数字进行以下运算：对奇数位，对应位的数字相加后对13取余
//——这里用J代表10、Q代表11、K代表12；对偶数位，用B的数字减去A的数字，若结果为负数，则再加10。
//这里令个位为第1位。
//
//输入格式：
//
//输入在一行中依次给出A和B，均为不超过100位的正整数，其间以空格分隔。
//
//输出格式：
//
//在一行中输出加密后的结果。
//
//输入样例：
//1234567 368782971
//输出样例：
//3695Q8118

//idea:
//因为两个输入会有可能长度不同
//需要在短的前面添加字符
//我用的是逆序输入两个字符
//之后再逆序输出加密结果
//也可以采用直接string(del,'0')+short的办法改变短字符串

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	string a1, b1;
	if (a.size() >= b.size())
	{
		for (auto ita = a.rbegin(); ita != a.rend(); ++ita)
		{
			a1.push_back(*ita);
		}
		for (auto itb = b.rbegin(); itb != b.rend(); ++itb)
		{
			b1.push_back(*itb);
		}
		for (int i = 0; i != a.size() - b.size(); ++i)
			b1.push_back('0');
	}
	else
	{
		for (auto itb = b.rbegin(); itb != b.rend(); ++itb)
		{
			b1.push_back(*itb);
		}
		for (auto ita = a.rbegin(); ita != a.rend(); ++ita)
		{
			a1.push_back(*ita);
		}
		for (int i = 0; i != b.size() - a.size(); ++i)
			a1.push_back('0');
	}

	string sout;
	char arr[13] = { '0','1','2','3','4','5','6','7','8','9','J','Q','K' };
	char c;
	for (int i = 0; i != b1.size(); ++i)
	{
		//偶数位
		if (i & 1)
		{
			//条件要写(b1[i] - a1[i]) >= 0,写>0就应该输出0的变成J了
			c = (b1[i] - a1[i]) >= 0 ? arr[(b1[i] - a1[i])] : arr[(b1[i] - a1[i])+10];
		}
		else
		{
			c = arr[(a1[i] - '0' + b1[i] - '0') % 13];
		}
		sout.push_back(c);
	}

	for (auto it = sout.rbegin(); it != sout.rend(); ++it)
		cout << *it;


}