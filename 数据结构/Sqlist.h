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
	int listsize;//��ǰ���Է����Ԫ�ظ�������sizeof(ElemType)Ϊ��λ���൱��һ���ж��ٸ�λ�ã�
}Sqlist;

//˳�����Ա��ʼ������
Status InitList_Sq(Sqlist *L);
//˳�����Ա�β����������
Status Push_Back(Sqlist *L,ElemType e);
//˳�����Ա���ʾ��������
Status Show_List(Sqlist *L);
//˳�����Ա�ͷ����������
Status Push_Front(Sqlist *L, ElemType e);
//˳�����Ա��β��ɾ������
Status Pop_Back(Sqlist* L);
//˳�����Ա��ͷ��ɾ������
Status Pop_Front(Sqlist* L);
//˳�����Ա�ָ��λ�ò�������
Status Insert_Pos(Sqlist* L,ElemType e,int pos);
#endif
