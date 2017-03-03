//1049. 数列的片段和(20)
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
//CAO, Peng

//给定一个正数数列，我们可以从中截取任意的连续的几个数，称为片段。
//例如，给定数列{ 0.1, 0.2, 0.3, 0.4 }，
//我们有(0.1) (0.1, 0.2) (0.1, 0.2, 0.3) (0.1, 0.2, 0.3, 0.4) 
//(0.2) (0.2, 0.3) (0.2, 0.3, 0.4) (0.3) (0.3, 0.4) (0.4) 这10个片段。
//
//给定正整数数列，求出全部片段包含的所有的数之和。
//如本例中10个片段总和是0.1 + 0.3 + 0.6 + 1.0 + 0.2 + 0.5 + 0.9 + 0.3 + 0.7 + 0.4 = 5.0。
//
//输入格式：
//
//输入第一行给出一个不超过10^5的正整数N，表示数列中数的个数，第二行给出N个不超过1.0的正数，是数列中的数，
//其间以空格分隔。
//
//输出格式：
//
//在一行中输出该序列所有片段包含的数之和，精确到小数点后2位。
//
//输入样例：
//4
//0.1 0.2 0.3 0.4
//输出样例：
//5.00

//idea:
//这里注意每个数属于的片段数为
//(n - i)*(i + 1);
//第i个位置的数字
//在0-i位置开头的序列中每次出现n-i次

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;

	cin >> n;
	double d[100000] = { 0.0 };
	double s = 0;

	double db;
	for (int i = 0; i != n; ++i)
	{
		cin >> d[i];
		//一定要double放前面
		//(n - i)*(i + 1)*d[i]就有测试点通不过;
		s += d[i] * (n - i)*(i + 1);
	}		

	printf("%.2lf", s);
}