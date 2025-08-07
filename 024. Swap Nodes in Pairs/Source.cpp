#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution 
{
public:
	ListNode* swapPairs(ListNode* head) 
	{
		ListNode* dummy = new ListNode(0, head);
		ListNode* cur = dummy;
		while (cur->next && cur->next->next)
		{
			ListNode* Next = cur->next;
			ListNode* temp = Next->next;
			Next->next = temp->next;
			temp->next = Next;
			cur->next = temp;
			cur = cur->next->next;
		}
		return dummy->next;
	}

	ListNode* Input()
	{
		int quantum, data;
		cin >> quantum >> data;
		ListNode* head = new ListNode(data);
		ListNode* cur = head;
		for (int index = 1;index < quantum; index++)
		{
			cin >> data;
			cur->next = new ListNode(data);
			cur = cur->next;
		}
		return head;
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
	ListNode* List = sol.Input();
	ListNode* result = sol.swapPairs(List);
	sol.Output(result);
	return 0;
}