/**********************************************************
本代码是来自博客园静默虚空
链接附上:http://www.cnblogs.com/jingmoxukong/p/3827011.html

由于初学，所以看到经典的code就引用过来，原作者实现了一部分函数，
实现的函数我已在类函数声明的后面打了勾，没打勾的我尝试着自己实现
一遍，由于水平有限，所以不免有很多错误，请大家多多指点。
还看了几篇博文，觉得里面有我想要的知识，于是就把链接留在了注释内，
希望方便我理解。
***********************************************************/




#pragma once

using namespace std;

/***********************************************************
1.复合类:在Node类中定义友元方的方
式,使List类可以访问结点的私有成员
************************************************************/




/**
class LinkNode
{
	friend class LinkList;
private:
	int data;
	LinkList *next;
};

class LinkList
{
public:
	//单链表具体操作
private:
	LinkNode *head;
}
*/




/*********************************************************
2.嵌套类：在List内部定义node类，但是Node的
数据成员放在public部分,使List和Node均可以
直接访问Node的成员
**********************************************************/



/*
class LinkList
{
public:
	//单链表具体操作
private:
	class LinkNode
	{
		int data;
		LinkNode *next;
	};
	LinkNode*head;
};

**/




/*******************************************************
3.继承:在Node类中把成员定义为protected,然后让
List继承Node类，这样就可以访问Node类的成员。
*******************************************************/


/**
class LinkNode
{
protected:
	int data;
	LinkNode *next;
};

class LinkList :public LinkNode
{
public:
	//单链表具体操作
private:
	LinkNode *head;
};

**/



/****************************************************
4.直接用struct 定义Node类，因为struct 的成员默认为公有
数据成员，所以可直接访问(struct也可以指定保护类型)
*****************************************************/
/**
struct LinkNode         //结点
{
	int data;           //定义数据域
	LinkNode *next;     //定义指针域
};

class LinkList         //链表
{
public:
	//单链表具体操作
private:
	LinkNode *head;    //表头
};
*/


/****************************************************
模板类补充：
定义一个模板类:
template<class 模板参数表>

class 类名{
//类定义...................

};

注意
(1)如果在全局域中声明了与模板参数同名的变量，则该变量被隐藏掉
(2)模板参数名不能被当做模板定义中类成员的名字
(3)同一个模板参数名在模板参数表中只能出现一次
(4)在不同的类模板或声明中，模板参数名可以被重复使用
(5)在类模板的前向声明和定义中，模板参数的名字可以不同
(6)类模板参数可以有缺省实参，给参数提供实参的顺序是先右后左
(7)类模板名可以用作一个类型指示符，当一个类模板名被用作另一个模板定义的类型指示符时，必须指定完整的实参表

函数重载：
http://www.cnblogs.com/assemble8086/archive/2011/10/02/2198308.html

模板函数，实现链表
http://www.cnblogs.com/jingmoxukong/p/3827011.html

const的作用
http://blog.csdn.net/Eric_Jo/article/details/4138548

重载操作符:
http://blog.csdn.net/u010270148/article/details/41820117
http://www.cnblogs.com/zpcdbky/p/5027481.html

****************************************************/

/****************************************************
const作用
1.可以定义为常量
2.便于进行类型检查
  const 常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行
  安全检查，而对后者只进行字符替换，没有类型安全检查，并且在字符替换时
  可能会产生意料不到的错误
3.可以保护被修饰的东西
4.可以很方便的进行参数的调整和修改
5.为函数重载提供了一个参考
6.可以节省空间，避免不必要的内存分配
7.提高了效率


*****************************************************/

















/*单链表的结点定义*/
template<class T>
struct  LinkNode
{
	T data;
	LinkNode<T> *next;
	LinkNode(LinkNode<T>*ptr = NULL) { next = ptr };
	LinkNode(const T &item, LinkNode<T> *ptr = NULL)   //对传入的参数进行类型检查，不匹配进行提示
	//函数参数表中的形参允许有默认值，但是带默认值得参数需要放后面
	{
		next = ptr;
		data = item;
	}
};

/*带头结点的单链表定义*/
template <class T>
class LinkList
{
public :
	//无参数的构造函数
	LinkList(){ head = new LinkNode<T>; }

	//有参数的构造函数
	LinkList(const T &item) { head = new LinkList<T>(item); }

	//拷贝构造函数
	LinkList(LinkList<T>&List);

	//析构函数
	~LinkList() { Clear(); }

	//重载函数:赋值
	LinkList<T>& operator=(Linklist<T> &List);

	//链表清空
	void Clear();                         //y

	//获取链表长度
	int Length()const;                    //y

	//获取链表头结点
	LinkNode<T>* GetHead()const;

	//设置链表头结点
	void SetHead(LinkList<T> *p);

