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
	cout << "���� 1 �����ϵ��" << '\n' <<
		"���� 2 ��ʾ��ϵ��" << '\n' <<
		"���� 3 ɾ����ϵ��" << '\n' <<
		"���� 4 ������ϵ��" << '\n' <<
		"���� 5 �޸���ϵ��" << '\n' <<
		"���� 6 �����ϵ��" << '\n' <<
		"���� 7 �˳�ͨѶ¼" << '\n';
}
void func01(addressbooks *p)//�����ϵ��
{
	if (p->m_size >= max)
	{
		cout << "�����޷���ӡ�";
	}
	else
	{
	cout << "������ϵ��������"; cin >> p->st[p->m_size].name;
	cout << "������ϵ���Ա�";
	cout << "1---�� 2---Ů��";
	int num = 0;
	cin >> num;
	switch (num)
	{
	case 1:
		p->st[p->m_size].sex = "��";
	case 2:
		p->st[p->m_size].sex = "Ů";
	}
	cout << "������ϵ�����䣺"; cin >> p->st[p->m_size].age;
	cout << "������ϵ�˵绰��"; cin >> p->st[p->m_size].contact;
	cout << "������ϵ�˵�ַ��"; cin >> p->st[p->m_size].address;
	p->m_size++;
	cout << "����ӡ�" << '\n';
	}
}
void func02(addressbooks* p)//��ʾ��ϵ��
{
	if (p->m_size == 0)
	{
		cout << "��ϵ��Ϊ�ա�"<<'\n';
	}
	else
	{
		for (int i = 0; i < p->m_size; i++)
		{
			cout << "������" << p->st[i].name << '\n'
				<< "�Ա�" << p->st[i].sex << '\n'
				<< "���䣺" << p->st[i].age << '\n'
				<< "�绰��" << p->st[i].contact << '\n'
				<< "��ַ��" << p->st[i].address << '\n';
		}
	}
}
void func03(addressbooks* p)//ɾ����ϵ��
{
	string name;
	cout << "����ɾ����ϵ�˵�������";
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
	cout << "��ɾ����"<<'\n';
}
void func04(addressbooks* p)//������ϵ��
{
	string name;
	cout << "������Ҫ���ҵ���ϵ�˵�������";
	cin >> name;
	for (int i = 0; i < max; i++)
	{
		if (p->st[i].name == name)
		{
			cout << "������" << p->st[i].name << '\n'
				<< "�Ա�" << p->st[i].sex << '\n'
				<< "���䣺" << p->st[i].age << '\n'
				<< "�绰��" << p->st[i].contact << '\n'
				<< "��ַ��" << p->st[i].address << '\n';
			break;
		}
	}
}
void func05(addressbooks* p)//�޸���ϵ��
{
	string name;
	cout << "������Ҫ�޸ĵ���ϵ�˵�������";
	cin >> name;
	for (int i = 0; i < max; i++)
	{
		if (p->st[i].name == name)
		{
			int num;
			cout << "����1�޸�����" << '\n'
				<< "����2�޸��Ա�" << '\n'
				<< "����3�޸�����" << '\n'
				<< "����4�޸���ϵ��ʽ" << '\n'
				<< "����5�޸ĵ�ַ" << '\n';
			cin >> num;
			if (num == 1) { cout << "����������"; cin >> p->st[i].name; }
			else if (num == 2) { cout << "�����Ա�"; cin >> p->st[i].sex; }
			else if (num == 3) { cout << "�������䣺"; cin >> p->st[i].age; }
			else if (num == 4) { cout << "����绡��"; cin >> p->st[i].contact; }
			else if (num == 5) { cout << "�����ַ��"; cin >> p->st[i].address; }
			break;
		}
	}
	cout << "�޸���ɡ�"<<'\n';
}
void func06(addressbooks* p)//�����ϵ��
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
	cout << "�����"<<'\n';
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
			cout << "�����˳�ͨѶ¼ " << '\n'; return 0;
		}
	}
	system("pause");
}