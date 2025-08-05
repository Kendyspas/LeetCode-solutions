#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int maxArea = 0;
        while (left < right)
        {
            int Length = right - left;
            int Width = min(height[left], height[right]);
            int Area = Length * Width;
            if (Area > maxArea)
                maxArea = Area;
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};

int main()
{
    int quantity;
    cin >> quantity;
    vector<int>height(quantity);
    for (int index = 0;index < quantity;index++)
        cin >> height[index];
    Solution sol;
    int result = sol.maxArea(height);
    cout << result;
    return 0;
}