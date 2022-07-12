#include<iostream>
using namespace std;
#include<string>
#define max 1000

struct person
{
	string name;
	string sex;
	int age;
	int contact;
	string address;
};
struct addressbooks
{
	person st[max];
	int m_size;
};
void manu()
{
	cout << "输入 1 添加联系人" << '\n' <<
		"输入 2 显示联系人" << '\n' <<
		"输入 3 删除联系人" << '\n' <<
		"输入 4 查找联系人" << '\n' <<
		"输入 5 修改联系人" << '\n' <<
		"输入 6 清空联系人" << '\n' <<
		"输入 7 退出通讯录" << '\n';
}
void func01(addressbooks *p)//添加联系人
{
	if (p->m_size >= max)
	{
		cout << "已满无法添加。";
	}
	else
	{
	cout << "输入联系人姓名："; cin >> p->st[p->m_size].name;
	cout << "输入联系人性别：";
	cout << "1---男 2---女：";
	int num = 0;
	cin >> num;
	switch (num)
	{
	case 1:
		p->st[p->m_size].sex = "男";
	case 2:
		p->st[p->m_size].sex = "女";
	}
	cout << "输入联系人年龄："; cin >> p->st[p->m_size].age;
	cout << "输入联系人电话："; cin >> p->st[p->m_size].contact;
	cout << "输入联系人地址："; cin >> p->st[p->m_size].address;
	p->m_size++;
	cout << "已添加。" << '\n';
	}
}
void func02(addressbooks* p)//显示联系人
{
	if (p->m_size == 0)
	{
		cout << "联系人为空。"<<'\n';
	}
	else
	{
		for (int i = 0; i < p->m_size; i++)
		{
			cout << "姓名：" << p->st[i].name << '\n'
				<< "性别：" << p->st[i].sex << '\n'
				<< "年龄：" << p->st[i].age << '\n'
				<< "电话：" << p->st[i].contact << '\n'
				<< "地址：" << p->st[i].address << '\n';
		}
	}
}
void func03(addressbooks* p)//删除联系人
{
	string name;
	cout << "输入删除联系人的姓名：";
	cin >> name;
	for (int i = 0; i <p->m_size; i++)
	{
		if (p->st[i].name == name)
		{
			for (int j = i; j < p->m_size - i; j++)
			{
				p->st[j].name = p->st[j + 1].name;
				p->st[j].sex = p->st[j + 1].sex;
				p->st[j].age = p->st[j + 1].age;
				p->st[j].contact = p->st[j + 1].contact;
				p->st[j].address = p->st[j + 1].address;
			}
			p->m_size--;
		}
	}
	cout << "已删除。"<<'\n';
}
void func04(addressbooks* p)//查找联系人
{
	string name;
	cout << "输入需要查找的联系人的姓名：";
	cin >> name;
	for (int i = 0; i < max; i++)
	{
		if (p->st[i].name == name)
		{
			cout << "姓名：" << p->st[i].name << '\n'
				<< "性别：" << p->st[i].sex << '\n'
				<< "年龄：" << p->st[i].age << '\n'
				<< "电话：" << p->st[i].contact << '\n'
				<< "地址：" << p->st[i].address << '\n';
			break;
		}
	}
}
void func05(addressbooks* p)//修改联系人
{
	string name;
	cout << "输入需要修改的联系人的姓名：";
	cin >> name;
	for (int i = 0; i < max; i++)
	{
		if (p->st[i].name == name)
		{
			int num;
			cout << "输入1修改姓名" << '\n'
				<< "输入2修改性别" << '\n'
				<< "输入3修改年龄" << '\n'
				<< "输入4修改联系方式" << '\n'
				<< "输入5修改地址" << '\n';
			cin >> num;
			if (num == 1) { cout << "输入姓名："; cin >> p->st[i].name; }
			else if (num == 2) { cout << "输入性别："; cin >> p->st[i].sex; }
			else if (num == 3) { cout << "输入年龄："; cin >> p->st[i].age; }
			else if (num == 4) { cout << "输入电弧："; cin >> p->st[i].contact; }
			else if (num == 5) { cout << "输入地址："; cin >> p->st[i].address; }
			break;
		}
	}
	cout << "修改完成。"<<'\n';
}
void func06(addressbooks* p)//清空联系人
{
	//for (int i = 0; i < p->m_size; i++)
	//{
	//	p->st[i].name = "";
	//	p->st[i].sex = "";
	//	p->st[i].age = NULL;
	//	p->st[i].contact = NULL;
	//	p->st[i].address = "";
	//}
	p->m_size = 0;
	cout << "已清空"<<'\n';
}
int main()
{
	addressbooks book;
	book.m_size = 0;
	int num=0;
	
	while (true)
	{
		manu();
		cin >> num;
		switch (num)
		{
		case 1:
			func01(&book); break;
		case 2:
			func02(&book); break;
		case 3:
			func03(&book); break;
		case 4:
			func04(&book); break;
		case 5:
			func05(&book); break;
		case 6:
			func06(&book); break;
		case 7:
			cout << "你已退出通讯录 " << '\n'; return 0;
		}
	}
	system("pause");
}