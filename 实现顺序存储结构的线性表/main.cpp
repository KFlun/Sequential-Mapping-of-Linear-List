#include <iostream>
#include "head.h"
using namespace std;

int main()
{
	SqList list;
	int num;
	ElemType elem;
	bool flag;

	cout << "            1.˳���Ĵ�������ʾ" << endl;
	if (!list.CreatList())
		cout << "˳�����ʧ�ܣ�" << endl;
	else
		cout << "˳������ɹ���    " << endl;
	//˳������ʾ
	list.display();
	cout << endl << endl;

	cout << "            2.��Ԫ�ز���" << endl;
	num = list.LocateElem(3);
	cout << "3��˳���ĵ�" << num << "��Ԫ��" << endl << endl << endl;

	cout << "            3.��λ�ò���" << endl;
	list.GetElem(4, elem);
	cout << "˳���ĵ�4��Ԫ����:" << elem << endl << endl << endl;

	cout << "            4.˳���Ĳ���" << endl;
	if (list.ListInsert(2, 10))
		cout << "����ɹ����ڵ�2��λ�ò���10��    " << endl;
	else
		cout << "����ʧ�ܣ�" << endl;
	list.display();
	cout << endl << endl;

	cout << "            5.ɾ��Ԫ��" << endl;
	list.ListDelete(5, elem);
	cout << "ɾ����5��Ԫ��:" << elem << endl;
	cout << "�ñ�ĳ���Ϊ:" << list.ListLength() << endl;
	list.display();
	cout << endl << endl;

	cout << "            6.���˳���" << endl;
	cout << "���˳���ǰ-----";
	if (!list.ListEmpty())
	{
		cout << "��ǰ˳����ǿձ�" << endl;
		list.clearList();
		cout << "���˳����-----";
		if (list.ListEmpty())
			cout << "��ǰ˳����ǿձ�" << endl;
	}
	cout << endl << endl;

	cout << "            7.�ϲ�˳���" << endl;
	ElemType elems1[8] = { 0,1,2,3,4,5,6,7 };
	ElemType elems2[9] = { 5,6,7,8,9,10,11,1,12 };

	SqList list1 = { elems1,8 };
	SqList list2 = { elems2,9 };
	SqList list3;
	cout << "�ϲ�ǰ��������Ϊ��" << endl;
	list1.display();
	list2.display();
	flag = list3.UnionList(list1, list2);
	if (!flag)
		cout << "�ϲ���˳���ĳ��ȳ������Χ" << endl;
	cout << "�ñ�ĳ���Ϊ:    " << list3.ListLength() << endl;
	list3.display();
	system("pause");
	return 0;
}