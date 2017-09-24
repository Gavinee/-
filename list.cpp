/*********************************
*********用数组实现线性表*********
初学者，其中有些代码错误，有待完善
还有两个函数没有实现:
ElemType LocateElem(SqList L, int i, ElemType compare())
ElemType ListTraverse(SqList L, ElemType visit())
**********************************/



#include<iostream>

using namespace std;
#define Error   -2                                    //错误
#define False   -1                                    //没有返回数据类型
typedef int ElemType;                               //定义类型宏
#define Size 100                                      //定义一个数组长度

typedef struct List {
	ElemType Array[Size];
	int ListSize;                                     //线性表容量
	int ListLength;                                   //线性表中已经使用了多少元素
}SqList;


void InitList(SqList &L)                              //初始化线性表     yes
{
	L.ListSize = Size;
	L.ListLength = 0;

}

void DestroyList(SqList &L)                           //销毁线性表      yes
{
	L.ListSize = 0;
	L.ListLength = 0;
}

void ClearList(SqList L)                              //清除线性表中的数据      yes
{
	L.ListLength = 0;
}

bool ListEmpty(SqList L)                             //判断线性表是否为空表   yes
{
	if (L.ListLength == 0)
	{   
		cout << "the list is empty!" << endl;
		return true;                                 //线性表为空,则返回TRUE
	}
	else
	{
		cout << "the list is not empty" << endl;
		return false;                                //线性表不为空，则返回FALSE
	}
}

int ListLength(SqList L)                             //求线性表的长度         yes
{
	ElemType length;
	length = L.ListLength;
	return length;
}

ElemType GetElem(SqList L,int i,ElemType &e)         //用e返回L中第i个元素的值
{
	if (L.ListLength > 0)
	{
		if (i >= 1 && i <= L.ListLength)
		{
			e = L.Array[i];
			return e;
		}
		else
			return Error;
	}
}

/**
bool compare(ElemType First, ElemType &e)
{
	if (L.Array[First] == e)
	{
		return true;
	}
	else
	{
		return false;
	}
}
**/


ElemType LocateElem(SqList L, int i, ElemType compare())  //返回L中第1个与e满足的关系compare()的数据元素的位序。
{

}


ElemType PriorElem(SqList L, ElemType e, ElemType &pre_e)         //求前驱元素    yes
{
	for (int i = 0; i < L.ListLength; i++)
	{
		if (e == L.Array[i])
		{
			if (i == 0)
			{
				return False;
			}
			else
			{
				pre_e = L.Array[i - 1];
				return pre_e;
			}
		
		}
		else
		{
			return Error;
		}
		
	}
}

ElemType NextElem(SqList L, ElemType cur_e, ElemType &next_e)             //求后继元素     yes
{
	for (int i = 0; i < L.ListLength; i++)
	{
		if (cur_e == L.Array[i])
		{
			if (i == L.ListLength - 1)
			{
				return False;
			}
			else
			{
				next_e = L.Array[i+1];
				return next_e;
			}
		}
		else
		{
			return Error;

		}
	}
}

ElemType ListInsert(SqList &L, int i, ElemType e)               //插入元素   yes
{
	if (L.ListLength > 0)
	{
		if (i >= 1 && i <= L.ListLength + 1)
		{
			for (int j = L.ListLength-1; j >=i-1; j--)
			{
				L.Array[j + 1] = L.Array[j];
			}
			L.Array[i] = e;
		}
		else
			return Error;
	}
}

ElemType ListDelete(SqList &L, int i, ElemType &e)               //删除元素    yes
{	
	if (L.ListLength > 0)
	{
		if (i <= L.ListLength&&i>=1)
		{
			e = L.Array[i-1];
			return e;

			for (i; i < L.ListLength; i++)
			{
				L.Array[i-1] = L.Array[i];
			}
		}
		else Error;
	}
}

ElemType ListTraverse(SqList L, ElemType visit())
{

}







