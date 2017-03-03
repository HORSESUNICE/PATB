//1032. 挖掘机技术哪家强(20)
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

//为了用事实说明挖掘机技术到底哪家强，PAT组织了一场挖掘机技能大赛。
//现请你根据比赛结果统计出技术最强的那个学校。
//
//输入格式：
//
//输入在第1行给出不超过10^5的正整数N，即参赛人数。
//随后N行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从1开始连续编号）、
//及其比赛成绩（百分制），中间以空格分隔。
//
//输出格式：
//
//在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。
//
//输入样例：
//6
//3 65
//2 80
//1 100
//2 70
//3 40
//3 0
//输出样例：
//2 150

//idea:
//因为不知道参数学校数
//可以使用100001的数组来记录了学校的分数
//我这里是直接用了map
//记录完分数就只要求出最高分的序号就可以了

//这里我用了map才勉强通过

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> wjj;

	int index, grade;

	for (int i = 0; i != n; ++i)
	{
		cin >> index >> grade;
		wjj[index] += grade;
	}

	auto it = wjj.cbegin();
	int indexmax, grademax;
	indexmax = it->first;
	grademax = it->second;
	while (it != wjj.cend())
	{
		if (it->second > grademax)
		{
			indexmax = it->first;
			grademax = it->second;
		}
		++it;
	}

	cout << indexmax << " " << grademax;
}