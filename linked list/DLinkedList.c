#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist)				//리스트 정의
{
	plist->head=(Node*)malloc(sizeof(Node));
	plist->head->next=NULL;
	plist->comp=NULL;
	plist->numOfData=0;
}

void FInsert(List* plist, LData data)			//노드 삽입 (정렬 조건 없을 때)
{
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;

	newNode->next=plist->head->next;		
	plist->head->next=newNode;

	(plist->numOfData)++;
}

void SInsert(List* plist, LData data)			//노드 삽입 (정렬 조건 있을 때)
{
	Node* newNode=(Node*)malloc(sizeof(Node));
	Node* pred=plist->head;
	newNode->data=data;

	while(pred->next!=NULL && plist->comp(data,pred->next->data)!=0)		//더미 노드의 다음 노드가 NULL이 아니고 정렬 조건도 만족시킬 때
	{
		pred=pred->next;
	}

	newNode->next=pred->next;
	pred->next=newNode;

	(plist->numOfData)++;
}

void LInsert(List* plist, LData data)
{
		if(plist->comp==NULL)			//정렬기준이 없을 때
			FInsert(plist,data);
		else
			SInsert(plist,data);		//정렬기준이 있을 때
}

int LFirst(List* plist, LData* pdata)
{
	if(plist->head->next==NULL)
		return FALSE;

	plist->before=plist->head;
	plist->cur=plist->head->next;

	*pdata=plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if(plist->cur->next==NULL)
		return FALSE;

	plist->before=plist->cur;
	plist->cur=plist->cur->next;

	*pdata=plist->cur->data;
	return TRUE;
}
LData LRemove(List* plist)
{
	Node* rpos=plist->cur;
	LData rdata=rpos->data;

	plist->before->next=plist->cur->next;
	plist->cur=plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}

void SetSortRule(List* plist, int(*comp)(LData d1, LData d2))
{
	plist->comp=comp;
}
