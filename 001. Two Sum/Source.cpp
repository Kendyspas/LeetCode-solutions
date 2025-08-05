#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target) 
                {
                    return { i, j };
                }
            }
        }
        return {};
    }
};

int main()
{
    int n, target;
    cin >> n;
    vector<int>num(n);
    for (int i = 0;i < n;i++)
        cin >> num[i];
    cin >> target;
    Solution sol;
    vector<int>result = sol.twoSum(num, target);
    for (int i = 0;i < result.size();i++)
        cout << result[i]<<" ";
    return 0;
}