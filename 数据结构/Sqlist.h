#ifndef HEADER_FILE
#define HEADER_FILE

#define LIST_INIT_SIZE 8 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10   //���Ա�洢�ռ�ķ�������

//�������״̬����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef int ElemType;

//------------���Ա�̬����˳��洢�ṹ--------------//
typedef struct {
	ElemType* elem;//�洢�ռ��ַ
	int length;//��ǰ����Ԫ�صĸ���
	int listsize;//��ǰ�����Ԫ�ظ�������sizeof(ElemType)Ϊ��λ��
}Sqlist;

//˳����ʼ������
Status InitList_Sq(Sqlist *L);
//˳���β����������
Status Push_Back(Sqlist *L,ElemType e);
//˳�����ʾ��������
Status Show_List(Sqlist *L);
//˳���ͷ����������
Status Push_Front(Sqlist *L, ElemType e);
//˳����β��ɾ������
Status Pop_Back(Sqlist* L);
//˳����ͷ��ɾ������
Status Pop_Front(Sqlist* L);
#endif
