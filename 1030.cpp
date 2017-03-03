//1030. 完美数列(25)
//
//时间限制
//300 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CAO, Peng

//给定一个正整数数列，和正整数p，
//设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。
//
//现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。
//
//输入格式：
//
//输入第一行给出两个正整数N和p，其中N（ <= 10^5）是输入的正整数的个数，
//p（ <= 10^9）是给定的参数。第二行给出N个正整数，每个数不超过10^9。
//
//输出格式：
//
//在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。
//
//输入样例：
//10 8
//2 3 20 4 5 1 6 7 8 9
//输出样例：
//8

//idea:
//这题首先要看懂意思
//按题目的意思讲输入排序是必须要做的
//之后才能求完美数列的个数
//但这题也有点奇怪
//我开始max是利用给定m从最后开始检索直到符合完美数列的M，求max=M-n
//这样做就会超时
//改成了和别人一样的从头开始检索M就通过了
//应该还是测试数据的一些问题吧

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unsigned n, p;
	cin >> n >> p;

	vector<unsigned> vu;
	unsigned num;
	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		vu.push_back(num);
	}

	sort(vu.begin(), vu.end());

	unsigned max = 0;
	unsigned it = 0;
	while (it != n)
	{
		unsigned ite = it + max;
		while (ite<n&&vu[ite] <= vu[it]*p)
		{
			++ite;
		}
		if (ite - it > max)
			max = ite - it;
		++it;
	}

	cout << max;	
}