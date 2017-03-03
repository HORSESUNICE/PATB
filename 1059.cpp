//1059. C语言竞赛(20)
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

//C语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：
//
//0. 冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
//1. 排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
//2. 其他人将得到巧克力。
//
//给定比赛的最终排名以及一系列参赛者的ID，你要给出这些参赛者应该获得的奖品。
//
//输入格式：
//
//输入第一行给出一个正整数N（<=10000），是参赛者人数。
//随后N行给出最终排名，每行按排名顺序给出一位参赛者的ID（4位数字组成）。
//接下来给出一个正整数K以及K个需要查询的ID。
//
//输出格式：
//
//对每个要查询的ID，在一行中输出“ID: 奖品”，其中奖品
//或者是“Mystery Award”（神秘大奖）、或者是“Minion”（小黄人）、
//或者是“Chocolate”（巧克力）。如果所查ID根本不在排名里，打印“Are you kidding?”（耍我呢？）。
//如果该ID已经查过了（即奖品已经领过了），打印“ID: Checked”（不能多吃多占）。
//
//输入样例：
//6
//1111
//6666
//8888
//1234
//5555
//0001
//6
//8888
//0001
//1111
//2222
//8888
//2222
//输出样例：
//8888: Minion
//0001: Chocolate
//1111: Mystery Award
//2222: Are you kidding?
//8888: Checked
//2222: Are you kidding?

//idea:
//首先按输入将id获奖排序
//之后再利用一个数组作为是否领奖的标记
//把id当成int构建数组就不会超时了
//我这里把id当成string利用map搜索

#include <iostream>
#include <string>
#include <cmath>
#include <map>

using namespace std;

bool ss(int n)
{
	if (n == 1)
		return false;
	if (n == 2)
		return true;

	for (int i = 2; i != static_cast<int>(sqrt(n)) + 1; ++i)
		if (n%i == 0)
			return false;

	return true;
}

int main()
{
	map<string, string> mapid;
	map<string, int> mapcheck;
	string s;
	int n;

	getline(cin, s);
	n = stoi(s);

	for (int i = 0; i != n; ++i)
	{
		getline(cin, s);
		if (i == 0)
		{
			mapid[s] = "Mystery Award";
			mapcheck[s] = 1;
		}
		else
		{
			if (ss(i + 1))
			{
				mapid[s] = "Minion";
				mapcheck[s] = 1;
			}
			else
			{
				mapid[s] = "Chocolate";
				mapcheck[s] = 1;
			}
		}

	}

	getline(cin, s);
	int k = stoi(s);
	for (int i = 0; i != k; ++i)
	{
		getline(cin, s);

		if (mapcheck[s]==0)
			cout << s << ": Are you kidding?" << endl;
		else
		{
			if (mapcheck[s] == 1)
			{
				cout << s << ": " << mapid[s] << endl;
				++mapcheck[s];
			}
			else
			{
				cout << s << ": Checked" << endl;
			}
		}
	}
}