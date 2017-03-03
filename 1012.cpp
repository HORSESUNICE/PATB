//1012. 数字分类(20)
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

//给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
//
//A1 = 能被5整除的数字中所有偶数的和；
//A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1 - n2 + n3 - n4...；
//A3 = 被5除后余2的数字的个数；
//A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
//A5 = 被5除后余4的数字中最大数字。
//输入格式：
//
//每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，
//随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。
//
//输出格式：
//
//对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
//
//若其中某一类数字不存在，则在相应位置输出“N”。
//
//输入样例1：
//13 1 2 3 4 5 6 7 8 9 10 20 16 18
//输出样例1：
//30 11 2 9.7 9
//输入样例2：
//8 1 2 4 5 6 7 9 16
//输出样例2：
//N 11 2 N 9

//idea:
//按要求将输入的数据归类
//但要小心某类数据如果不存在注意数组下标越界的发生

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> array;
	int num;
	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		array.push_back(num);
	}

	vector<int> a, b, c, d, e;
	auto it = array.begin();
	while (it != array.end())
	{
		switch (*it%5)
		{
		case 0:
			if (*it % 2 == 0)
				a.push_back(*it);
			break;
		case 1:
			b.push_back(*it);
			break;
		case 2:
			c.push_back(*it);
			break;
		case 3:
			d.push_back(*it);
			break;
		case 4:
			e.push_back(*it);
			break;
		default:
			break;
		}
		++it;
	}

	int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
	double a4 = 0;
	
	auto it1 = a.begin();
	while (it1 != a.end())
	{
		a1 += *it1;
		++it1;
	}

	auto it2 = b.begin();
	int symbol = -1;
	while (it2 != b.end())
	{
		symbol *= -1;
		a2 += *it2*symbol;
		++it2;
	}

	a3 = static_cast<int>(c.size());

	auto it4 = d.begin();
	while (it4 != d.end())
	{
		a4 += *it4;
		++it4;
	}
	a4 /= static_cast<int>(d.size());

	//这里要小心段错误指针越界
	//如果没有第五类数
	//那给a5赋的初始值就会指向e.end()
	if (!e.empty())
	{
		auto it5 = e.begin();
		a5 = *it5;
		while (it5 != e.end())
		{
			if (a5 < *it5)
				a5 = *it5;
			++it5;
		}
	}

	if (a.empty())
		cout << "N ";
	else
		cout << a1 << " ";

	if (b.empty())
		cout << "N ";
	else
		cout << a2 << " ";

	if (c.empty())
		cout << "N ";
	else
		cout << a3 << " ";

	if (d.empty())
		cout << "N ";
	else
		//为了输出一位小数，C++的格式太麻烦了就用了printf
		printf("%.1lf ", a4);

	if (e.empty())
		cout << "N";
	else
		cout << a5;
}
