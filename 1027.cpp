//1027. 打印沙漏(20)
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

//本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印
//
//*****
// ***
//  *
// ***
//*****
//所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；
//相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。
//
//给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。
//
//输入格式：
//
//输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。
//
//输出格式：
//
//首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。
//
//输入样例：
//19 *
//输出样例：
//*****
// ***
//  *
// ***
//*****
//2

//idea:
//首先计算可以使用的最大符号数
//可用符号是1+6+10+...+2*(2n-1)
//这题要注意格式错误
//PAT的判断不能有多余输出
//在字符后面不能再输出对称的空白否则格式错误

#include <iostream>

using namespace std;

int main()
{
	int n;
	char c;
	cin >> n >> c;

	int i = 1;
	int count = 1;

	//count用于计算使用掉的最多符号数
	while ((n-count)>=(i+2)*2)
	{
		i += 2;
		count += 2 * i;
	}

	int left = n - count;

	for (int j = i; j > 0; j -= 2)
	{
		for (int k = 0; k != (i - j) / 2; ++k)
			cout << " ";

		for (int k = 0; k != j; ++k)
			cout << c;

		//输出对称的空白会导致格式错误
		//for (int k = 0; k != (i - j) / 2; ++k)
		//	cout << " ";

		cout << endl;
	}

	if (n > 6)
	{
		for (int j = 3; j <= i; j += 2)
		{
			for (int k = 0; k != (i - j) / 2; ++k)
				cout << " ";

			for (int k = 0; k != j; ++k)
				cout << c;

			//for (int k = 0; k != (i - j) / 2; ++k)
			//	cout << " ";

			cout << endl;
		}
	}

	cout << left;

}