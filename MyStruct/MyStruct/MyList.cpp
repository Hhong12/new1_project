#include "MyList.h"
#include <iostream>
using namespace std;

CMyList::CMyList()
{
	m_phead = nullptr;
}
void CMyList::Create()
{
	MyStruct *p, *s;
	int x = 0; cin >> x;
	while (x != -1)
	{
		s = new MyStruct;
		s->data = x;
		if (nullptr == m_phead)
		{
			m_phead = s;
		}
		else
		{
			p->next = s;
		}
		p = s;
		cin >> x;
	}
	p->next = nullptr;
	if (nullptr != m_phead)
	{
		cout << "创建成功!" << endl;
	}
	else
	{
		cout << "没有输入数据！" << endl;
	}
	

}
void CMyList::PrintList()
{
	MyStruct *pTemp = m_phead;
	//遍历链表并输出节点的值
	while (pTemp)
	{
		cout << pTemp->data << endl;
		pTemp = pTemp->next;
	}
}
int CMyList::GetListLength(MyStruct *head)
{
	if(head == nullptr)
	{
		return 0;
	}
	int len = 0;//链表长度
	MyStruct *cur = head;//从头节点开始
	while (cur != nullptr)
	{
		len++;
		cur = cur->next;//下一个节点
	}
	return len;

}

//反转单链表
MyStruct* CMyList::ReverseList(MyStruct *listNode)
{
	MyStruct *resultList = new MyStruct;
	resultList->next = listNode;
	MyStruct *p = listNode;
	MyStruct *m_pNext = p->next;
	while (m_pNext!=nullptr)
	{
		p->next = m_pNext->next;
		m_pNext->next = resultList->next;
		resultList->next = m_pNext;
		m_pNext = p->next;
	}
	return resultList->next;
}
CMyList::~CMyList()
{
	while (m_phead != nullptr)
	{
		MyStruct *pTemp = m_phead;//保存删除的节点
		m_phead = m_phead->next;//头节点指向下一个节点
		delete pTemp;//删除原来的头节点
		pTemp = nullptr;
	}
}
MyStruct* CMyList::FindMidList(MyStruct *head)//找中间节点
{
	if (head == nullptr)
	{
		return 0;
	}
	MyStruct* first = head;
	MyStruct* second = head;
	while (first != nullptr && second != nullptr)
	{
		first = first->next;
		second = second->next->next;
	}
	return first;
}
//查找单链表中的倒数第K个结点（k > 0）
MyStruct* CMyList::FindLastList(MyStruct *head, int k)
{
	if (head == 0 || k == 0)
	{
		return 0;
	}
	MyStruct* first = head;
	MyStruct* second = head;
	for (int i = 0; i < k; i++)
	{
		second = second->next;
		if (second == nullptr)
		{
			return 0;
		}
	}
	while (second->next != nullptr)
	{
		first = first->next;
		second = second->next;
	}
	return first;

}
//使用递归从尾到头打印链表
void CMyList::PrintReverseList(MyStruct *head)
{
	
}

MyStruct* CMyList::MergeList(MyStruct* head1, MyStruct* head2)//合并两个有序的列表
{
	if (head1 == nullptr)
	{
		return head2;
	}
	if (head2 == nullptr)
	{
		return head1;
	}

	MyStruct* head = nullptr;
	if (head1->data < head2->data)
	{
		head = head1;
		head->next = MergeList(head1->next, head2);
	}
	else
	{
		head = head2;
		head->next = MergeList(head1, head2->next);
	}
	return head;
}

//判断后是否有环
bool CMyList::HasCircle(MyStruct* head)
{
	if (head == nullptr)
	{
		return false;
	}
	MyStruct* pFast = head;
	MyStruct* pSlow = head;
	while (pFast != nullptr && pSlow != nullptr)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	}
	if (pFast == pSlow)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//判断是否相交
