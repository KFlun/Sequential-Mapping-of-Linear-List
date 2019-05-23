#include "head.h"
#include <iostream>
using namespace std;

SqList::SqList()//��ʼ��
{
	length = 0;//
}

SqList::SqList(ElemType elems[], int n)//�вι�����
{
	if (n > MAXSIZE)
	{
		cout << "�����˳����ȳ������Χ��ֻ������ǰ" << MAXSIZE << "��Ԫ��" << endl;
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

	cout << "������ٸ�Ԫ��(0-20)��" << endl;
	cin >> length;
	if (length<0 || length>MAXSIZE)
	{
		length = 0;
		return false;
	}
	for (int i = 1; i <= length; i++)
	{
		//        cout<<"������˳�����Ա�ĵ�"<<i<<"��Ԫ�أ�";
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

int  SqList::LocateElem(ElemType e)//�ɹ��򷵻�Ԫ�ص���ţ���1��ʼ��,ʧ���򷵻�0
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
	if (length == MAXSIZE || i<1 || i>length + 1)//���Ա���������i�ķ�Χ���ں���Χ��ʱ���ش���
		return false;
	if (i <= length)//���ڱ�β
	{
		//����λ�õĺ���Ԫ�غ���һλ
		for (int k = length - 1; k >= i - 1; k--)
			data[k + 1] = data[k];// ����Ų��λ�ã����⸲������
	}
	data[i - 1] = e;//����Ԫ��
	length++;
	return true;
}

bool SqList::ListDelete(int i, ElemType& e)
{
	if (length == 0 || i<1 || i>length)//���Ա���������i�ķ�Χ���ں���Χ��ʱ���ش���
		return false;
	e = data[i - 1];//ȡ��Ԫ��
	if (i <= length)//���ڱ�β
	{
		//����λ�õĺ���Ԫ��ǰ��һλ
		for (int k = i - 1; k < length - 1; k++)
			data[k] = data[k + 1];// ����Ų��λ�ã����⸲������
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