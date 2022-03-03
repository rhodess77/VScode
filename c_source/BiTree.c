
#include <iostream>
using namespace std;

//定义二叉树结点
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode , *pBiTNode;

//前序遍历二叉树
void PreOrderTraverse(pBiTNode T)
{
	//树不为空前序遍历二叉树
	if (T == NULL)
		return;
	else
	{
		printf("%c ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}

}

//中序遍历二叉树
void InOrderTraverse(pBiTNode T)
{
	//树不为空前序遍历二叉树
	if (T == NULL)
		return;
	else
	{
		InOrderTraverse(T->lchild);
		printf("%c ", T->data);
		InOrderTraverse(T->rchild);
	}
}

//后序遍历二叉树
void PostOrderTraverse(pBiTNode T)
{
	//树不为空前序遍历二叉树
	if (T == NULL)
		return;
	else
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c ", T->data);
	}
}

//创建二叉树
void CreateBiTree(pBiTNode* ppT)//注意这里传入的是一个二级指针
{
	char ch = 0;
	scanf("%c", &ch);//要利用 # 对二叉树创建进行截止
	if ('#' == ch)
	{
		*ppT = NULL;
	}
	else
	{
		*ppT = (pBiTNode)malloc(sizeof(BiTNode));//申请空间
		//前序递归创建二叉树
        (*ppT)->data = ch;
		CreateBiTree(&(*ppT)->lchild);
		CreateBiTree(&(*ppT)->rchild);
	}

}

int main()
{
	pBiTNode BiTree=NULL;
	CreateBiTree(&BiTree);
	PreOrderTraverse(BiTree);
	printf("\n");
	InOrderTraverse(BiTree);
	printf("\n");
	PostOrderTraverse(BiTree);
	system("pause");
	return 0;
}

