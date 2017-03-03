//1039. 到底买不买（20）
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

//小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，
//但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？
//如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。
//
//为方便起见，我们用[0 - 9]、[a - z]、[A - Z]范围内的字符来表示颜色。
//例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；
//第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。
//
//
//图 1
//输入格式：
//
//每个输入包含1个测试用例。
//每个测试用例分别在2行中先后给出摊主的珠串和小红想做的珠串，两串都不超过1000个珠子。
//
//输出格式：
//
//如果可以买，则在一行中输出“Yes”以及有多少多余的珠子；
//如果不可以买，则在一行中输出“No”以及缺了多少珠子。其间以1个空格分隔。
//
//输入样例1：
//ppRYYGrrYBR2258
//YrR8RrY
//输出样例1：
//Yes 8
//输入样例2：
//ppRYYGrrYB225
//YrR8RrY
//输出样例2：
//No 2

//idea:
//这题其实可以用map记录改良一下
//我这里的写法是这样的
//首先用sort和unique_copy得到需要的珠子类型
//然后用count计算需要的和实际提供的差别

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

//记录需要的珠子类型和不够的数量
struct symbol
{
	char c;
	int count;
};

int main()
{
	string act, want;
	cin >> act >> want;
	//sort(act.begin(),act.end());
	sort(want.begin(),want.end());

	string actuni, wantuni;
	//unique_copy(act.begin(), act.end(), back_inserter(actuni));
	unique_copy(want.begin(), want.end(), back_inserter(wantuni));

	//测试wantuni是否正确
	//cout << wantuni << endl;

	vector<symbol> vs;

	for (int i = 0; i != wantuni.size(); ++i)
	{
		vs.push_back({ wantuni[i],count(act.begin(),act.end(),wantuni[i]) - count(want.begin(),want.end(),wantuni[i]) });
	}

	//检测count是否正确
	//for (int i = 0; i != vs.size(); ++i)
	//{
	//	cout << vs[i].count << endl;
	//}

	//sum用于记录不够的珠子
	int sum = 0;
	for (int i = 0; i != vs.size(); ++i)
	{
		if (vs[i].count < 0)
			sum += -vs[i].count;
	}

	if (sum == 0)
		cout << "Yes " << act.size() - want.size();
	else
		cout << "No " << sum;
}