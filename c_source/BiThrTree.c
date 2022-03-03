#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


//线索标志枚举类型
enum PointerTag
{
	Link = 0, Thread
};

//线索二叉树结点
typedef struct BiThrNode
{
	char data;
	enum PointerTag LTag;
	enum PointerTag RTag;
	struct BiThrNode* lchild;
	struct BiThrNode* rchild;
}BiThrNode, * pBiThrNode;

//全局变量pre始终指向前驱结点
pBiThrNode pre = NULL;

//前序创建二叉树（未线索化）
void CreateBiThrTree(pBiThrNode* T)
{
	char ch = 0;
	scanf("%c", &ch);

	if (ch == '#')//如果为 # 则将该结点设置为空
		*T = NULL;
	else
	{
		*T = (pBiThrNode)malloc(sizeof(BiThrNode));//申请空间
		(*T)->data = ch;		//录入结点数据
		(*T)->LTag = Link;		//初始化标志
		(*T)->RTag = Link;		//初始化标志
		CreateBiThrTree(&(*T)->lchild);//递归左子树
		CreateBiThrTree(&(*T)->rchild);//递归右子树
	}
}

//前序遍历二叉树
void PreOrderTraverse(pBiThrNode p)
{
	if (!p)
	{
		return;
	}
	else
	{
		printf("%c ", p->data);
		PreOrderTraverse(p->lchild);
		PreOrderTraverse(p->rchild);
	}
}

//中序遍历二叉树
void InOrderTraverse(pBiThrNode p)
{
	if (!p)
	{
		return;
	}
	else
	{
		InOrderTraverse(p->lchild);
		printf("%c ", p->data);
		InOrderTraverse(p->rchild);
	}
}

//中序线索化二叉树
void InThreading(pBiThrNode p)
{

	if (p)
	{
		InThreading(p->lchild);//递归左子树线索化

		//线索化操作
		if (!p->lchild)
		{//若其没有左孩子，则将左孩子指针指向其前驱结点
			p->LTag = Thread;
			p->lchild = pre;
		}

		if (pre)
		{
			if (!pre->rchild)
			{
				pre->RTag = Thread;
				pre->rchild = p;
			}
		}
		pre = p;//让pre跟上p

		InThreading(p->rchild);//递归右子树线索化
	}
}

//建立二叉树双向链表
pBiThrNode InitTreeLinkList(pBiThrNode T)
{
	pBiThrNode p = T;
	//为头结点申请空间
	pBiThrNode head = (pBiThrNode)malloc(sizeof(BiThrNode));
	head->lchild = T;//头结点的左孩子指针指向二叉树的根结点

	//前序二叉链表的首结点左孩子指针指向头结点
	while (p->lchild)
	{
		p = p->lchild;
	}
	p->lchild = head;

	//前序二叉链表的最后一个结点右孩纸指针指向头结点
	//且头结点的右孩子指针指向最后一个结点
	p = T;
	while (p->rchild)
		p = p->rchild;
	head->rchild = p;
	p->rchild = head;

	return head;//返回线索二叉树头指针
}

//中序遍历线索二叉树
void InOrderTraverse_Thr(pBiThrNode head)
{
	pBiThrNode p = head->lchild;//p指向线索二叉树的根结点

	while (p != head)//当p回到头结点，代表遍历完毕
	{
		//先根据PointerTag找到中序首结点
		while (p->LTag == Link)
			p = p->lchild;

		//对结点的遍历操作
		printf("%c ", p->data);

		//如果结点指向后继的线索，则直接找到后继
		while (p->RTag == Thread && p->rchild != head)
		{
			p = p->rchild;
			
			//对结点进行遍历操作
			printf("%c ", p->data);
		}

		//如果没有后继，则进入其右子树
		p = p->rchild;
	}
	printf("\n");
}

int main()
{
	printf("请输入二叉树前序表达式：\n");
	pBiThrNode BiTree = NULL;
	CreateBiThrTree(&BiTree);

	printf("线索化前前序遍历二叉树：\n");
	PreOrderTraverse(BiTree);
	printf("\n");

	printf("线索化前中序遍历二叉树：\n");
	InOrderTraverse(BiTree);
	printf("\n");

	InThreading(BiTree);
	printf("线索化后中序遍历二叉树：\n");
	pBiThrNode BiThrTree = InitTreeLinkList(BiTree);
	InOrderTraverse_Thr(BiThrTree);
	
    system("pause");
	return 0;
}