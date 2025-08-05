#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int val) : val(val), next(nullptr) {}
	ListNode(int val, ListNode* next) :val(val), next(next) {}
};

class Solution 
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* dummy=new ListNode(0);
		ListNode* cur = dummy;
		int carry_in = 0;
		while (l1 || l2 || carry_in)
		{
			int sum = carry_in;
			if (l1)
			{
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2)
			{
				sum += l2->val;
				l2 = l2->next;
			}
			cur->next = new ListNode(sum % 10);
			carry_in = sum / 10;
			cur = cur->next;
		}
		return dummy->next;
	}
	ListNode* Input()
	{
		int n,x;
		cin >> n;
		cin >> x;
		ListNode* head = new ListNode(x);
		ListNode* cur = head;
		for (int i = 1;i < n;i++)
		{
			cin >> x;
			cur->next = new ListNode(x);
			cur = cur->next;
		}
		return head;	
	}
	void Output(ListNode* l)
	{
		ListNode* cur = l;
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
	ListNode* l1 = sol.Input();
	ListNode* l2 = sol.Input();
	ListNode* result= sol.addTwoNumbers(l1, l2);
	sol.Output(result);
	return 0;
}