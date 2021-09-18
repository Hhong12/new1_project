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
	void Create();//����������
	void PrintList();//��ӡ������
	int GetListLength(MyStruct *head);//�������нڵ�ĸ���
	MyStruct* ReverseList(MyStruct *listNode);//����ķ�ת
	MyStruct* FindMidList(MyStruct *head);//���м�ڵ�
	MyStruct* FindLastList(MyStruct *head, int k);// ���ҵ������еĵ�����K����㣨k > 0��
	void PrintReverseList(MyStruct *head);//��β��ͷ��ӡ������
	MyStruct* MergeList(MyStruct* head1, MyStruct* head2);//�ϲ�����������б�
	bool HasCircle(MyStruct* head);//�ж��Ƿ��л�
	bool IsIntersected(MyStruct* head1, MyStruct* head2);//�ж��Ƿ��ཻ
	MyStruct* GetFirstCommonNode(MyStruct* head1, MyStruct* head2);//�����������ཻ�ĵ�һ���ڵ�
	MyStruct* GetFirstInCircle(MyStruct* head);//����뻷�еĵ�һ���ڵ�
	int GetCircleLength(MyStruct* head);//�󻷵ĳ��ȣ�����Ϊ�������Ǹ��ڵ�
	void Delete(MyStruct* head, MyStruct* ToBeDelete);//ɾ���ڵ㸴�ӵ�O(1)
private:
	MyStruct *m_phead;//�����ͷָ��
};

