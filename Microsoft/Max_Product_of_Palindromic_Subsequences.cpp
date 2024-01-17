#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string &s1, string &s2, int &ans, int indx, int len, string s)
    {
        // Generate all possible subsequence and check if they are palindrome if yes calculate maximu answer
        if (indx >= len)
        {
            if (isPalindrome(s1) && isPalindrome(s2))
            {
                int curr = s1.size() * s2.size();
                ans = max(ans, curr);
            }
            return;
        }
        solve(s1, s2, ans, indx + 1, len, s);
        s1.push_back(s[indx]);
        solve(s1, s2, ans, indx + 1, len, s);
        s1.pop_back();
        s2.push_back(s[indx]);
        solve(s1, s2, ans, indx + 1, len, s);
        s2.pop_back();
    }
    int maxProduct(string s)
    {
        int len = s.length();
        string s1 = "", s2 = "";
        int ans = INT_MIN;
        solve(s1, s2, ans, 0, len, s);
        return ans;
    }
};

int main()
{
    string s1;
    cin >> s1;
    Solution obj;
    int ans = obj.maxProduct(s1);
    cout << ans << "\n";
    return 0;
}
