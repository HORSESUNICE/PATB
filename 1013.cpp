//1013. 数素数(20)
//
//时间限制
//100 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//令Pi表示第i个素数。现任给两个正整数M <= N <= 10^4，请输出PM到PN的所有素数。
//
//输入格式：
//
//输入在一行中给出M和N，其间以空格分隔。
//
//输出格式：
//
//输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
//
//输入样例：
//5 27
//输出样例：
//11 13 17 19 23 29 31 37 41 43
//47 53 59 61 67 71 73 79 83 89
//97 101 103

//idea:
//这题关键还是和1007一样在于写一个判定素数的函数
//我为了偷懒就把前10000个素数先全部求出来了，再按要求取数

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//判断是否为素数
bool f(int n)
{
	if (n == 2)
		return true;
	for (int i = 2; i != static_cast<int>(sqrt(n)) + 1; ++i)
		if (n%i == 0)
			return false;
	return true;
}

int main()
{
	vector<int> ss;
	int count = 0;
	int num = 2;
	while (count != 10001)
	{
		if (f(num))
		{
			ss.push_back(num);
			++count;
		}
		++num;
	}
	int m, n;
	cin >> m >> n;
	//ans用于记录需要输出的所有素数
	vector<int> ans;
	auto it = ss.begin() + m - 1;
	while (it != ss.begin() + n)
	{
		ans.push_back(*it);
		++it;
	}

	auto itans = ans.begin();
	while (itans != ans.end())
	{
		//每行的第一个数字
		if ((itans - ans.begin()) % 10 == 0)
			cout << *itans;
		//每行的最后一个数字
		else if ((itans - ans.begin()) % 10 == 9)
			cout << " " << *itans << endl;
		else
			cout << " " << *itans;
		++itans;
	}
}