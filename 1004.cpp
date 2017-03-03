//1004. 成绩排名(20)
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

//读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
//
//输入格式：每个测试输入包含1个测试用例，格式为
//
//第1行：正整数n
//第2行：第1个学生的姓名 学号 成绩
//第3行：第2个学生的姓名 学号 成绩
//... ... ...
//第n + 1行：第n个学生的姓名 学号 成绩
//其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，
//这里保证在一组测试用例中没有两个学生的成绩是相同的。
//输出格式：对每个测试用例输出2行，
//第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
//
//输入样例：
//3
//Joe Math990112 89
//Mike CS991301 100
//Mary EE990830 95
//输出样例：
//Mike CS991301
//Joe Math990112

//idea:
//想法比较直接
//就是读取所有输入
//将读入的第一个学生先作为min和max
//之后遍历输入
//获得成绩最高和最低的结果

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//student记录每一行输入的各种信息
struct student
{
	string name;
	string id;
	int grade;
};

int main()
{
	int n;
	vector<student> st;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		student student;
		cin >> student.name >> student.id >> student.grade;
		st.push_back(student);
	}
	//首先将迭代器绑定到第一个学生
	//之后将每个学生与迭代器中的成绩做比较
	//sf=student first最佳 sl=student last最差
	//不要嘲笑我的英语水平
	//只是作为一个标识符而已
	auto it = st.begin(), sf = st.begin(), sl = st.begin();
	while (it != st.end())
	{
		if (it->grade < sl->grade)
			sl = it;
		if (it->grade > sf->grade)
			sf = it;

		++it;
	}
	cout << sf->name << " " << sf->id << endl;
	cout << sl->name << " " << sl->id;
}