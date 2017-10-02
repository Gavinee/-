#include<iostream>
using namespace std;

#define  TRUE             1
#define  FALSE            0
#define  OK               1
#define  ERROR            0
#define  INFEASIBLE       -1
#define  OVERFLOW         -2

#define LIST_INIT_SIZE    100            //线性表存储空间的初始分配量
#define LISTINCREMENT     10             //线性表存储空间的分配增量

typedef int ElemType;                    


typedef struct {
	ElemType *elem;               //存储空间基址
	int length;                   //当前长度
	int listsize;                 //当前分配的存储容量
}SqList;

int InitList(SqList &L);                                      //初始化线性表
void DestroyList(SqList &L);                                   //销毁线性表
void ClearList(SqList L);                                      //清空线性表
bool ListEmpty(SqList L);                                      //判断线性表是否为空
ElemType ListLength(SqList L);                                 //求线性表的长度
ElemType GetElem(SqList L,int i,ElemType &e);                  //用e返回L中第i个数据元素的值
int LocateElem(SqList L, ElemType e, ElemType compare());      //返回e满足关系compare()的数据元素的位序，若这样的数据元素不存在，则返回值为0
ElemType PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);     //返回pre_e返回它的后继
ElemType NextElem(SqList L,ElemType cur_e,ElemType &next_e);   //返回next_e返回它的前驱
ElemType ListInsert(SqList &L,int i,ElemType e);               //插入新的数据元素e,L的长度加1
ElemType ListDelete(SqList &L,int i,ElemType &e);              //删除L的第i个数据元素，并用e返回其值，L的长度减1
bool ListTraverse(SqList L,bool visit());                      
//依次对L的每个元素元素调用函数visit(),一旦visit()失败,则操作失败

int InitList(SqList &L)
{
	ElemType *elem = new ElemType[LIST_INIT_SIZE];
	if(!L.elem)
	{
		return INFEASIBLE;
	}
	L.length=0;             //当前长度
	L.listsize=LIST_INIT_SIZE;    //当前分配量
        return 0;	
}

void DestroyList(SqList &L)
{
	L.listsize = 0;
	delete L.elem;
}

void ClearList(SqList L)
{
	L.length = 0;
	L.listsize = 0;
}

bool ListEmpty(SqList L)
{

	if (L.length== 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ElemType ListLength(SqList L)
{
	int length;
	length=L.length;
	return length;
}

ElemType GetElem(SqList L, int i, ElemType &e)
{

}


bool compare(int i, int j)
{
	if (i == j)
		return true;
	else
		false;
}

ElemType LocateElem(SqList L, ElemType e, ElemType compare(ElemType First,ElemType Second))
{
	int i;
	if (i<0 ||i >L.length)
	{
		return FALSE;
	}
	else
	{
	return compare(e, L.elem[i]);
	}
}

ElemType PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	int i;
	if (i<0 || i>L.length)
	{
		return FALSE;
        }
	else
	{
		for (i = 0; i < L.length; i++)
		{
			if (i >= 1)
			{
				if (cur_e == L.elem[i])
				{
					pre_e = L.elem[i - 1];
					return pre_e;
				}
			}
			else
			{
				return FALSE;
			}
		}
	}
}

ElemType NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
	int i;
	if (i<0 || i>L.length)
	{
		return FALSE;
	}
	else
	{
		if (i < L.length)
		{
			for (i = 0; i < L.length; i++)
			{
				cur_e = L.elem[i];
				next_e = L.elem[i + 1];
				return next_e;
			}
		}
		else
		{
			return FALSE;
		}
	}
}

ElemType ListInsert(SqList &L, int i, ElemType e)
{
	int j;
	ElemType *elem = new ElemType[LIST_INIT_SIZE + LISTINCREMENT];
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	else
	{
		for (j = L.length; j >= i; j++)
		{
			L.elem[j] = L.elem[j-1];
		}
		L.elem[j]=e;
	}
}


ElemType ListDelete(SqList &L, int i, ElemType &e)
{
	int j = 0;
	if (i < 1 || i < L.length)
	{
		return ERROR;
	}
	else
	{
		for (j = i; j < L.length; j++)
		{
			L.elem[j-1] = L.elem[j];
		}
		L.elem[j - 1] = e;
	}
}

bool ListTraverse(SqList L, bool visit())
{

}