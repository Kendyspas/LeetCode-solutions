#include<iostream>
#include<vector>
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
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		if (lists.empty())
			return nullptr;
		int quantum = lists.size();
		ListNode* head = lists[0];
		ListNode* dummy = new ListNode(0, head);
		for (int index = 1;index < quantum; index++)
		{
			ListNode* pre = dummy;
			ListNode* cur1 = dummy->next;
			ListNode* cur2 = lists[index];
			while (cur1 && cur2)
			{
				if (cur1->val < cur2->val)
				{
					pre->next = cur1;
					cur1 = cur1->next;
					pre = pre->next;
				}
				else
				{
					pre->next = cur2;
					cur2 = cur2->next;
					pre = pre->next;
				}
			}
			while (cur1)
			{
				pre->next = cur1;
				cur1 = cur1->next;
				pre = pre->next;
			}
			while (cur2)
			{
				pre->next = cur2;
				cur2 = cur2->next;
				pre = pre->next;
			}
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
	int quantum;
	cin >> quantum;
	vector<ListNode*>List(quantum);
	Solution sol;
	for (int index = 0;index < quantum; index++)
	{
		List[index] = sol.Input();
	}
	ListNode* result = sol.mergeKLists(List);
	sol.Output(result);
	return 0;
}