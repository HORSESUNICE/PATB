//1040. 有几个PAT（25）
//
//时间限制
//120 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CAO, Peng

//字符串APPAPT中包含了两个单词“PAT”，其中第一个PAT是第2位(P), 第4位(A), 第6位(T)；第二个PAT是第3位(P), 第4位(A), 第6位(T)。
//
//现给定字符串，问一共可以形成多少个PAT？
//
//输入格式：
//
//输入只有一行，包含一个字符串，长度不超过105，只包含P、A、T三种字母。
//
//输出格式：
//
//在一行中输出给定字符串中包含多少个PAT。由于结果可能比较大，只输出对1000000007取余数的结果。
//
//输入样例：
//APPAPT
//输出样例：
//2

//idea:
//开始我的做法是遍历输入中的P
//然后计算后面的A和T的数量求和来计算
//显然是超时了
//这里用了别人的方法
//首先统计T的个数
//利用A的出现来计算，给定A组成的PAT个数为A前P个数*A后T个数
//一次遍历就可以了

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	long long sum = 0;
	string pat;
	cin >> pat;

	long long p = 0;
	long long t = count(pat.begin(), pat.end(), 'T');
	for (auto it = pat.begin(); it != pat.end(); ++it)
	{
		if (*it == 'P')
			++p;
		else if (*it == 'A')
			sum += p*t;
		else
			--t;
	}

	cout << sum % 1000000007;
}