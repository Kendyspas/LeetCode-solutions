#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int data) : val(data), next(nullptr) {}
	ListNode(int data, ListNode* next) : val(data), next(next) {}
};

class Solution 
{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
	{
		ListNode* cur1 = list1;
		ListNode* cur2 = list2;
		ListNode* dummy = new ListNode(0);
		ListNode* cur = dummy;
		while (cur1 && cur2)
		{
			if (cur1->val < cur2->val)
			{
				cur->next = new ListNode(cur1->val);
				cur1 = cur1->next;
				cur = cur->next;
			}
			else
			{
				cur->next = new ListNode(cur2->val);
				cur2 = cur2->next;
				cur = cur->next;
			}
		}
		while (cur1)
		{
			cur->next = new ListNode(cur1->val);
			cur1 = cur1->next;
			cur = cur->next;
		}
		while (cur2)
		{
			cur->next = new ListNode(cur2->val);
			cur2 = cur2->next;
			cur = cur->next;
		}
		ListNode* NewHead = dummy->next;
		return NewHead;
	}
	ListNode* Input()
	{
		int Quantum, data;
		cin >> Quantum;
		cin >> data;
		ListNode* Head = new ListNode(data);
		ListNode* cur = Head;
		for (int index = 1;index < Quantum;index++)
		{
			cin >> data;
			cur->next = new ListNode(data);
			cur = cur->next;
		}
		return Head;
	}
	void Output(ListNode* List)
	{
		ListNode* cur = List;
		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
	}
};

int main()
{
	Solution sol;
	ListNode* List_1 = sol.Input();
	ListNode* List_2 = sol.Input();
	ListNode* List = sol.mergeTwoLists(List_1, List_2);
	sol.Output(List);
	return 0;
}