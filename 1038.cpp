//1038. 统计同成绩学生(20)
//
//时间限制
//250 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。
//
//输入格式：
//
//输入在第1行给出不超过105的正整数N，即学生总人数。
//随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），
//随后是K个分数，中间以空格分隔。
//
//输出格式：
//
//在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
//
//输入样例：
//10
//60 75 90 55 75 99 82 90 75 50
//3 75 90 88
//输出样例：
//3 2 0

//idea:
//这题和1032类似
//开始用vector和count会-6超时
//改成用数组计数就通过了

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	vector<int> grade;

	int n;
	int num;
	cin >> n;

	int st[101] = { 0 };

	for (int i = 0; i != n; ++i)
	{
		scanf("%d", &num);

		++st[num];
	}

	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		scanf("%d", &num);

		grade.push_back(num);
	}

	cout << st[grade[0]];
	if (grade.size() > 1)
	{
		for (int i = 1; i != grade.size(); ++i)
			cout << " " << st[grade[i]];
	}
}