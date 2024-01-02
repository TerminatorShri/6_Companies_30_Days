#include <bits/stdc++.h>
using namespace std;

/*
Platform => LeetCode
Difficulty => Medium
*/

class Solution
{
public:
    void solve(vector<string> &ans, string mp[], string digits, string temp, int indx)
    {
        if (indx >= digits.length())
        {
            if (temp.length() > 0)
                ans.push_back(temp);
            return;
        }
        int curr = digits[indx] - '0'; // Extract current digit from string
        string val = mp[curr];
        for (auto it : val)
        {
            temp.push_back(it);
            solve(ans, mp, digits, temp, indx + 1); // Make a recursive call for every letter corresponding to it in mapping
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string temp = "";
        solve(ans, mp, digits, temp, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    string digits;
    cin >> digits;
    vector<string> ans = s.letterCombinations(digits);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}