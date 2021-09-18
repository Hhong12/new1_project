#pragma once

struct MyStruct
{
	int data;
	MyStruct *next;
};
class CMyList
{
public:
	CMyList();
	~CMyList();
	void Create();//创建单链表
	void PrintList();//打印单链表
	int GetListLength(MyStruct *head);//求单链表中节点的个数
	MyStruct* ReverseList(MyStruct *listNode);//链表的反转
	MyStruct* FindMidList(MyStruct *head);//找中间节点
	MyStruct* FindLastList(MyStruct *head, int k);// 查找单链表中的倒数第K个结点（k > 0）
	void PrintReverseList(MyStruct *head);//从尾到头打印单链表
	MyStruct* MergeList(MyStruct* head1, MyStruct* head2);//合并两个有序的列表
	bool HasCircle(MyStruct* head);//判断是否有环
	bool IsIntersected(MyStruct* head1, MyStruct* head2);//判断是否相交
	MyStruct* GetFirstCommonNode(MyStruct* head1, MyStruct* head2);//求两个链表相交的第一个节点
	MyStruct* GetFirstInCircle(MyStruct* head);//求进入环中的第一个节点
	int GetCircleLength(MyStruct* head);//求环的长度，参数为相遇的那个节点
	void Delete(MyStruct* head, MyStruct* ToBeDelete);//删除节点复杂第O(1)
private:
	MyStruct *m_phead;//链表的头指针
};

