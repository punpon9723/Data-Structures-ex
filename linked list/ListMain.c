#include <stdio.h>
#include "ArrayList.h"
#include "ArrayList.c"
/*void ListInit(List* plist)
{
	(plist->numOfData)=0;
	(plist->curPosition)=-1;
}
void LInsert(List* plist, LData data)
{
	if(plist->numOfData>=LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData]=data;
	(plist->numOfData)++;
}
int LFirst(List* plist,LData* pdata)
{
	if(plist->numOfData==0)
		return FALSE;

	(plist->curPosition)=0;
	*pdata=plist->arr[0];
	return TRUE;
}
int LNext(List *plist, LData* pdata)
{
	if(plist->curPosition>=(plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;
	*pdata=plist->arr[plist->curPosition];
	return TRUE;
}
LData LRemove(List *plist)
{
	int rpos=plist->curPosition;
	int num=plist->numOfData;
	int i;
	LData rdata=plist->arr[rpos];

	for(i=rpos;i<num-1;i++)
		plist->arr[i]=plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}
int LCount(List *plist)
{
	return plist->numOfData;
}
*/
int main(void)
{
	List list;
	int data;
	ListInit(&list);
	int i;
	for(i=0;i<9;i++)
	{
		LInsert(&list,i+1);
	}
	int sum=0;
	
	if(LFirst(&list,&data))
	{
		sum+=data;
		while(LNext(&list,&data))
			sum+=data;
	}
	printf("%d\n",sum);

	if(LFirst(&list,&data))
	{
		if(data%2==0 || data%3==0)
			LRemove(&list);

		while(LNext(&list,&data))
		{
			if(data%2==0 || data%3==0)
				LRemove(&list);
		}
	}

	if(LFirst(&list,&data))
	{
		printf("%d ",data);

		while(LNext(&list,&data))
		{
			printf("%d ",data);
		}
	}
	printf("\n");
	return 0;
}
