#include "head.h"
#include <iostream>
using namespace std;

SqList::SqList()//初始化
{
	length = 0;//
}

SqList::SqList(ElemType elems[], int n)//有参构造器
{
	if (n > MAXSIZE)
	{
		cout << "传入的顺序表长度超出最大范围，只接收了前" << MAXSIZE << "个元素" << endl;
		length = MAXSIZE;
	}
	else
		length = n;//

	for (int i = 0; i < length; i++)
		data[i] = elems[i];
}

SqList::~SqList()
{

}

bool SqList::CreatList()
{

	cout << "插入多少个元素(0-20)？" << endl;
	cin >> length;
	if (length<0 || length>MAXSIZE)
	{
		length = 0;
		return false;
	}
	for (int i = 1; i <= length; i++)
	{
		//        cout<<"请输入顺序线性表的第"<<i<<"个元素：";
		//        cin>>L->data[i-1];
		data[i - 1] = i;
	}
	return true;
}

bool SqList::UnionList(SqList L1, SqList L2)
{
	int i, j;
	for (i = 0; i < L1.length; i++)
	{
		data[i] = L1.data[i];
	}

	for (j = 0; j < L2.length; j++)
		if (L1.LocateElem(L2.data[j]) == 0)
		{
			if (i >= MAXSIZE)
				return false;
			data[i] = L2.data[j];
			i++;
		}
	length = i;
	return true;
}

int  SqList::LocateElem(ElemType e)//成功则返回元素的序号（从1开始）,失败则返回0
{
	for (int i = 0; i < length; i++)
		if (data[i] == e)
			return i + 1;
	return 0;
}

int  SqList::ListLength()
{
	return length;
}

bool SqList::GetElem(int i, ElemType& e)
{
	if (length == 0 || i<1 || i>length)
		return false;
	e = data[i - 1];
	return true;
}

bool SqList::ListInsert(int i, ElemType e)
{
	if (length == MAXSIZE || i<1 || i>length + 1)//线性表满，或者i的范围不在合理范围内时返回错误
		return false;
	if (i <= length)//不在表尾
	{
		//插入位置的后续元素后移一位
		for (int k = length - 1; k >= i - 1; k--)
			data[k + 1] = data[k];// 倒序挪动位置，避免覆盖问题
	}
	data[i - 1] = e;//插入元素
	length++;
	return true;
}

bool SqList::ListDelete(int i, ElemType& e)
{
	if (length == 0 || i<1 || i>length)//线性表满，或者i的范围不在合理范围内时返回错误
		return false;
	e = data[i - 1];//取出元素
	if (i <= length)//不在表尾
	{
		//插入位置的后续元素前移一位
		for (int k = i - 1; k < length - 1; k++)
			data[k] = data[k + 1];// 倒序挪动位置，避免覆盖问题
	}
	length--;
	return true;
}

bool SqList::ListEmpty()
{
	if (length == 0)
		return true;
	return false;
}

void SqList::clearList()
{
	length = 0;
}

void SqList::display()
{
	for (int i = 0; i < length; i++)
		cout << data[i] << "  ";
	cout << endl;
}