	//查找数据的位置，返回第一个找到的满足该数值的结点指针
	LinkList<T>* Find(T &item);

	//定位指定的位置，返回该位置上的结点指针
	LinkList<T>* Locate(int pos);            //y

	//在指定位置pos上的结点，失败返回false
	bool Insert(T &item, int item);          //y

	//删除指定位置pos上的结点，item就是该结点的值，失败返回false
	bool Remove(int pos, T &item);          //y

	//获取指定位置pos的结点的值，失败返回false
	bool GetData(int pos, T &item);

	//判断链表是否为空
	bool IsEmpty()const;

	//打印链表
	void Print()const;                    //y

	//链表排序
	void Sort();

	//链表逆置
	void Reverse();                        //y

private:
	LinkNode<T>*head;

};


//定位位置
/*返回链表中第pos个元素的地址，如果pos<0或超过链表最大个数返回NULL*/
template<class T>
LinkNode<T>* LinkList<T>::Locate(int pos)
{
	int i = 0;
	LinkNode<T> *p = head;

	if (pos < 0)
		return NULL;

	while (NULL != p&&i < pos)
	{
		p = p->next;
		i++;
	}
	return p;
}



//插入结点
template<class T>
bool LinkList<T>::Insert(T &item, int pos)
{
	LinkNode<T> *p = Locate(pos);
	if (NULL == p)
		return false;

	LocateNode<T>  *node = new LinkNode<T>(item);
	if (NULL == node)
	{
		cout << "分配内存失败！" << endl;
		exit(1);
	}
	node->next = p->next;        //新结点的指针域指向p结点的下一个结点
	p->next = node;              //将node设置为p的下一个结点
	return ture;
}

template<class T>
bool LinkList<T>::Remove(int pos, T &item)
{
	LinkNode<T> *p = Locate(pos);
	if (NULL == p || NULL == p->next)
		return false;

	LinkNode<T> *del = p->next;
	p->next = del->next;
	item = del->data;
	delete del;
	return true;
}

//清空链表
template<class T>
void LinkList<T>::Clear()
{
	LinkNode<T> *p = NULL;

	//遍历链表，每次都删除头结点的next结点，最后保留头结点
	while (NULL != head->next)
	{
		p = head->next;
		head->next = p->head;      //每次都删除头结点的next结点
		delete p;
	}
}

//打印链表元素
template<class T>
void LinkList<T>::Print()const
{
	int count = 0;
	LinkNode<T> *p = head;
	while (NULL != p->next)
	{
		p = p->next;
		cout << p->data << " ";
		if (++coun % 10 == 0)       //每隔十个元素，换行打印
			cout << endl;
	}
}

//求链表长度
template<class T>
int LinkList<T>::Length() const
{
	int count = 0;
	LinkNode<T> *p = head->next;     //初始化，p指向头结点下年一个结点
	while (NULL != p)                //判断该结点是否为空
	{
		p = p->next;                 //不为空，则让p继续指向下一个结点
		++count;                     //长度+1
	}
	return count;
}


//单链表倒置
template<class T>
void LinkList<T>::Reverse()
{
	LinkNode<T> *pre = head->next;
	LinkNode<T> *curr = pre->next;
	LinkNode<T> *next = NULL;

	head->next->next = NULL;

	while (curr)
	{
		next = curr->next;        //结点next赋为head->next->next->next
		curr->next = pre;         //将curr的指针域指向pre
		pre = curr;               //pre结点移向下一个结点
	}
	head->next = pre;             
}


//设置链表头结点
template<class T>
void LinkList<T>::SetHead(LinkList<T> *p)
{
	LinkNode<T> *p;
	LinkNode<T> p=new LinkNode;
}


//获取链表头结点
template<class T>
LinkNode<T>* Linklist<T>::GetHead()const
{
	if(head)
	{
		return head;
	}
	else
	{
		return;
	}
}



//查找数据的位置，返回第一个找到的满足该数值的结点指针
LinklistNode<T>* LinkList<T>::Find(T &item)
{
	LinkNode<T> *p;
	p=head->next;
	if(head->data==item)
		return head;
	while(p->data==item)
	{
		if(p->next==NULL)
		{
			return ;
		}
		p=p->next;

	}
	return p;
}


//获取指定位置pos的结点的值，失败返回false
bool GetData(int pos, T &item)
{
	LinkNode<T> *p;
	int i=0;
	p=head->next;
	if(pos<1||pos>Length())
	{
		return false;
	}
	else
	{
		while(pos==i)
		{
			p=p->next;
			i++;
		}
		return p->data;
	}
}



//判断链表是否为空
bool IsEmpty()const
{
	if(head==NULL)
		return true;
	else
		return false;
}


//链表排序
void Sort()
{


}









