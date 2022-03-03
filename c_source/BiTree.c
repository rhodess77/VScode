
#include <iostream>
using namespace std;

//������������
typedef struct BiTNode
{
	char data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode , *pBiTNode;

//ǰ�����������
void PreOrderTraverse(pBiTNode T)
{
	//����Ϊ��ǰ�����������
	if (T == NULL)
		return;
	else
	{
		printf("%c ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}

}

//�������������
void InOrderTraverse(pBiTNode T)
{
	//����Ϊ��ǰ�����������
	if (T == NULL)
		return;
	else
	{
		InOrderTraverse(T->lchild);
		printf("%c ", T->data);
		InOrderTraverse(T->rchild);
	}
}

//�������������
void PostOrderTraverse(pBiTNode T)
{
	//����Ϊ��ǰ�����������
	if (T == NULL)
		return;
	else
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c ", T->data);
	}
}

//����������
void CreateBiTree(pBiTNode* ppT)//ע�����ﴫ�����һ������ָ��
{
	char ch = 0;
	scanf("%c", &ch);//Ҫ���� # �Զ������������н�ֹ
	if ('#' == ch)
	{
		*ppT = NULL;
	}
	else
	{
		*ppT = (pBiTNode)malloc(sizeof(BiTNode));//����ռ�
		//ǰ��ݹ鴴��������
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

