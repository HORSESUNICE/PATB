//1035. 插入与归并(25)
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

//根据维基百科的定义：
//
//插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。
//每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
//
//归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，
//然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。
//
//现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？
//
//输入格式：
//
//输入在第一行给出正整数N(<= 100)；随后一行给出原始序列的N个整数；
//最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。
//
//输出格式：
//
//首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；
//然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。
//数字间以空格分隔，且行末不得有多余空格。
//输入样例1：
//10
//3 1 2 8 7 5 9 4 6 0
//1 2 3 7 8 5 9 4 6 0
//输出样例1：
//Insertion Sort
//1 2 3 5 7 8 9 4 6 0
//输入样例2：
//10
//3 1 2 8 7 5 9 4 0 6
//1 3 2 8 5 7 4 9 0 6
//输出样例2：
//Merge Sort
//1 2 3 8 4 5 7 9 0 6

//idea:
//这题我第一次做是将输入序列进行循环
//每次进行一次归并排序和插入排序，分别用两个vector记录
//然后和中间序列比较
//结果显而易见超时了
//后来看了别人的方法发现可以寻找第一个未升序排列的数字，比较之后的数字是否和输入相同
//来确定是属于哪种排序
//但这里我还遇到了一个暂时没想通的问题，一样求解答
//如果是归并排序，下一步应该是将已经排序的两倍长排序?
//我用这样偷懒的办法写了之后最后一个测试点却是答案错误，好难过，这是哪里有点问题？
//然后我没法，还是改成了和别人答案一样的将初始序列一步步归并排序后和中间序列比较的办法

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vi, vimid;

	int num;
	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		vi.push_back(num);
	}

	for (int i = 0; i != n; ++i)
	{
		cin >> num;
		vimid.push_back(num);
	}

	int max = 0;
	int j1 = 0;
	for (int i = 0; i != n; ++i)
	{
		if (vimid[i] < max)
		{
			j1 = i;
			break;
		}
		else
			max = vimid[i];
	}

	int k = j1;
	for (; k != n; ++k)
		if (vimid[k] != vi[k])
			break;
	if (k == n)
	{
		cout << "Insertion Sort" << endl;
		sort(vimid.begin(), vimid.begin() + j1 + 1);

		cout << vimid[0];
		for (int i = 1; i != n; ++i)
			cout << " " << vimid[i];
	}
	else
	{
		cout << "Merge Sort" << endl;

		//int beg = 0, end = 2 * j1, j2 = 2 * j1;
		//while (end <= n)
		//{
		//	sort(vimid.begin() + beg, vimid.begin() + end);
		//	beg += j2;
		//	end += j2;
		//}
		//sort(vimid.begin() + beg, vimid.end());

		//这里不知道为什么我直接将已经升序的两倍排序当输出结果最后一个测试点就会错
		//一定要一步步两倍的排序才行
		//暂时没想到哪里会有一些问题

		//归并第一次每两个排序
		//第二次每4个排序
		//以此类推，注意最后没能整除的部分也排序一下
		int step = 2;
		while (vimid != vi)
		{
			int beg = 0, end = step;
			while (end <= n)
			{
				sort(vi.begin() + beg, vi.begin() + end);
				beg += step;
				end += step;
			}
			sort(vi.begin() + beg, vi.end());
			step *= 2;
		}

		int b = 0, e = step;
		while (e <= n)
		{
			sort(vi.begin() + b, vi.begin() + e);
			b += step;
			e += step;
		}
		sort(vi.begin() + b, vi.end());

		cout << vi[0];
		for (int i = 1; i != n; ++i)
			cout << " " << vi[i];
	}
}