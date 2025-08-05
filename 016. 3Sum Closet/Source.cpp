#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int goal = nums[0] + nums[1] + nums[2];
        for (int index = 0;index < nums.size() - 2;index++)
        {
            int left = index + 1, right = nums.size() - 1;
            while(left<right)
            {
                int sum = nums[index] + nums[left] + nums[right];
                if (sum == target)
                    return sum;
                int aim = (target - sum > 0) ? (target - sum) : -(target - sum);   
                int dis = ((target - goal) > 0) ? (target - goal) : -(target - goal);
                if (dis > aim)
                    goal = sum;
                if (sum < target)
                    left++;
                else
                    right--;
            }
        }
        return goal;
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
    int result = sol.threeSumClosest(nums, target);
    cout << result;
    return 0;
}