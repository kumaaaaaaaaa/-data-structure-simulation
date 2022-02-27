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


typedef LinkedList List; // LinkedList를 List로 간단히 지칭

void ListInit(List * plist); // 초기화
void LInsert(List * plist, LData data); // 추가

int LFirst(List * plist, LData * pdata); 
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist); // 제거
int LCount(List * plist); // 데이터의 개수

#endif