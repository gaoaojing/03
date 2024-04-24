//输入：1 2 2 0 0 0 3 2 0 0 4 0 0
//输出：1 null 3 null 4 null nul
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
typedef struct Btree
{
	int data;//二叉树中的数据
	struct Btree* lchild;//左孩子
	struct Btree* rchild;//右孩子
}*T;
void Buildtree(T& t)//建立二叉树
{
	int  Binarytree;
	cin >> Binarytree;
	if (Binarytree == 0)//用0表示为空
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
//递归
Btree* travel(T& t, int target)//后序遍历二叉树并且删除给定值节点
{
	
	if (!t)
		return NULL;
	
	t->lchild = travel(t->lchild, target);
	t->rchild = travel(t->rchild, target);
	if (!t->lchild && !t->rchild && t->data == target)
		return NULL;
	return t;
}

void printBtree1(T& t)//先序遍历并且输出二叉树剩余的节点
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
void printBtree2(T& t)//中序遍历并且输出二叉树剩余的节点
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
void printBtree3(T& t)//后序遍历并且输出二叉树剩余的节点
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
	cout << "请先序输入构成二叉树的数值"<<endl;
	cout << "tree=  ";
	T t;
	t = new Btree;
	Buildtree(t);//创建二叉树
	cout << "请输入给定值" << endl;
	cout << "target=  ";
	int target;
	int p;
	cin >> target;
	t=travel(t, target);
	cout << "如果想先序输出请按0:" << endl;
	cout << "如果想中序输出请按1:" << endl;
	cout << "如果想后序输出请按2:" << endl;
	cout << "请输入；";
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

