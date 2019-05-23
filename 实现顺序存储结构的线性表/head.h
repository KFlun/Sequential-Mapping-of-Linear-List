#pragma once
typedef int ElemType;
#define MAXSIZE 20//���洢����,���Ǹ�"��"
class SqList
{
public:
	SqList();//�޲ι����������캯����
	SqList(ElemType elems[], int n);//�вι�����
	~SqList();//��������
	bool CreatList();//�½�һ��˳���,����һ������
	bool UnionList(SqList L1, SqList L2);//�ϲ�����˳�����ͬԪ�ز����ظ�
	int LocateElem(ElemType e);//��Ԫ�ز��ң��ȶԣ����ɹ��򷵻�Ԫ�ص���ţ���1��ʼ��,ʧ���򷵻�0
	int ListLength();//˳���ĳ���
	bool GetElem(int i, ElemType& e);//���ҵ�i��λ�õ�Ԫ��
	bool ListInsert(int i, ElemType e);//�ڵ�i��λ�ò���Ԫ��
	bool ListDelete(int i, ElemType& e);//ɾ����i��λ�õ�Ԫ��
	bool ListEmpty();//�п�
	void clearList();//���˳���
	void display();//��ʾ��ǰ��˳���

private:
	ElemType data[MAXSIZE];//�±��0��ʼ�����Ƕ����Ա�Ĳ����е��±��1��ʼ����1��Ԫ����ʵ�����±�Ϊ0��Ԫ��
	int length;
};
