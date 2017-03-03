//1055. 集体照(25)
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

//拍集体照时队形很重要，这里对给定的N个人K排的队形设计排队规则如下：
//
//每排人数为N / K（向下取整），多出来的人全部站在最后一排；
//后排所有人的个子都不比前排任何人矮；
//每排中最高者站中间（中间位置为m / 2 + 1，其中m为该排人数，除法向下取整）；
//每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧
//（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。
//这里假设你面对拍照者，所以你的左边是中间人的右边）；
//若多人身高相同，则按名字的字典序升序排列。这里保证无重名。
//现给定一组拍照人，请编写程序输出他们的队形。
//
//输入格式：
//
//每个输入包含1个测试用例。每个测试用例第1行给出两个正整数N（ <= 10000，总人数）和K（ <= 10，总排数）。
//随后N行，每行给出一个人的名字（不包含空格、长度不超过8个英文字母）和身高（[30, 300]区间内的整数）。
//
//输出格式：
//
//输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。
//注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。
//
//输入样例：
//10 3
//Tom 188
//Mike 170
//Eva 168
//Tim 160
//Joe 190
//Ann 168
//Bob 175
//Nick 186
//Amy 160
//John 159
//输出样例：
//Bob Tom Joe Nick
//Ann Mike Eva
//Tim Amy John

//idea:
//这题首先是对数据按身高从高到低排列
//然后利用类似1050的方法
//按规则输入
//因为最后一行人数和其他行不同，特殊处理
//之后每行按要求，从中间开始排列
//利用标记-1来建立左右的依次排序

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct person
{
	string name;
	int height;
};

bool compare(const person &p1, const person &p2)
{
	if (p1.height > p2.height)
		return true;
	else if ((p1.height == p2.height) && p1.name < p2.name)
		return true;
	else
		return false;
}

int main()
{
	int n, k, row, rowmax;
	cin >> n >> k;
	row = n / k;
	rowmax = n / k + n%k;
	vector<person> vp;
	vector<string> vs(rowmax, "");
	vector<vector<string>> pic(k, vs);

	for (int i = 0; i != n; ++i)
	{
		string pn;
		int ph;
		cin >> pn >> ph;
		vp.push_back({ pn,ph });
	}

	sort(vp.begin(), vp.end(), compare);
	int start;

	int sump = 0;
	for (int i = 0; i != k; ++i)
	{
		int turn = 1;
		int index = 0;
		if (i == 0)
		{
			start = rowmax / 2;
			int count = 0;
			while (count != rowmax)
			{
				pic[i][start] = vp[sump].name;
				turn *= -1;
				index += 1;
				start += turn*index;
				++count;
				++sump;
			}
		}
		else
		{
			start = row / 2;
			int count = 0;
			while (count != row)
			{
				pic[i][start] = vp[sump].name;
				turn *= -1;
				index += 1;
				start += turn*index;
				++count;
				++sump;
			}
		}
	}

	for (int i = 0; i != k; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j != rowmax; ++j)
			{
				if (j == 0)
					cout << pic[i][j];
				else
					cout << " " << pic[i][j];
			}
			cout << endl;
		}
		else
		{
			for (int j = 0; j != row; ++j)
			{
				if (j == 0)
					cout << pic[i][j];
				else
					cout << " " << pic[i][j];
			}
			cout << endl;
		}
	}
}