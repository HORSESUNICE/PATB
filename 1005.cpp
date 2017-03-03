//1005. 继续(3n + 1)猜想(25)
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

//卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
//
//当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。
//例如对n = 3进行验证的时候，我们需要计算3、5、8、4、2、1，
//则当我们对n = 5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，
//因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。
//我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
//
//现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。
//你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
//
//输入格式：每个测试输入包含1个测试用例，
//第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n <= 100)的值，数字间用空格隔开。
//
//输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。
//数字间用1个空格隔开，但一行中最后一个数字后没有空格。
//
//输入样例：
//6
//3 5 6 7 8 11
//输出样例：
//7 6

//idea:
//这题困难在于如何判断两个数之间的覆盖关系
//我的做法暂时比较复杂是这样的：
//首先将第一个数字假定先作为关键数
//将之后的输入进行一一判断
//如果新数字在之前数字的覆盖中，进行下一个数字的判断
//之前数字在新数字的覆盖中则将旧数据用新数字的替换
//数字之间没有覆盖关系则增加新的数字
//最后将要输出的数据逆序排列


#include <iostream>
#include <vector>

using namespace std;

//记录数字及其产生的覆盖
struct core
{
	int n;
	vector<int> fg;
};

//求数字对应的覆盖
core f(int n)
{
	core c;
	c.n = n;
	while (n != 1)
	{
		if (n % 2)
		{
			n = (3 * n + 1) / 2;
			c.fg.push_back(n);
		}
		else
		{
			n /= 2;
			c.fg.push_back(n);
		}
	}
	return c;
}

int main()
{
	//输入数据的总数
	int num;
	cin >> num;
	//记录下输入的所有数字
	vector<int> vi;
	int n;
	for (int i = 0; i != num; ++i)
	{
		cin >> n;
		vi.push_back(n);
	}

	//最后需要输出的数据
	vector<core> ans;
	ans.push_back(f(vi[0]));
	for (int i = 1; i != num; ++i)
	{
		//judge:
		// = 1 当前数字在之前数字的覆盖中
		// = 2 之前数字在当前数字的覆盖中
		// = 0 数字之间没有覆盖关系
		int judge = 0;
		core c = f(vi[i]);
		//it为输出结果的迭代器
		auto it = ans.begin();
		while (it != ans.end())
		{
			auto iti = it->fg.begin();
			while (iti != it->fg.end())
			{
				//当前数字在之前数字的覆盖中
				if (*iti == vi[i])
				{
					judge = 1;
					break;
				}
				//这里递增迭代器不要忘记否则死循环
				++iti;
			}
			//这里不要写iti,重定义
			auto itj = c.fg.begin();
			while (itj != c.fg.end())
			{
				//之前数字在当前数字的覆盖中
				if (*itj == it->n)
				{
					judge = 2;
					*it = c;
					break;
				}
				++itj;
			}
			if (judge == 1 || judge == 2)
				break;
			++it;
		}
		if (judge == 0)
			ans.push_back(c);
	}

	//这里如果会sort可以直接用sort代替
	//写这题的时候我还没学会sort..
	decltype(ans.size()) i = 0, j = 0;
	for(i=0;i!=ans.size();++i)
		for(int j=i+1;j!=ans.size();++j)
			if (ans[i].n < ans[j].n)
			{
				core temp = ans[i];
				ans[i] = ans[j];
				ans[j] = temp;
			}
	for (i = 0; i != ans.size() - 1; ++i)
		cout << ans[i].n << " ";
	cout << ans[i].n;
}