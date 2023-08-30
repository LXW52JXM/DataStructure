#define _CRT_SECURE_NO_WARNINGS
#include"SqList.h"
#include<stdio.h>

int main() {
	Sqlist mylist;
	//顺序表初始化
	InitList_Sq(&mylist);
	//进行输入操作的元素
	ElemType Item;
	//数据要插入的位置
	int pos;

	int select = 1;
	while (select)
	{
		printf("*******************************************************\n");
		printf("**【1】顺序表尾部插入数据    【2】顺序表头部插入数据***\n");
		printf("**【3】查看顺序表数据        【4】顺序表从尾部删除数据*\n");
		printf("**【5】顺序表从头部删除数据  【6】顺序表按位置插入数据*\n");
		printf("**【7】查找顺序表的数据      【8】顺序表数据长度      *\n");
		printf("**【9】顺序表按位置删除数据  【10】顺序表按值删除数据 *\n");
		printf("**【11】顺序表排序           【12】顺序表逆序         *\n");
		printf("**【13】顺序表清除           【14】顺序表销毁         *\n");
		printf("**【0】退出                                           *\n");
		printf("*******************************************************\n");
		printf("请选择:》");
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			printf("退出成功！");
			break;
		case 1:
			printf("顺序表尾部插入数据(-1退出)：");
			while (scanf("%d", &Item),Item!=-1)
			{
				Push_Back(&mylist, Item);
			}
			break;
		case 2:
			printf("顺序表头部插入数据(-1退出)：");
			while (scanf("%d",&Item),Item!=-1)
			{
				Push_Front(&mylist,Item);
			}
			break;
		case 3:
			printf("查看顺序表数据：");
			Show_List(&mylist);
			break;
		case 4:
			printf("顺序表从尾部删除数据(-1退出)：");
			Pop_Back(&mylist);
			break;
		case 5:
			printf("顺序表从头部删除数据(-1退出)：");
			Pop_Front(&mylist);
			break;
		case 6:			
			printf("请输入要插入的数据：");
			scanf("%d",&Item);
			printf("请输入要插入的位置：");
			scanf("%d",&pos);
			Insert_Pos(&mylist, Item, pos);
			break;
		default:
			break;
		}
	}
	
};