bool CMyList::IsIntersected(MyStruct* head1, MyStruct* head2)
{
	if (head1 == nullptr || head2 == nullptr)
	{
		return false;
	}
	MyStruct* tail1 = head1;
	while (tail1->next != nullptr)
	{
		tail1 = tail1->next;
	}
	MyStruct* tail2 = head2;
	while (tail2->next != nullptr)
	{
		tail2 = tail2->next;
	}
	return tail1 == tail2;
}

MyStruct* CMyList::GetFirstCommonNode(MyStruct* head1, MyStruct* head2)
{
	if (head1 == nullptr || head2 == nullptr)
	{
		return 0;
	}
	int len1 = 1; MyStruct* tail1 = head1;
	while (tail1->next != nullptr)
	{
		tail1 = tail1->next;
		len1++;
	}
	int len2 = 1; MyStruct* tail2 = head2;
	while (tail2->next != nullptr)
	{
		tail2 = tail2->next;
		len2++;
	}
	if (tail1 != tail2)//不相交
	{
		return 0;
	}
	MyStruct* node1 = head1;
	MyStruct* node2 = head2;
	if (len1 > len2)
	{
		int k = len1 - len2;
		while (k--)
		{
			node1 = node1->next;
		}
	}
	else
	{
		int k = len2 - len1;
		while (k--)
		{
			node2 = node2->next;
		}
	}
	while (node1 != node2)
	{
		node1 = node1->next;
		node2 = node2->next;
	}
	return node1;
}
//删除节点复杂第O(1)
void CMyList::Delete(MyStruct* head, MyStruct* ToBeDelete)
{
	if (ToBeDelete == nullptr)
	{
		return ;
	}
	if (ToBeDelete->next != nullptr)
	{
		ToBeDelete->data = ToBeDelete->next->data;//将下个节点数据复制到本节点，然后删除下一个节点
		MyStruct* temp = ToBeDelete->next;
		delete temp;
	}
	else//删除的是尾节点
	{
		if (head == ToBeDelete)//只有一个节点的情况
		{
			head = nullptr;
			delete ToBeDelete;
		}
		else
		{
			MyStruct* node = head;//存储要删除节点的上一个节点
			while (node->next != ToBeDelete)//找到要删除的节点的上一个节点
			{
				node = node->next;
			}
			node->next == nullptr;//删除此节点
			delete ToBeDelete;
		}
	}
}
MyStruct* CMyList::GetFirstInCircle(MyStruct* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return nullptr;
	}
	MyStruct* pFast = head;
	MyStruct* pSlow = head;
	while (pFast != nullptr && pSlow != nullptr)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if (pSlow == pFast)
		{
			break;
		}
	}
	if (pFast == nullptr || pFast->next == nullptr)
	{
		return NULL;
	}
	//将换中的此节点作为假设的尾节点，将它变为两个单链表相交的问题
	MyStruct* pTempTail = pSlow;
	MyStruct* pHead1 = head;
	MyStruct* pHead2 = pTempTail->next;
	MyStruct* pNode1 = pHead1; MyStruct* pNode2 = pHead2;//创建两个临时变量存储一下
	int len1 = 1;
	//求分开后两个链表的长度
	while (pNode1 != pTempTail)
	{
		pNode1 = pNode1->next;
		len1++;
	}
	int len2 = 1;
	while (pNode2 != pTempTail)
	{
		pNode2 = pNode2->next;
		len2++;
	}
	pNode1 = pHead1; pNode2 = pHead2;
	if (len1 > len2)
	{
		int k = len1 - len2;
		while (k--)
		{
			pNode1 = pNode1->next;
		}
	}
	else
	{
		int k = len2 - len1;
		while (k--)
		{
			pNode2 = pNode2->next;
		}
	}
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;
}
int CMyList::GetCircleLength(MyStruct* head)
{
	MyStruct* current = head;
	int length = 0;
	while (current != nullptr)
	{
		current = current->next;
		length++;
		if (current == head)
		{
			return length;
		}
	}
	return length;
}
