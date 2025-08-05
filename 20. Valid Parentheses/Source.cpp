#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char>par;
        if (s.empty())
            return true;
        for (char letter : s)
        {
            if (letter == '(' || letter == '[' || letter == '{')
                par.push(letter);
            else
            {
                if (par.empty())
                    return false;
                char top = par.top();
                if ((top == '(' && letter != ')') || (top == '[' && letter != ']') || (top == '{' && letter != '}'))
                    return false;
                par.pop();
            }         
        }
        return par.empty();
    }
};

int main()
{
    string parenthese;
    getline(cin, parenthese);
    Solution sol;
    if (sol.isValid(parenthese))
        cout << "True";
    else
        cout << "False";
    return 0;
}