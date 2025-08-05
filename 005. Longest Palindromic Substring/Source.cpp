#include<iostream>
#include<string>
using namespace std;

class Solution
{
private:
    int Length(string& s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return "";
        int start = 0, end = 0;
        for (int i = 0;i < s.length();i++)
        {       
            int length_1 = Length(s, i, i); 
            int length_2 = Length(s, i, i + 1);
            int maxLeng = max(length_1, length_2);
            if (maxLeng > end - start + 1)
            {
                start = i - (maxLeng - 1) / 2;
                end = i + maxLeng / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);
    string result = sol.longestPalindrome(s);
    for (char c : result)
        cout << c;
    return 0;
}