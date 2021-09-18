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
		cout << "�����ɹ�!" << endl;
	}
	else
	{
		cout << "û���������ݣ�" << endl;
	}
	

}
void CMyList::PrintList()
{
	MyStruct *pTemp = m_phead;
	//������������ڵ��ֵ
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
	int len = 0;//������
	MyStruct *cur = head;//��ͷ�ڵ㿪ʼ
	while (cur != nullptr)
	{
		len++;
		cur = cur->next;//��һ���ڵ�
	}
	return len;

}

//��ת������
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
		MyStruct *pTemp = m_phead;//����ɾ���Ľڵ�
		m_phead = m_phead->next;//ͷ�ڵ�ָ����һ���ڵ�
		delete pTemp;//ɾ��ԭ����ͷ�ڵ�
		pTemp = nullptr;
	}
}
MyStruct* CMyList::FindMidList(MyStruct *head)//���м�ڵ�
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
//���ҵ������еĵ�����K����㣨k > 0��
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
//ʹ�õݹ��β��ͷ��ӡ����
void CMyList::PrintReverseList(MyStruct *head)
{
	
}

MyStruct* CMyList::MergeList(MyStruct* head1, MyStruct* head2)//�ϲ�����������б�
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

//�жϺ��Ƿ��л�
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

//�ж��Ƿ��ཻ
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
	if (tail1 != tail2)//���ཻ
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
//ɾ���ڵ㸴�ӵ�O(1)
void CMyList::Delete(MyStruct* head, MyStruct* ToBeDelete)
{
	if (ToBeDelete == nullptr)
	{
		return ;
	}
	if (ToBeDelete->next != nullptr)
	{
		ToBeDelete->data = ToBeDelete->next->data;//���¸��ڵ����ݸ��Ƶ����ڵ㣬Ȼ��ɾ����һ���ڵ�
		MyStruct* temp = ToBeDelete->next;
		delete temp;
	}
	else//ɾ������β�ڵ�
	{
		if (head == ToBeDelete)//ֻ��һ���ڵ�����
		{
			head = nullptr;
			delete ToBeDelete;
		}
		else
		{
			MyStruct* node = head;//�洢Ҫɾ���ڵ����һ���ڵ�
			while (node->next != ToBeDelete)//�ҵ�Ҫɾ���Ľڵ����һ���ڵ�
			{
				node = node->next;
			}
			node->next == nullptr;//ɾ���˽ڵ�
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
	//�����еĴ˽ڵ���Ϊ�����β�ڵ㣬������Ϊ�����������ཻ������
	MyStruct* pTempTail = pSlow;
	MyStruct* pHead1 = head;
	MyStruct* pHead2 = pTempTail->next;
	MyStruct* pNode1 = pHead1; MyStruct* pNode2 = pHead2;//����������ʱ�����洢һ��
	int len1 = 1;
	//��ֿ�����������ĳ���
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
