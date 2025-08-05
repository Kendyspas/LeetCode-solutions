#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>>result;
        int n = nums.size();
        for (int index = 0;index < n - 3;index++)
        {
            if (index > 0 && nums[index] == nums[index - 1])
                continue;
            for (int j = index + 1;j < n - 2;j++)
            {
                if (j > index + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = n - 1;
                while(left<right)
                {
                    long long sum = (long long)nums[index] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        result.push_back({ nums[index] , nums[j] , nums[left] , nums[right] });
                        while (left + 1 < right && nums[left] == nums[left + 1])
                            left++;
                        while (left < right - 1 && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return result;
    }
};

int main()
{
    int quantum, target;
    cin >> quantum;
    vector<int>nums(quantum);
    for (int index = 0;index < quantum;index++)
        cin >> nums[index];
    cin >> target;
    Solution sol;
    vector<vector<int>>result = sol.fourSum(nums, target);
    for (auto Array : result)
    {
        for (int number : Array)
            cout << number << " ";
        cout << endl;
    }
    return 0;
}