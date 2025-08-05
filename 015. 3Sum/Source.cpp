#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        for (int index = 0;index < nums.size() - 2;index++)
        {
            if (index > 0 && nums[index] == nums[index - 1])
                continue;
            int left = index + 1, right = nums.size() - 1;
            while(left<right)
            {
                int target = nums[index] + nums[left] + nums[right];
                if (!target)
                {
                    result.push_back({ nums[index], nums[left], nums[right] });
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }                   
                else if (target > 0)
                    right--;
                else
                    left++;
            }
        }
        return result;
    }
};

int main()
{
    int quantum;
    cin >> quantum;
    vector<int>nums(quantum);
    for (int index = 0;index < quantum;index++)
        cin >> nums[index];
    Solution sol;
    vector<vector<int>>result = sol.threeSum(nums);
    for (auto triplet : result)
    {
        for (int num : triplet)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}