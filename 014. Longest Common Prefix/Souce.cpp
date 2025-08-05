#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
            return "";
        string result = strs[0];
        for (int index = 1;index < strs.size();index++)
        {
            int j = 0;
            while (j < result.length() && j < strs[index].length() && result[j] == strs[index][j])
                j++;
        result = result.substr(0, j);
        if (result.empty())
            break;
        }
        return result;
    }
};

int main()
{
    int quantum;
    cin >> quantum;
    cin.ignore();
    vector<string>strs(quantum);
    for (int index = 0;index < quantum;index++)
    {
        getline(cin, strs[index]);
    }
    Solution sol;
    string result = sol.longestCommonPrefix(strs);
    for(char c:result)
        cout<<c;
    return 0;
}