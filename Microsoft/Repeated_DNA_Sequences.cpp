#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int len = s.length();
        map<string, int> mp;
        // Find all possible substring of length 10
        for (int i = 0; i <= len - 10; i++)
        {
            string curr = s.substr(i, 10);
            mp[curr]++;
        }
        vector<string> ans;
        for (auto it : mp)
        {
            // If occurence is greater than 1 store the string
            if (it.second > 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    string s;
    cin >> s;
    vector<string> ans = obj.findRepeatedDnaSequences(s);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}