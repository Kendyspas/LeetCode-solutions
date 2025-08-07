#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string>result;
		int total = 1 << 2 * n;
		for (int index = 0;index < total; index++)
		{
			int close = 0, open = 0;
			string str;
			for (int j = 2 * n - 1;j >= 0; j--)
			{
				if ((index >> j) & 1)
				{
					str += ')';
					close++;
				}
				else
				{
					str += '(';
					open++;
				}
				if (close > open)
					break;
			}
			if (close == n && open == n)
				result.push_back(str);
		}
		return result;
	}
};

int main()
{
	int number;
	Solution sol;
	cin >> number;
	vector<string>result = sol.generateParenthesis(number);
	for (auto& res : result)
		cout << res << "  ";
	return 0;
}