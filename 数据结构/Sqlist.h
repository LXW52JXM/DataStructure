#ifndef HEADER_FILE
#define HEADER_FILE

#define LIST_INIT_SIZE 8 //线性表存储空间的初始化分量
#define LISTINCREMENT 10   //线性表存储空间的分配增量

//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef int ElemType;

//------------线性表动态分配顺序存储结构--------------//
typedef struct {
	ElemType* elem;//存储空间基址
	int length;//当前存在元素的个数
	int listsize;//当前可以分配的元素个数（以sizeof(ElemType)为单位，相当于一共有多少个位置）
}Sqlist;

//顺序线性表初始化方法
Status InitList_Sq(Sqlist *L);
//顺序线性表尾部插入数据
Status Push_Back(Sqlist *L,ElemType e);
//顺序线性表显示所有数据
Status Show_List(Sqlist *L);
//顺序线性表头部插入数据
Status Push_Front(Sqlist *L, ElemType e);
//顺序线性表从尾部删除数据
Status Pop_Back(Sqlist* L);
//顺序线性表从头部删除数据
Status Pop_Front(Sqlist* L);
//顺序线性表指定位置插入数据
Status Insert_Pos(Sqlist* L,ElemType e,int pos);
#endif
