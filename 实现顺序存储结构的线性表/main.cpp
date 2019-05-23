#include <iostream>
#include "head.h"
using namespace std;

int main()
{
	SqList list;
	int num;
	ElemType elem;
	bool flag;

	cout << "            1.顺序表的创建和显示" << endl;
	if (!list.CreatList())
		cout << "顺序表创建失败！" << endl;
	else
		cout << "顺序表创建成功！    " << endl;
	//顺序表的显示
	list.display();
	cout << endl << endl;

	cout << "            2.按元素查找" << endl;
	num = list.LocateElem(3);
	cout << "3是顺序表的第" << num << "个元素" << endl << endl << endl;

	cout << "            3.按位置查找" << endl;
	list.GetElem(4, elem);
	cout << "顺序表的第4个元素是:" << elem << endl << endl << endl;

	cout << "            4.顺序表的插入" << endl;
	if (list.ListInsert(2, 10))
		cout << "插入成功！在第2个位置插入10后：    " << endl;
	else
		cout << "插入失败！" << endl;
	list.display();
	cout << endl << endl;

	cout << "            5.删除元素" << endl;
	list.ListDelete(5, elem);
	cout << "删掉第5个元素:" << elem << endl;
	cout << "该表的长度为:" << list.ListLength() << endl;
	list.display();
	cout << endl << endl;

	cout << "            6.清空顺序表" << endl;
	cout << "清空顺序表前-----";
	if (!list.ListEmpty())
	{
		cout << "当前顺序表不是空表！" << endl;
		list.clearList();
		cout << "清空顺序表后-----";
		if (list.ListEmpty())
			cout << "当前顺序表是空表！" << endl;
	}
	cout << endl << endl;

	cout << "            7.合并顺序表" << endl;
	ElemType elems1[8] = { 0,1,2,3,4,5,6,7 };
	ElemType elems2[9] = { 5,6,7,8,9,10,11,1,12 };

	SqList list1 = { elems1,8 };
	SqList list2 = { elems2,9 };
	SqList list3;
	cout << "合并前的两个表为：" << endl;
	list1.display();
	list2.display();
	flag = list3.UnionList(list1, list2);
	if (!flag)
		cout << "合并后，顺序表的长度超过最大范围" << endl;
	cout << "该表的长度为:    " << list3.ListLength() << endl;
	list3.display();
	system("pause");
	return 0;
}