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
	return OK;
};

//顺序表显示所有数据
Status Show_List(Sqlist* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d   ",L->elem[i]);
	}
	printf("\n");
	return OK;
};

//顺序表头部插入数据
Status Push_Front(Sqlist* L, ElemType e) {
	if (L->length==L->listsize)
	{
		printf("顺序表空间已满！不能插入！\n");
		return ERROR;
	}
	//把所有元素向后移一位
	for (int i = L->length; i >0; --i)
	{
		//这里的int i = L->length元素存在个数从1开始，元素下标从0开始
		L->elem[i] = L->elem[i - 1];
	}
	//在头部插入新数据
	L->elem[0] = e;
	//元素个数加1
	L->length++;
	return OK;
};

//顺序表从尾部删除数据
Status Pop_Back(Sqlist* L) {
	if (L->length==0)
	{
		printf("顺序表空间已空！不能删除！！\n");
		return ERROR;
	}
	L->length--;
};

//顺序表从头部删除数据
Status Pop_Front(Sqlist* L) {
	if (L->length==0)
	{
		printf("顺序表空间已空！不能删除！！\n");
		return ERROR;
	}
	//所有元素向前移动一位，把第前一位位置元素逐一覆盖已起到删除头元素目的
	for (int i = 0; i < L->length-1; i++)
	{
		L->elem[i] = L->elem[i + 1];
	}
	L->length--;
	return OK;
}
