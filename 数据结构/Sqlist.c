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
	return OK;
};

//˳�����ʾ��������
Status Show_List(Sqlist* L) {
	for (int i = 0; i < L->length; i++)
	{
		printf("%d   ",L->elem[i]);
	}
	printf("\n");
	return OK;
};

//˳���ͷ����������
Status Push_Front(Sqlist* L, ElemType e) {
	if (L->length==L->listsize)
	{
		printf("˳���ռ����������ܲ��룡\n");
		return ERROR;
	}
	//������Ԫ�������һλ
	for (int i = L->length; i >0; --i)
	{
		//�����int i = L->lengthԪ�ش��ڸ�����1��ʼ��Ԫ���±��0��ʼ
		L->elem[i] = L->elem[i - 1];
	}
	//��ͷ������������
	L->elem[0] = e;
	//Ԫ�ظ�����1
	L->length++;
	return OK;
};

//˳����β��ɾ������
Status Pop_Back(Sqlist* L) {
	if (L->length==0)
	{
		printf("˳���ռ��ѿգ�����ɾ������\n");
		return ERROR;
	}
	L->length--;
};

//˳����ͷ��ɾ������
Status Pop_Front(Sqlist* L) {
	if (L->length==0)
	{
		printf("˳���ռ��ѿգ�����ɾ������\n");
		return ERROR;
	}
	//����Ԫ����ǰ�ƶ�һλ���ѵ�ǰһλλ��Ԫ����һ��������ɾ��ͷԪ��Ŀ��
	for (int i = 0; i < L->length-1; i++)
	{
		L->elem[i] = L->elem[i + 1];
	}
	L->length--;
	return OK;
}
