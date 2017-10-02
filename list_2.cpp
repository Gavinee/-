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
typedef int Status;                     //Status是函数的类型，其值是函数状态代码




typedef struct {
	ElemType *elem;               //存储空间基址
	int length;                   //当前长度
	int listsize;                 //当前分配的存储容量
}SqList;



Status InitList(SqList &L);                                      //初始化线性表
void DestroyList(SqList &L);                                   //销毁线性表
void ClearList(SqList L);                                      //清空线性表
bool ListEmpty(SqList L);                                      //判断线性表是否为空
Status ListLength(SqList L);                                 //求线性表的长度
Status GetElem(SqList L,int i,ElemType &e);                  //用e返回L中第i个数据元素的值
Status LocateElem(SqList L, ElemType e, ElemType compare());      //返回e满足关系compare()的数据元素的位序，若这样的数据元素不存在，则返回值为0
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);     //返回pre_e返回它的后继
Status NextElem(SqList L,ElemType cur_e,ElemType &next_e);   //返回next_e返回它的前驱
Status ListInsert(SqList &L,int i,ElemType e);               //插入新的数据元素e,L的长度加1
Status ListDelete(SqList &L,int i,ElemType &e);              //删除L的第i个数据元素，并用e返回其值，L的长度减1
void ListTraverse(SqList L,void visit(int i));                      //遍历线性表(线性表中元素都访问一次，且只访问一次)
//依次对L的每个元素元素调用函数visit(),一旦visit()失败,则操作失败

Status InitList(SqList &L)
{
	L.listsize=LIST_INIT_SIZE;    //当前分配量
	L.length=0;             //当前长度
	ElemType *elem = new ElemType[LIST_INIT_SIZE];
	if(!L.elem)
	{
		cout<<"分配空间失败";
		return INFEASIBLE;
	}
        return 0;	
}

void DestroyList(SqList &L)
{
	L.listsize = 0;
	L.length = 0;
	delete L.elem;
}

void ClearList(SqList L)
{
	L.length = 0;
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

Status ListLength(SqList L)
{
	int length;
	length=L.length;
	return length;
}

Status GetElem(SqList L, int i, ElemType &e)        
{
	if(i<1||i>L.length)
	{
		cout<<"数组空间长度溢出";
		return OVERFLOW;
	}
	else
	{       
		e=L.elem[i-1];
		return e;
	}
}


bool compare(int i, int j)
{
	if (i == j)
		return true;
	else
		false;
}

Status LocateElem(SqList L, ElemType e, bool compare(ElemType First,ElemType Second))
{
	int i;
	if (i<0 ||i >L.length)
	{
		cout<<"数组空间长度溢出";
		return OVERFLOW;
	}
	else
	{
	     if(compare(e, L.elem[i]))
	     {
		     cout<<"返回第i个元素值";
		     return i;
	     }
	     else
	     {
		     cout<<"数组中没有匹配的值";
		     return INFEASIBLE;
	     }
	}
}

Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
	int i;
	if (i<0 || i>L.length)
	{
		cout<<"数组空间长度溢出";
		return OVERFLOW;
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
				cout<<"没有前驱";
				return INFEASIBLE;
			}
		}
	}
}

Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
	int i;
	if (i<0 || i>L.length)
	{
		cout<<"数组空间长度溢出";
		return OVERFLOW;
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
			cout<<"没有后继";
			return INFEASIBLE;
		}
	}
}

Status ListInsert(SqList &L, int i, ElemType e)
{
	int j;
	if(L.length==L.LIST_INIT_SIZE)
	{
		ElemType *elem = new ElemType[LIST_INIT_SIZE + LISTINCREMENT];
		if(L.length==NULL)        //检查分配是否相同
			return FALSE;
		L.listsize+=LISTINCREMENT;
	}
	if (i<1 || i>L.length)
	{
		cout<<"数组空间长度溢出";
		return OVERFLOW;
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


Status ListDelete(SqList &L, int i, ElemType &e)
{
	int j = 0;
	if (i < 1 || i > L.length)
	{
		cout<<"数组空间长度溢出";
		return OVERFLOW;
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



void visit(int i)
{
	cout<<i;
}

void ListTraverse(SqList L, void visit(int i))
{
	for(int j=0;j<L.length;j++)
	{
		visit(L.elem[j]);
	}
}
