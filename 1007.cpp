//1007. 素数对猜想 (20)
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

//让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。
//显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
//
//现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。
//
//输入格式：每个测试输入包含1个测试用例，给出正整数N。
//
//输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
//
//输入样例：
//20
//输出样例：
//4

//idea:这题主要就是写一个判定素数的函数

#include <iostream>
#include <cmath>

using namespace std;

//判断是否为素数
bool f(int n)
{
	//因为后面的输入从5开始所有1是否为素数就没有写进来
	//double sqrt(n)
	//这里n开根号之后务必要+1；否则完全平方数被视为素数
	for (int i = 2; i != static_cast<int>(sqrt(n)) + 1; ++i)
		//如果不进行类型转换
		//double sqrt(n),返回double,当i=n的时候返回false
		if (n%i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	int count = 0;
	if (n > 4)
	{
		for (int i = 5; i != n + 1; ++i)
			if (f(i) && f(i - 2))
				++count;
	}
	cout << count;
}