#include <iostream>
using namespace std;
//冒泡排序
void BubbleSort(int arr[],int lenght)
{
	for(int i=0;i<length;i++)
	{
		for(int j=0;j<length-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp =0;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
 } 
//选择排序
void choose(int arr[],int length)
{
	for(int i = 0;i<length;i++)
	{
		int index = i;//第一个索引 
		for(int j=i+1;j<length;j++)
		{
			if(arr[j]<arr[index])
			{
				index = j
			}
		}
		if(index == i)
		{
			continue;
		}
		else
		{
			int temp =0;temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
 } 

//快速排序
void QuickSort(int arr[],int start,int end)
{
	if(start >= end)
	{
		return;
	}
	int i = start ;
	int j = end;
	int base = arr[i];
	while(i<j)
	{
		if(arr[j] > base)
		{
			j--;
		}
		else
		{
			arr[i] = arr[j];
			i++;
		}
		if(arr[i] < base)
		{
			i--;
		}
		else
		{
			a[j] = a[i];
			j--;
		}
		arr[i] = base;
		QuickSort(arr,start,i-1);
		QuickSort(arr,i+1,end);
	}
	
 } 

//堆排序
 
 
 //数组全排列
 
 void Perm(int arr[],int k,int m)//k,其实位置，m终点位置
 {
 	if(k==m)
	 {
	 	for(int i=0;i<arr.length;i++)
	 	{
	 		cout<<a[i];
		 }
	  } 
	  for(int i = k;i<=m;i++)
	  {
	  	swap(arr[k],arr[i]);
	  	Perm(arr,k+1;m);
	  	swap(arr[i],arr[k]);
	  }
  } 
  
  
  
  //哈希排序
  void HashSort(int arr[])
  {
  	int count[100] = 0;
  	for(int i = 0;i<arr.length;i++)
  	{
  		count[a[i]]++;
	  }
	  for(int i=0;i<100;i++)
	  {
	  	for(int j=0;j<count[i];j++)
	  	{
	  		cout<<i<<endl;
		  }
	  }
   } 
   
   //希尔排序
   const int INC = 2;
   void ShellSort(int a[],int len)
   {
   	int gap = a.length/INC;
   	int insertNum = 0;
   	while(gap)
   	{
   		for(int i = gap;i<a.length;i++)
   		{
   			insertNum = a[i];
   			int j=i;
   			if(j >= gap && insertNum < a[j-gap])
   			{
   				a[j] = a[j-gap];
   				j -= gap;
			   }
			   a[j] = insertNum;
		   }
		   gap = gap/INC;
	   }
   }
   
   //单链表反转
   public ListNode reverseList(ListNode listNode)
   {
   	ListNode resultList = new ListNode();
   	resultList.next = listNode;
   	ListNode p = listNode;
	ListNode pNext = listNode.next;
	while(Pnext!=null)
	{
		p.next = pNext.next;
		pNext.next = result.next;
		result.next = pNext;
		pNext = p.next;
	 } 
	} 
	//找中间节点
	
	void FindMidNode(Node head,k)
	{
		if(head == null)
		{
			return null;
		}
		Node first;
		Node second;
		while(first!=null && second!=null)
		{
			first = first.next;
			second = second.next.next;
		}
		return first;
	 } 
	 
	 //找倒数第k个节点
	 void FindLastNode(Node head)
	 {
	 	if(head == null)
	 	{
	 		return null;
		 }
		 Node firstNode;
		 Node secondNode;
		 
		 	for(int i=0;i<k;i++)
		 	{
		 		secondNode = secondNode.next;
			 }
			 while(secondNode != null)
		 {
			 first = first.next;
			 second = second.next;
		  } 
		  return first;
	  } 
	  //判断节点个数 
	  int GetListLength(Node head)
	  {
	  	if(head == null)
	  	{
	  		return null;
		  }
		  int length = 0;
		  Node pNext = head;
		  while(head != null)
		  {
		  	length++;
		  	pNext = pNext.next;
		  	
		  }
		  return length;
	  }
	  
	  //从为到头打印链表
	  
	  void PrintLastList(Node head)
	  {
	  	statck <Node> node;
	  	Node pNext = head;
	  	while(head != null)
	  	{
	  		node.Push(pNext);
			  pNext = pNext.next; 
		  }
		  while(!node.empty())
		  {
		  	pNext = node.top();
		    cout<<pNext.data;
		    node.Pop();
		  }
	   } 
	   
	   
	   //合并已经排序好的两个链表
	   
	   void MergeList(Node head1,Node head2)
	   {
	   	Node head = null;//新链表的头节点
		   if(head1 == null)
		   {
		   	return head2;
			} 
			if(head2 == null)
			{
				return head1;
			}
			if(head1.data<head2.data)
			{
				head = head1;
				head.next = MergeList(head1.next,head2)
			}
			else
			{
				head = head2;
				head2.next = MergeList(head1,head2.next);
			}
			return head;
		} 
	   
	   //判断两个单链表是否相交：关键判断尾节点是否相同
	   bool IsIntersected(Node *head1,Node *head2)
	   {
	   	if(head1 == null || head2 == null)
	   	{
	   		return false;
		   }
		   Node pHead1 = head1;
		   Node pHead2 = head2;
		   while(pHead1.next != null)
		   {
		   	pHead1 = pHead1.next;
		   }
		   while(pHead2.next != null)
		   {
		   	pHead2 = pHead2.next;
		   }
		   if(pHead1 == pHead2)
		   {
		   	return true;
		   }
		} 
	   //给出单链表头指针O(1)删除指定节点
	   void Delete(Node head,node Todel)
	   {
	   	if(Todel == null || head == null)
	   	{
	   		return;
		   }
		   if(Todel.next != null)
		   {
		   	Todel.data = Todel.next.data;
		   	Node temp = Todel.next;
		   	Todel.next = Todel.next.next;
		   	delete temp;
		   }
		   else
		   {
		   	if(head == Todel)
		   	{
		   		delete Todel;
		   		head = null;
			   }
			   else
			   {
			   	Node pNode = head;
			   	while(pNode.next != Todel)
			   	{
			   		pNode = pNode.next;
				   }
				   pNode = Todel.data;
				   pNode.next = null;
				   delete Todel;
			   }
		   }
		} 
	  
	   //链栈
	   
	   void Enqueue(int data)//入栈 
	   {
	   	qnode *p = new qnode;
	   	p->data = data;
	   	if(f==null)//只有一个节点
		   {
		   	p->next = null;
		   	f=r=p;
		   	}
			   r->next = p;
			   p->next = null;
			   r= p;
			   return 
	   }
	    void Enqueue(int data)//出队
		{
			if(r==null)
			{
				
			}
			node p =f;
			f=f->next;
			delete p;
		 } 
	   
int main()
{
	
	
	
} 
