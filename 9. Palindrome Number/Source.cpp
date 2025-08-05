#include<iostream>
using namespace std;

class Solution 
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int initial_number = x;
        int reverse_number = 0;
        while (x)
        {
            int number = x % 10;
            if (reverse_number > (INT_MAX - number) / 10)
                return false;
            reverse_number = reverse_number * 10 + number;
            x /= 10;
        }
        if (initial_number == reverse_number)
            return true;
        else
            return false;
    }
};

int main()
{
    int number;
    cin >> number;
    Solution sol;
    if (sol.isPalindrome(number))
        cout << "true";
    else
        cout << "false";
    return 0;
}