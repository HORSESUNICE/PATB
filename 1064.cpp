//1064. 朋友数(20)
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

//如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。
//例如123和51就是朋友数，因为1 + 2 + 3 = 5 + 1 = 6，而6就是它们的朋友证号。
//给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。注意：我们默认一个整数自己是自己的朋友。
//
//输入格式：
//
//输入第一行给出正整数N。随后一行给出N个正整数，数字间以空格分隔。题目保证所有数字小于10^4。
//
//输出格式：
//
//首先第一行输出给定数字中不同的朋友证号的个数；
//随后一行按递增顺序输出这些朋友证号，数字间隔一个空格，且行末不得有多余空格。
//
//输入样例：
//8
//123 899 51 998 27 33 36 12
//输出样例：
//4
//3 6 9 26

//idea:
//由于数字有范围限制
//所以朋友数字在0-36之间
//我们用一个数组记录数据中是否有这样的朋友数

#include <iostream>
#include <iterator>

using namespace std;

int fun(int i)
{
	int f = 0;
	while (i != 0)
	{
		f += i % 10;
		i /= 10;
	}
	return f;
}

int main()
{
	int arr[40] = { 0 };

	int n;
	cin >> n;

	for (int i = 0; i != n; ++i)
	{
		int num;
		cin >> num;
		++arr[fun(num)];
	}


	int count = 0;
	for (int i = 0; i != 40; ++i)
	{
		if (arr[i])
			++count;
	}
	cout << count << endl;

	int sym = 0;
	for (int i = 0; i != 40; ++i)
	{
		if (arr[i])
		{
			if (sym)
				cout << " " << i;
			else
			{
				cout << i;
				sym = 1;
			}
		}
	}
}