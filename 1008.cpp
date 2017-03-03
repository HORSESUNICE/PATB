//1008. 数组元素循环右移问题(20)
//
//时间限制
//400 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard

//一个数组A中存有N（N>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（M >= 0）个位置，
//即将A中的数据由（A0 A1……AN - 1）变换为（AN - M …… AN - 1 A0 A1……AN - M - 1）（
//最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？
//
//输入格式：每个输入包含一个测试用例，第1行输入N(1 <= N <= 100)、M（M >= 0）；
//第2行输入N个整数，之间用空格分隔。
//
//输出格式：在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。
//
//输入样例：
//6 2
//1 2 3 4 5 6
//输出样例：
//5 6 1 2 3 4

//idea:
//主要是确定数组首位的数字是哪一个就可以了
//另外再注意一下M>=N的情况就可以了

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	//M的大小没有明确指出是否比N小，因此取余防止指针越界
	m %= n;

	//array存输入数据，ans存输出数据
	vector<int> array;
	vector<int> ans;
	int num;
	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		array.push_back(num);
	}
	auto it = array.end() - m;
	while (it != array.end())
	{
		ans.push_back(*it);
		++it;
	}
	it = array.begin();
	while(it!= array.end() - m)
	{
		ans.push_back(*it);
		++it;
	}

	auto itans = ans.begin();
	while (itans != ans.end() - 1)
	{
		cout << *itans << " ";
		++itans;
	}
	cout << *itans;

}