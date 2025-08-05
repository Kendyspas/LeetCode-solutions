#include<iostream>
using namespace std;

class Solution 
{
public:
    int reverse(int x)
    {
        int cur = 0;
        while (x)
        {
            int m = x % 10;
            x /= 10;
            if ((cur > INT_MAX / 10) || (cur == INT_MAX / 10 && m > 7))
                return 0;
            if ((cur < INT_MIN / 10) || (cur == INT_MIN / 10 && m < -8))
                return 0;
            cur = cur * 10 + m;
        }
        return cur;
    }
};

int main()
{
    int x;
    cin >> x;
    Solution sol;
    int result = sol.reverse(x);
    cout << result;
    return 0;
}