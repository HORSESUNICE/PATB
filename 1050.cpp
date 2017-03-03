//1050. 螺旋矩阵(25)
//
//时间限制
//150 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue

//本题要求将给定的N个正整数按非递增的顺序，填入“螺旋矩阵”。
//所谓“螺旋矩阵”，是指从左上角第1个格子开始，按顺时针螺旋方向填充。
//要求矩阵的规模为m行n列，满足条件：m*n等于N；m >= n；且m - n取所有可能值中的最小值。
//
//输入格式：
//
//输入在第1行中给出一个正整数N，第2行给出N个待填充的正整数。所有数字不超过10^4，相邻数字以空格分隔。
//
//输出格式：
//
//输出螺旋矩阵。每行n个数字，共m行。相邻数字以1个空格分隔，行末不得有多余空格。
//
//输入样例：
//12
//37 76 20 98 76 42 53 95 60 81 58 93
//输出样例：
//98 95 93
//42 37 81
//53 20 76
//58 60 76

//idea:
//首先求矩阵形状
//如果输入数字个数为完全平方就生成正方形
//否则就为比开根号取整最小整除数字个数的数为行号
//就按照题目要求的来填入数字
//首先利用vector建立矩阵
//然后按要求填入
//每次填入一个外圈
//这里我用l r u l标记了外圈的左右上下
//如果最后剩下单独列就再从上到下填入

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int m, n;
	int sq = static_cast<int>(sqrt(num));
	if (num == sq*sq)
		m = sq;
	else
	{
		m = sq + 1;
		while (num%m)
			++m;
	}
	n = num / m;

	vector<int> vi;
	int numin;
	for (int i = 0; i != num; ++i)
	{
		cin >> numin;
		vi.push_back(numin);
	}
	sort(vi.rbegin(), vi.rend());

	vector<int> vr(n, 0);
	vector<vector<int>> v(m, vr);

	int rowu = 0, rowd = m - 1, linel = 0, liner = n - 1;
	int j = 0;
	while (linel < liner)
	{
		for (int i = linel; i != liner + 1; ++i)
			v[rowu][i] = vi[j++];
		for (int i = rowu + 1; i != rowd + 1; ++i)
			v[i][liner] = vi[j++];
		for (int i = liner - 1; i != linel - 1; --i)
			v[rowd][i] = vi[j++];
		for(int i=rowd-1;i!=rowu;--i)
			v[i][linel]=vi[j++];
		++linel;
		--liner;
		++rowu;
		--rowd;
	}
	if (linel == liner)
		for (int i = rowu; i != rowd + 1; ++i)
			v[i][linel] = vi[j++];

	for(int i=0;i!=m;++i)
		for (int j = 0; j != n; ++j)
		{
			if (n == 1)
				cout << v[i][j] << endl;
			else
			{
				if (j == 0)
					cout << v[i][j];
				else if (j == n - 1)
					cout << " " << v[i][j] << endl;
				else
					cout << " " << v[i][j];
			}
		}

}