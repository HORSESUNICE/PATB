//1062. 最简分数(20)
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

//一个分数一般写成两个整数相除的形式：N/M，其中M不为0。最简分数是指分子和分母没有公约数的分数表示形式。
//
//现给定两个不相等的正分数 N1/M1 和 N2/M2，要求你按从小到大的顺序列出它们之间分母为K的最简分数。
//
//输入格式：
//
//输入在一行中按N/M的格式给出两个正分数，随后是一个正整数分母K，其间以空格分隔。
//题目保证给出的所有整数都不超过1000。
//
//输出格式：
//
//在一行中按N/M的格式列出两个给定分数之间分母为K的所有最简分数，
//按从小到大的顺序，其间以1个空格分隔。行首尾不得有多余空格。题目保证至少有1个输出。
//
//输入样例：
//7/18 13/20 12
//输出样例：
//5/12 7/12

//idea:
//因为读入的整数之后要相除得到分数，所以吃过亏直接用double读入
//之后比较是否在两者直接来输出
//这里要小心
//题目没有说明两个读入的分数之间大小关系

#include <iostream>
#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int gcd(int m, int n)
{
	if (n == 0)
		return m;
	else if (n > m)
		return gcd(n, m);
	else
		return gcd(n, m%n);
}

int main()
{
	double n1, m1, n2, m2, k;

	scanf("%lf/%lf %lf/%lf %lf", &n1, &m1, &n2, &m2, &k);

	//输入没有保证d1和d2之间的大小关系
	double d1 = n1 / m1;
	double d2 = n2 / m2;

	if (d1 > d2)
	{
		double d = d1;
		d1 = d2;
		d2 = d;
	}

	int sym = 0;

	int i = 0;
	int zsk = static_cast<int>(k);
	while ((static_cast<double>(i) / k < d2))
	{
		if ((static_cast<double>(i) / k > d1)&&(gcd(i,zsk)==1))
		{
			if (sym)
				printf(" %d/%d", i, zsk);
			else
			{
				printf("%d/%d", i, zsk);
				sym = 1;
			}
		}
		++i;
	}
}