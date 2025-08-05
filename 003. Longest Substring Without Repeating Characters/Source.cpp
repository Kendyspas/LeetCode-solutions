#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int length = s.length();
        int left = 0, right = 0, MaxUp = 0;
        unordered_set<char> Windown;
        while(right<length)
            if (Windown.count(s[right]) == 0)
            {
                Windown.insert(s[right]);
                MaxUp = max(MaxUp, right - left + 1);
                right++;
            }
            else
            {
                Windown.erase(s[left]);
                left++;
            }
        return MaxUp;
    }
};

int main()
{
    Solution sol;
    string s;
    getline(cin, s);
    int result = sol.lengthOfLongestSubstring(s);
    cout << result;
    return 0;
}
