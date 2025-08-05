#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)   
    {
        int sign = 1, index = 0;
        long result = 0;
        while (s[index] == ' ')
            index++;
        if (index < s.length() && (s[index] == '+' || s[index] == '-'))
        {
            sign = (s[index] == '+') ? 1 : -1;
            index++;
        }
        while (index < s.length() && isdigit(s[index]))
        {
            int digit = s[index] - '0';
            if (result > (INT_MAX - digit) / 10)
                return (sign == 1) ? INT_MAX : INT_MIN; 
            result = result * 10 + digit;
            index++;
        }
        return sign * result;
    }
};

int main()
{
    string s;
    getline(cin, s);
    Solution sol;
    int result = sol.myAtoi(s);
    cout << result;
    return 0;
}