/*********************************
*********������ʵ�����Ա�*********
��ѧ�ߣ�������Щ��������д�����
**********************************/



#include<iostream>

using namespace std;
#define Error   -2                                    //����
#define False   -1                                    //û�з�����������
typedef int ElemType;                               //�������ͺ�
#define Size 100                                      //����һ�����鳤��

typedef struct List {
	ElemType Array[Size];
	int ListSize;                                     //���Ա�����
	int ListLength;                                   //���Ա����Ѿ�ʹ���˶���Ԫ��
}SqList;


void InitList(SqList &L)                              //��ʼ�����Ա�     yes
{
	L.ListSize = Size;
	L.ListLength = 0;

}

void DestroyList(SqList &L)                           //�������Ա�      yes
{
	L.ListSize = 0;
	L.ListLength = 0;
}

void ClearList(SqList L)                              //������Ա��е�����      yes
{
	L.ListLength = 0;
}

bool ListEmpty(SqList L)                             //�ж����Ա��Ƿ�Ϊ�ձ�   yes
{
	if (L.ListLength == 0)
	{   
		cout << "the list is empty!" << endl;
		return true;                                 //���Ա�Ϊ��,�򷵻�TRUE
	}
	else
	{
		cout << "the list is not empty" << endl;
		return false;                                //���Ա�Ϊ�գ��򷵻�FALSE
	}
}

int ListLength(SqList L)                             //�����Ա�ĳ���         yes
{
	ElemType length;
	length = L.ListLength;
	return length;
}

ElemType GetElem(SqList L,int i,ElemType &e)         //��e����L�е�i��Ԫ�ص�ֵ
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


ElemType LocateElem(SqList L, int i, ElemType compare())  //����L�е�1����e����Ĺ�ϵcompare()������Ԫ�ص�λ��
{

}


ElemType PriorElem(SqList L, ElemType e, ElemType &pre_e)         //��ǰ��Ԫ��    yes
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

ElemType NextElem(SqList L, ElemType cur_e, ElemType &next_e)             //����Ԫ��     yes
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

ElemType ListInsert(SqList &L, int i, ElemType e)               //����Ԫ��   yes
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

ElemType ListDelete(SqList &L, int i, ElemType &e)               //ɾ��Ԫ��    yes
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







