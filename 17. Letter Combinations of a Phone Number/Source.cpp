#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution 
{
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits == "")
            return {};
        vector<string>maps = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
        vector<string>result = { "" };
        for (char digit : digits)
        {
            vector<string>temp;
            for (string comb : result)
                for (char letter : maps[digit - '0'])
                    temp.push_back(comb + letter);
            result = temp;
        }
        return result;
    }
};

int main()
{
    string digit;
    getline(cin, digit);
    Solution sol;
    vector<string>letter = sol.letterCombinations(digit);
    for (auto result : letter)
    {
        for (char c : result)
            cout << c;
        cout << " ";
    }
    return 0;
}