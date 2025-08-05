#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int Number = 0;
        int index = 0;
        while (index < s.length())
        {
            if (s[index] == 'M')
            {
                Number += 1000;
                index++;
            }
            else if (s[index] == 'C' && s[index + 1] == 'M')
            {
                Number += 900;
                index += 2;
            }
            else if (s[index] == 'D')
            {
                Number += 500;
                index++;
            }
            else if (s[index] == 'C' && s[index + 1] == 'D')
            {
                Number += 400;
                index += 2;
            }
            else if (s[index] == 'C')
            {
                Number += 100;
                index++;
            }
            else if (s[index] == 'X' && s[index + 1] == 'C')
            {
                Number += 90;
                index += 2;
            }
            else if (s[index] == 'L')
            {
                Number += 50;
                index++;
            }
            else if (s[index] == 'X' && s[index + 1] == 'L')
            {
                Number += 40;
                index += 2;
            }
            else if (s[index] == 'X')
            {
                Number += 10;
                index++;
            }
            else if (s[index] == 'I' && s[index + 1] == 'X')
            {
                Number += 9;
                index += 2;
            }
            else if (s[index] == 'V')
            {
                Number += 5;
                index++;
            }
            else if (s[index] == 'I' && s[index + 1] == 'V')
            {
                Number += 4;
                index += 2;
            }
            else if (s[index] == 'I')
            {
                Number++;
                index++;
            }
        }
        return Number;
    }
};

int main()
{
    string s;
    getline(cin, s);
    Solution sol;
    int result = sol.romanToInt(s);
    cout << result;
    return 0;
}