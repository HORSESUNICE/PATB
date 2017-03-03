//1058. 选择题(20)
//
//时间限制
//300 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//批改多选题是比较麻烦的事情，本题就请你写个程序帮助老师批改多选题，并且指出哪道题错的人最多。
//
//输入格式：
//
//输入在第一行给出两个正整数N（ <= 1000）和M（ <= 100），
//分别是学生人数和多选题的个数。随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、
//选项个数（不少于2且不超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。
//注意每题的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。
//最后N行，每行给出一个学生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，
//按题目顺序给出。注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。
//
//输出格式：
//
//按照输入的顺序给出每个学生的得分，每个分数占一行。注意判题时只有选择全部正确才能得到该题的分数。
//最后一行输出错得最多的题目的错误次数和编号（题目按照输入的顺序从1开始编号）。
//如果有并列，则按编号递增顺序输出。数字间用空格分隔，行首尾不得有多余空格。
//如果所有题目都没有人错，则在最后一行输出“Too simple”。
//
//输入样例：
//3 4
//3 4 2 a c
//2 5 1 b
//5 3 2 b c
//1 5 4 a b d e
//(2 a c) (2 b d) (2 a c) (3 a b e)
//(2 a c) (1 b) (2 a b) (4 a b d e)
//(2 b d) (1 e) (2 b c) (4 a b c d)
//输出样例：
//3
//6
//5
//2 2 3 4

//idea:
//这题以为是格式化的输入
//我们对每行输入可以这样处理
//遇到(时，将下一个字符读入，然后根据读入数字大小，每隔两个字符读入一个选项，然后跳过这样的一段长度
//以此进行循环

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//用于记录多选题的各项内容
struct que
{
	int index;
	int score;
	int total;
	int cor;
	char word[5] = { 0 };
	int wrong = 0;
};

bool com(const que &q1, const que &q2)
{
	if (q1.wrong > q2.wrong)
		return true;
	else if ((q1.wrong == q2.wrong) && q1.index < q2.index)
		return true;
	else
		return false;
}

struct st
{
	int choose;
	char word[5] = { 0 };
};

int main()
{
	int n, m;

	string s;
	getline(cin, s);
	istringstream is(s);
	is >> n >> m;

	vector<que> vq;

	for (int i = 0; i != m; ++i)
	{
		getline(cin, s);
		istringstream dxt(s);
		que q;
		q.index = i + 1;
		dxt >> q.score >> q.total >> q.cor;
		for (int j = 0; j != q.cor; ++j)
			dxt >> q.word[j];

		vq.push_back(q);
	}



	for (int i = 0; i != n; ++i)
	{
		getline(cin, s);
		//istringstream st(s);

		vector<st> vs;

		int sum = 0;
		int sym = 0;

		int choose = 0;

		//利用格式化输入进行处理
		for (int j = 0; j != s.size(); ++j)
		{
			if (s[j] == '(')
			{
				st ans;
				ans.choose = s[j + 1] - '0';

				for (int k = 0; k != ans.choose; ++k)
					ans.word[k] = s[j + 1 + 2 * (k + 1)];
				vs.push_back(ans);

				j += 2 * (ans.choose + 1);
			}
		}

		//比较答案
		for (int i = 0; i != m; ++i)
		{
			if (vs[i].choose != vq[i].cor)
			{
				sym = 1;
				vq[i].wrong++;
			}
			else
			{
				int j = 0;
				for (; j != vq[i].cor; ++j)
					if (vs[i].word[j] != vq[i].word[j])
					{
						vq[i].wrong++;
						break;
					}
				if (j == vq[i].cor)
					sum += vq[i].score;
			}
		}

		cout << sum << endl;
	}

	sort(vq.begin(), vq.end(), com);

	int l = 0;
	if (vq[l].wrong)
	{
		cout << vq[l].wrong;
		while (vq[l].wrong == vq[0].wrong)
		{
			cout << " " << vq[l].index;
			++l;
		}
	}
	else
		cout << "Too simple";


}