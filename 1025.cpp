//1025. 反转链表(25)
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

//给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。
//例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；
//如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。
//
//输入格式：
//
//每个输入包含1个测试用例。
//每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、
//以及正整数K(<= N)，即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用 - 1表示。
//
//接下来有N行，每行格式为：
//
//Address Data Next
//
//其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。
//
//输出格式：
//
//对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
//
//输入样例：
//00100 6 4
//00000 4 99999
//00100 1 12309
//68237 6 - 1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//输出样例：
//00000 4 33218
//33218 3 12309
//12309 2 00100
//00100 1 99999
//99999 5 68237
//68237 6 - 1

//idea:
//首先还是要明白题目的意思
//反转链表不是说只将地址反转就可以了
//因为反转，会导致节点的next的地址也一起改变
//这题还有一点要注意的
//我第一次做的时候是将地址输入到vector后按要求反转再输出的
//这样会超时
//看了别人的答案之后一定要改成利用数组才解决了超时的问题

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	int node[100000] = { 0 };
	int data[100000] = { 0 };

	//ord是节点输入时的顺序
	//res是反转链表后的顺序
	vector<int> ord;
	vector<int> res;

	int first, n, k;

	cin >> first >> n >> k;

	int add, da, next;

	for (int i = 0; i != n; ++i)
	{
		cin >> add >> da >> next;
		node[add] = next;
		data[add] = da;
	}

	while (first != -1)
	{
		ord.push_back(first);
		first = node[first];
	}

	//输入的节点有可能不在链表中
	//这也太坑了，一个测试点是这样的
	n = ord.size();

	for (int i = 0; i != n / k*k; ++i)
	{
		int j = i / k*k + k - 1 - i%k;
		res.push_back(ord[j]);
	}

	for (int i = n / k*k; i != n; ++i)
		res.push_back(ord[i]);

	for(int i=0;i!=n-1;++i)
		printf("%05d %d %05d\n", res[i], data[res[i]], res[i+1]);
	printf("%05d %d %d\n", res[n-1], data[res[n-1]], -1);
}