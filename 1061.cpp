//1061. 判断题(15)
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

//判断题的评判很简单，本题就要求你写个简单的程序帮助老师判题并统计学生们判断题的得分。
//
//输入格式：
//
//输入在第一行给出两个不超过100的正整数N和M，分别是学生人数和判断题数量。
//第二行给出M个不超过5的正整数，是每道题的满分值。
//第三行给出每道题对应的正确答案，0代表“非”，1代表“是”。
//随后N行，每行给出一个学生的解答。数字间均以空格分隔。
//
//输出格式：
//
//按照输入的顺序输出每个学生的得分，每个分数占一行。
//
//输入样例：
//3 6
//2 1 3 3 4 5
//0 0 1 0 1 1
//0 1 1 0 0 1
//1 0 1 0 1 0
//1 1 0 0 1 1
//输出样例：
//13
//11
//12

//idea:
//这题就按行读取数据将题目答案读取到vector
//将答案和vector比较获取得分就可以了

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> q(m, 0);

	vector<int> cor(m, 0);

	for (int i = 0; i != m; ++i)
		cin >> q[i];

	for (int i = 0; i != m; ++i)
		cin >> cor[i];

	for (int i = 0; i != n; ++i)
	{
		int sum = 0;
		int get;
		for (int j = 0; j != m; ++j)
		{
			cin >> get;
			if (get == cor[j])
				sum += q[j];
		}
		cout << sum << endl;
	}
}