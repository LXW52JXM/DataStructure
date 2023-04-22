#include "Sqlist.h"
#include<stdio.h>

//线性表初始化
Status InitList_Sq(Sqlist *L) {
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);//存储分配失败
	L->length = 0;				//空表长度为0(元素存在的数量)
	L->listsize = LIST_INIT_SIZE;//初始化存储元素个数
	return OK;
};

//顺序表尾部插入数据
Status Push_Back(Sqlist* L, ElemType e) {
	//判断顺序表空间是否已满
	if (L->length==L->listsize)
	{
		printf("顺序表空间已满！不能插入！\n");
		return ERROR;
	}
	L->elem[L->length] = e;
	L->length++;
};

//顺序表显示所有数据
Status Show_List(Sqlist* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d   ",L->elem[i]);
	}
	printf("\n");
};
