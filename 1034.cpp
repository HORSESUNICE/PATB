//1034. 有理数四则运算(20)
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

//本题要求编写程序，计算2个有理数的和、差、积、商。
//
//输入格式：
//
//输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，
//其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为0。
//
//输出格式：
//
//分别在4行中按照“有理数1 运算符 有理数2 = 结果”的格式顺序输出2个有理数的和、差、积、商。
//注意输出的每个有理数必须是该有理数的最简形式“k a/b”，其中k是整数部分，a/b是最简分数部分；
//若为负数，则须加括号；若除法分母为0，则输出“Inf”。题目保证正确的输出中没有超过整型范围的整数。
//
//输入样例1：
//2/3 -4/2
//输出样例1：
//2/3 + (-2) = (-1 1/3)
//2/3 - (-2) = 2 2/3
//2/3 * (-2) = (-1 1/3)
//2/3 / (-2) = (-1/3)
//输入样例2：
//5/3 0/6
//输出样例2：
//1 2/3 + 0 = 1 2/3
//1 2/3 - 0 = 1 2/3
//1 2/3 * 0 = 0
//1 2/3 / 0 = Inf

//idea:
//这题关键就是在于输入的一个分数如何转化为按要求的最简分数的格式
//这里要用到求最大公约数的函数(gcd)
//我在这题还碰到了一个真BUG,希望有人知道的话给我解答一下，万分感谢！

#include <iostream>
#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

//这里求最大公约数担心int越界就用了long long
//用int有没有测试点会错忘记了
long long gcd(long long x, long long y)
{
	if (y > x)
		return gcd(y, x);
	else if (y == 0)
		return x;
	else
		return gcd(y, x%y);
}

//格式化输出的函数
void fun(long long a, long long b)
{
	long long k, x, y;
	long long m, n;

	long long sym = 1;
	if (a < 0)
	{
		m = -a;
		//这个就是奇怪的BUG了..

		//这里分数的正负号一定要这样判断
		//如果用a*b<0判断测试点2会错误
		//不知道测试数据是什么会产生这样的结果
		sym *= -1;
	}
	else
		m = a;

	if (b < 0)
	{
		n = -b;
		sym *= -1;
	}
	else
		n = b;
	
	if (!n)
		cout << "Inf";
	else
	{
		k = m / n;
		x = m%n;
		y = n;
		long long g = gcd(x, y);

		if (sym == -1)
			cout << "(-";
		if (k)
			cout << k;
		if (!x)
		{
			if (!k)
				cout << 0;
		}
		else
		{
			if(k)
				cout << " " << x / g << "/" << y / g;
			else
				cout << x / g << "/" << y / g;
		}

		if (sym == -1)
			cout << ")";
	}


}

void add(long long a1, long long b1, long long a2, long long b2)
{
	long long m = a1*b2 + a2*b1;
	long long n = b1*b2;

	fun(a1, b1);
	cout << " + ";
	fun(a2, b2);
	cout << " = ";
	fun(m, n);
	cout << endl;
}

void minu(long long a1, long long b1, long long a2, long long b2)
{
	long long m= a1*b2 - a2*b1;
	long long n = b1*b2;

	fun(a1, b1);
	cout << " - ";
	fun(a2, b2);
	cout << " = ";
	fun(m, n);
	cout << endl;
}

void mul(long long a1, long long b1, long long a2, long long b2)
{
	long long m = a1*a2;
	long long n = b1*b2;

	fun(a1, b1);
	cout << " * ";
	fun(a2, b2);
	cout << " = ";
	fun(m, n);
	cout << endl;
}

void div(long long a1, long long b1, long long a2, long long b2)
{
	long long m = a1*b2;
	long long n = a2*b1;

	fun(a1, b1);
	cout << " / ";
	fun(a2, b2);
	cout << " = ";
	if (b1 == 0 || b2 == 0)
		cout << "Inf";
	else
		fun(m, n);
	cout << endl;
}
int main()
{
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);

	add(a1, b1, a2, b2);
	minu(a1, b1, a2, b2);
	mul(a1, b1, a2, b2);
	div(a1, b1, a2, b2);
}