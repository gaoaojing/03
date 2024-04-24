//���룺1 2 2 0 0 0 3 2 0 0 4 0 0
//�����1 null 3 null 4 null nul
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
typedef struct Btree
{
	int data;//�������е�����
	struct Btree* lchild;//����
	struct Btree* rchild;//�Һ���
}*T;
void Buildtree(T& t)//����������
{
	int  Binarytree;
	cin >> Binarytree;
	if (Binarytree == 0)//��0��ʾΪ��
	{
		t = NULL;
	}
	else
	{
		t = new Btree;
		t->data = Binarytree;
		Buildtree(t->lchild);
		Buildtree(t->rchild);
	}
}
//�ݹ�
Btree* travel(T& t, int target)//�����������������ɾ������ֵ�ڵ�
{
	
	if (!t)
		return NULL;
	
	t->lchild = travel(t->lchild, target);
	t->rchild = travel(t->rchild, target);
	if (!t->lchild && !t->rchild && t->data == target)
		return NULL;
	return t;
}

void printBtree1(T& t)//��������������������ʣ��Ľڵ�
{
	if (t != NULL)
	{
		cout << t->data << ' ';
		printBtree1(t->lchild);
		printBtree1(t->rchild);
		
	}
	else
		cout << "null  ";
}
void printBtree2(T& t)//��������������������ʣ��Ľڵ�
{
	if (t != NULL)
	{
		printBtree1(t->lchild);
		cout << t->data << ' ';
		printBtree1(t->rchild);

	}
	else
		cout << "null  ";
}
void printBtree3(T& t)//��������������������ʣ��Ľڵ�
{
	if (t != NULL)
	{
		printBtree1(t->lchild);
		printBtree1(t->rchild);
		cout << t->data << ' ';

	}
	else
		cout << "null  ";
}
int main()
{
	cout << "���������빹�ɶ���������ֵ"<<endl;
	cout << "tree=  ";
	T t;
	t = new Btree;
	Buildtree(t);//����������
	cout << "���������ֵ" << endl;
	cout << "target=  ";
	int target;
	int p;
	cin >> target;
	t=travel(t, target);
	cout << "�������������밴0:" << endl;
	cout << "�������������밴1:" << endl;
	cout << "������������밴2:" << endl;
	cout << "�����룻";
	cin >> p;
	switch (p)
	{
	case 0:
		printBtree1(t);
		break;
	case 1:
		printBtree2(t);
		break;
	case 2:
		printBtree3(t);
		break;
	}
	return 0;
}

