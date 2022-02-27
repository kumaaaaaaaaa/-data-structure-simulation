#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
} LinkedList;


typedef LinkedList List; // LinkedList�� List�� ������ ��Ī

void ListInit(List * plist); // �ʱ�ȭ
void LInsert(List * plist, LData data); // �߰�

int LFirst(List * plist, LData * pdata); 
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist); // ����
int LCount(List * plist); // �������� ����

#endif