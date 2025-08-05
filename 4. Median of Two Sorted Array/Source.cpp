#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size() + nums2.size();
        vector<int>nums(n);
        for (int i = 0;i < nums1.size();i++)
            nums[i] = nums1[i];
        for (int i = 0;i < nums2.size();i++)
            nums[i + nums1.size()] = nums2[i];
        sort(nums.begin(), nums.end());
        if (nums.size() % 2)
            return nums[(nums.size() - 1) / 2];
        else
            return (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>nums1(n);
    vector<int>nums2(m);
    for (int i = 0;i < n;i++)
        cin >> nums1[i];
    for (int i = 0;i < m;i++)
        cin >> nums2[i];
    Solution sol;
    double result = sol.findMedianSortedArrays(nums1, nums2);
    cout << fixed << setprecision(5) << result;
    return 0;
}