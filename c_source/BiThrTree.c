#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>


//������־ö������
enum PointerTag
{
	Link = 0, Thread
};

//�������������
typedef struct BiThrNode
{
	char data;
	enum PointerTag LTag;
	enum PointerTag RTag;
	struct BiThrNode* lchild;
	struct BiThrNode* rchild;
}BiThrNode, * pBiThrNode;

//ȫ�ֱ���preʼ��ָ��ǰ�����
pBiThrNode pre = NULL;

//ǰ�򴴽���������δ��������
void CreateBiThrTree(pBiThrNode* T)
{
	char ch = 0;
	scanf("%c", &ch);

	if (ch == '#')//���Ϊ # �򽫸ý������Ϊ��
		*T = NULL;
	else
	{
		*T = (pBiThrNode)malloc(sizeof(BiThrNode));//����ռ�
		(*T)->data = ch;		//¼��������
		(*T)->LTag = Link;		//��ʼ����־
		(*T)->RTag = Link;		//��ʼ����־
		CreateBiThrTree(&(*T)->lchild);//�ݹ�������
		CreateBiThrTree(&(*T)->rchild);//�ݹ�������
	}
}

//ǰ�����������
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

//�������������
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

//����������������
void InThreading(pBiThrNode p)
{

	if (p)
	{
		InThreading(p->lchild);//�ݹ�������������

		//����������
		if (!p->lchild)
		{//����û�����ӣ�������ָ��ָ����ǰ�����
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
		pre = p;//��pre����p

		InThreading(p->rchild);//�ݹ�������������
	}
}

//����������˫������
pBiThrNode InitTreeLinkList(pBiThrNode T)
{
	pBiThrNode p = T;
	//Ϊͷ�������ռ�
	pBiThrNode head = (pBiThrNode)malloc(sizeof(BiThrNode));
	head->lchild = T;//ͷ��������ָ��ָ��������ĸ����

	//ǰ�����������׽������ָ��ָ��ͷ���
	while (p->lchild)
	{
		p = p->lchild;
	}
	p->lchild = head;

	//ǰ�������������һ������Һ�ָֽ��ָ��ͷ���
	//��ͷ�����Һ���ָ��ָ�����һ�����
	p = T;
	while (p->rchild)
		p = p->rchild;
	head->rchild = p;
	p->rchild = head;

	return head;//��������������ͷָ��
}

//�����������������
void InOrderTraverse_Thr(pBiThrNode head)
{
	pBiThrNode p = head->lchild;//pָ�������������ĸ����

	while (p != head)//��p�ص�ͷ��㣬����������
	{
		//�ȸ���PointerTag�ҵ������׽��
		while (p->LTag == Link)
			p = p->lchild;

		//�Խ��ı�������
		printf("%c ", p->data);

		//������ָ���̵���������ֱ���ҵ����
		while (p->RTag == Thread && p->rchild != head)
		{
			p = p->rchild;
			
			//�Խ����б�������
			printf("%c ", p->data);
		}

		//���û�к�̣��������������
		p = p->rchild;
	}
	printf("\n");
}

int main()
{
	printf("�����������ǰ����ʽ��\n");
	pBiThrNode BiTree = NULL;
	CreateBiThrTree(&BiTree);

	printf("������ǰǰ�������������\n");
	PreOrderTraverse(BiTree);
	printf("\n");

	printf("������ǰ���������������\n");
	InOrderTraverse(BiTree);
	printf("\n");

	InThreading(BiTree);
	printf("�����������������������\n");
	pBiThrNode BiThrTree = InitTreeLinkList(BiTree);
	InOrderTraverse_Thr(BiThrTree);
	
    system("pause");
	return 0;
}