#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows)
    {
        if (numRows >= s.length() || numRows == 1)
            return s;
        bool test = false;
        vector<string>a(min(numRows, int(s.length())));
        string result = "";
        int index = 0;
        for (char c : s)
        {
            a[index] += c;
            if (!index || index == numRows - 1)
            {
                test = !test;
            }
            index += test ? 1 : -1;
        }
        for (string& c : a)
            result += c;
        return result;

    }
};

int main()
{
    string s;
    getline(cin, s);
    int numRows;
    cin >> numRows;
    Solution sol;
    string result = sol.convert(s, numRows);
    for (char c : result)
        cout << c;
    return 0;
}