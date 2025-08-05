#include<iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int data) :val(data), next(nullptr) {}
	ListNode(int data, ListNode* next) : val(data), next(next) {}
};

class Solution 
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* dummy = new ListNode(0,head);		
		ListNode* cur = dummy;
		ListNode* tail = head;
		int Number = 0;
		while (tail)
		{
			Number++;
			tail = tail->next;
		}
		for (int index = 0;index < Number - n;index++)
			cur = cur->next;
		ListNode* temp = cur->next;
		cur->next = temp->next;
		delete temp;
		ListNode* headList = dummy->next;
		return headList;
	}
	ListNode* Input(int quantum)
	{
		int data;
		cin >> data;
		ListNode* head = new ListNode(data);
		ListNode* cur = head;
		for (int index = 1;index < quantum;index++)
		{
			cin >> data;
			cur->next = new ListNode(data);
			cur = cur->next;
		}
		return head;
	}
	void Output(ListNode* head)
	{
		ListNode* cur = head;
		while (cur)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
	}
};

int main()
{
	int quantum, n;
	cin >> quantum;
	Solution sol;
	ListNode* head = sol.Input(quantum);
	cin >> n;
	ListNode* result = sol.removeNthFromEnd(head, n);
	sol.Output(result);
	return 0;
}