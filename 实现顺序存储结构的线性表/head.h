#pragma once
typedef int ElemType;
#define MAXSIZE 20//最大存储容量,这是个"宏"
class SqList
{
public:
	SqList();//无参构造器（构造函数）
	SqList(ElemType elems[], int n);//有参构造器
	~SqList();//析构函数
	bool CreatList();//新建一个顺序表,就是一个数组
	bool UnionList(SqList L1, SqList L2);//合并两个顺序表，相同元素不再重复
	int LocateElem(ElemType e);//按元素查找（比对）：成功则返回元素的序号（从1开始）,失败则返回0
	int ListLength();//顺序表的长度
	bool GetElem(int i, ElemType& e);//查找第i个位置的元素
	bool ListInsert(int i, ElemType e);//在第i个位置插入元素
	bool ListDelete(int i, ElemType& e);//删除第i个位置的元素
	bool ListEmpty();//判空
	void clearList();//清空顺序表
	void display();//显示当前的顺序表

private:
	ElemType data[MAXSIZE];//下标从0开始，但是对线性表的操作中的下标从1开始：第1个元素其实就是下标为0的元素
	int length;
};
