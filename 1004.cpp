//1004. �ɼ�����(20)
//
//ʱ������
//400 ms
//�ڴ�����
//65536 kB
//���볤������
//8000 B
//�������
//Standard
//����
//CHEN, Yue

//����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�
//
//�����ʽ��ÿ�������������1��������������ʽΪ
//
//��1�У�������n
//��2�У���1��ѧ�������� ѧ�� �ɼ�
//��3�У���2��ѧ�������� ѧ�� �ɼ�
//... ... ...
//��n + 1�У���n��ѧ�������� ѧ�� �ɼ�
//����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ��������
//���ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
//�����ʽ����ÿ�������������2�У�
//��1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�
//
//����������
//3
//Joe Math990112 89
//Mike CS991301 100
//Mary EE990830 95
//���������
//Mike CS991301
//Joe Math990112

//idea:
//�뷨�Ƚ�ֱ��
//���Ƕ�ȡ��������
//������ĵ�һ��ѧ������Ϊmin��max
//֮���������
//��óɼ���ߺ���͵Ľ��

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//student��¼ÿһ������ĸ�����Ϣ
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
	//���Ƚ��������󶨵���һ��ѧ��
	//֮��ÿ��ѧ����������еĳɼ����Ƚ�
	//sf=student first��� sl=student last���
	//��Ҫ��Ц�ҵ�Ӣ��ˮƽ
	//ֻ����Ϊһ����ʶ������
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