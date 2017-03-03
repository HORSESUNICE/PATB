//1020. 月饼(25)
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
//月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。
//现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
//
//注意：销售时允许取出一部分库存。样例给出的情形是这样的：
//假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。
//如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，
//获得 72 + 45 / 2 = 94.5（亿元）。
//
//输入格式：
//
//每个输入包含1个测试用例。
//每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、
//以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。
//随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；
//最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
//
//输出格式：
//
//对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。
//
//输入样例：
//3 20
//18 15 10
//75 72 45
//输出样例：
//94.50

//idea:
//这题的想法就是先将月饼按单价逆序排列
//然后按需求量来挑选月饼并计算最大收益
//pat的数据有一些极端
//对于之后可能要转化为double用于除法的int最好输入时直接用double获取
//将int static_cast<double>往往会有一个测试点通不过
//之后也有题目会有这样的问题

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

//一个很奇怪的问题
//如果把整数输入用int来cin会有一个测试点通不过
//改成double就通过了

struct stock
{
	//int kc;
	//int zsj = 0;

	//库存，总售价，均价
	double kc;
	double zsj = 0;
	double jj = 0;
};

int main()
{
	//int n, sum;
	double n, sum;
	cin >> n >> sum;
	vector<stock> s;
	//将输入改为double
	//int num;
	double num;
	for (int i = 0; i != n; ++i)
	{
		stock st;
		cin >> num;
		st.kc = num;
		s.push_back(st);
	}
	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		s[i].zsj = num;
		s[i].jj = s[i].zsj / s[i].kc;
	}

	for (int i = 0; i != n; ++i)
	{
		for (int j = i + 1; j != n; ++j)
		{
			stock temp;
			if (s[j].jj > s[i].jj)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}

	//int max = 0;
	double max = 0;
	double maxprice = 0;
	int index = 0;
	//index用于判断月饼已经用掉了多少种
	while (index != n)
	{
		//当前种类月饼库存已经够总需求不够的部分
		if (s[index].kc >= sum - max)
		{
			maxprice += s[index].jj*(sum - max);
			break;
		}
		else
		{
			maxprice += s[index].zsj;
			max += s[index].kc;
		}
		++index;
	}
	printf("%.2lf", maxprice);

}