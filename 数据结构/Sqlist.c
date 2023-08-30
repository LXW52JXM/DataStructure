#include "Sqlist.h"
#include<stdio.h>

//线性线性表初始化
Status InitList_Sq(Sqlist *L) {
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);//存储分配失败
	L->length = 0;				//空表长度为0(元素存在的数量)
	L->listsize = LIST_INIT_SIZE;//初始化存储元素个数
	return OK;
};

//顺序线性表尾部插入数据
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

//顺序线性表显示所有数据
Status Show_List(Sqlist* L) {
	printf("长度：%d\n", L->listsize);
	printf("存在长度：%d\n", L->length);
	
	for (int i = 0; i < L->length; i++)
	{
		printf("%d   ",L->elem[i]);
	}
	printf("\n");
	return OK;
};

//顺序线性表头部插入数据
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

//顺序线性表从尾部删除数据
Status Pop_Back(Sqlist* L) {
	if (L->length==0)
	{
		printf("顺序表空间已空！不能删除！！\n");
		return ERROR;
	}
	L->length--;
};

//顺序线性表从头部删除数据
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

//顺序线性表指定位置插入数据
Status Insert_Pos(Sqlist* L, ElemType e, int pos) {
	//length+1是为了保证顺序线性表插入数据时是顺序线性表是连续的
	if (pos<1||pos>L->length+1)
	{
		printf("插入数据的位置非法，请重新再试！\n");
		return ERROR;
	}

	//当前存储空间已满，增加分配
	if (L->length==L->listsize)
	{
		ElemType *newbase=(ElemType*)realloc(L->elem,(L->listsize+ LISTINCREMENT)*sizeof(ElemType));
		if (!newbase)//分配失败终止程序
		{
			exit(OVERFLOW);
		}
		L->elem = newbase;//分配新的基址
		L->listsize = L->listsize + LISTINCREMENT;//增加存储容量
	}
	for (int i = L->length; i >=pos; --i)
	{
		L->elem[i] = L->elem[i - 1];//插入位置及之后的元素右移
	}
	L->elem[pos-1] = e;
	L->length++;
	return OK;
}
