#include "Sqlist.h"
#include<stdio.h>

//���Ա��ʼ��
Status InitList_Sq(Sqlist *L) {
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);//�洢����ʧ��
	L->length = 0;				//�ձ���Ϊ0(Ԫ�ش��ڵ�����)
	L->listsize = LIST_INIT_SIZE;//��ʼ���洢Ԫ�ظ���
	return OK;
};

//˳���β����������
Status Push_Back(Sqlist* L, ElemType e) {
	//�ж�˳���ռ��Ƿ�����
	if (L->length==L->listsize)
	{
		printf("˳���ռ����������ܲ��룡\n");
		return ERROR;
	}
	L->elem[L->length] = e;
	L->length++;
};

//˳�����ʾ��������
Status Show_List(Sqlist* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d   ",L->elem[i]);
	}
	printf("\n");
};
