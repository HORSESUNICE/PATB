//1015. 德才论 (25)
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
//CHEN, Li

//宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：
//“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。
//凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”
//
//现给出一批考生的德才分数，请根据司马光的理论给出录取排名。
//
//输入格式：
//
//输入第1行给出3个正整数，分别为：N（<=105），即考生总数；
//L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；
//H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
//才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
//德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
//其他达到最低线L的考生也按总分排序，但排在第三类考生之后。
//
//随后N行，每行给出一位考生的信息，
//包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。
//
//输出格式：
//
//输出第1行首先给出达到最低分数线的考生人数M，
//随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。
//当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
//
//输入样例：
//14 60 80
//10000001 64 90
//10000002 90 60
//10000011 85 80
//10000003 85 80
//10000004 80 85
//10000005 82 77
//10000006 83 76
//10000007 90 78
//10000008 75 79
//10000009 59 90
//10000010 88 45
//10000012 80 100
//10000013 90 99
//10000014 66 60
//输出样例：
//12
//10000013 90 99
//10000012 80 100
//10000003 85 80
//10000011 85 80
//10000004 80 85
//10000007 90 78
//10000006 83 76
//10000005 82 77
//10000002 90 60
//10000014 66 60
//10000008 75 79
//10000001 64 90

//idea:
//这题的题目实在是长了一些吧
//按要求区分考试之后分类排序最后输出
//但这题真的太坑了
//有测试数据是有很多考试数据的
//输出用cout就炸会超时，我也是看了别人答案才知道一定要改成printf
//printf的格式化输出还是比cout流的输出快那么些的

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

//用于记录考生的数据
struct st
{
	int id;
	int d;
	int c;
};

int main()
{
	int N, L, H;
	cin >> N >> L >> H;

	vector<st> ks1, ks2, ks3, ks4;

	for (int i = 0; i != N; ++i)
	{
		st student;
		cin >> student.id >> student.d >> student.c;
		//对考虑录取的考生按要求分类
		if (student.d >= L&&student.c >= L)
		{
			if (student.d >= H&&student.c >= H)
				ks1.push_back(student);
			else if (student.d >= H&&student.c < H)
				ks2.push_back(student);
			else if (student.d < H&&student.c < H && (student.d >= student.c))
				ks3.push_back(student);
			else
				ks4.push_back(student);
		}
	}

	//这个lambda用于排序
	//写这个的时候C++Primer刚看到这部分内容就用了一下
	//注意lambda最后一定要加一个;
	//可以改为一般的函数
	auto order1 = [](const st &st1, const st &st2)
	{
		if ((st2.d + st2.c) < (st1.d + st1.c))
		{
			return true;
		}
		else if (((st2.d + st2.c) == (st1.d + st1.c)) && (st2.d < st1.d))
		{
			return true;
		}
		else if (((st2.d + st2.c) == (st1.d + st1.c)) && (st2.d == st1.d) && (st2.id > st1.id))
		{
			return true;
		}
		else
			return false;
	};

	sort(ks1.begin(), ks1.end(), order1 );
	sort(ks2.begin(), ks2.end(), order1 );
	sort(ks3.begin(), ks3.end(), order1 );
	sort(ks4.begin(), ks4.end(), order1 );

	cout << ks1.size() + ks2.size() + ks3.size() + ks4.size() << endl;
	auto it = ks1.begin();
	while (it != ks1.end())
	{
		printf("%d %d %d\n", it->id, it->d, it->c);
		++it;
	}
	it = ks2.begin();
	while (it != ks2.end())
	{
		printf("%d %d %d\n", it->id, it->d, it->c);
		++it;
	}
	it = ks3.begin();
	while (it != ks3.end())
	{
		printf("%d %d %d\n", it->id, it->d, it->c);
		++it;
	}
	it = ks4.begin();
	while (it != ks4.end())
	{
		printf("%d %d %d\n", it->id, it->d, it->c);
		++it;
	}
}
