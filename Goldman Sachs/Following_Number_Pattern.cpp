#include <bits/stdc++.h>
using namespace std;

/*
Platform => GeeksForGeeeks
Difficulty => Medium
*/

class Solution
{
public:
    string printMinNumberForPattern(string S)
    {
        // code here
        string ans = "";
        stack<int> st;
        int cnt = 1;
        for (auto it : S)
        {
            st.push(cnt);
            cnt += 1;
            if (it == 'I')
            {
                while (!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(cnt);
        while (!st.empty())
        {
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }
};

int main()
{
    string temp;
    cin >> temp;
    Solution obj;
    cout << obj.printMinNumberForPattern(temp) << "\n";
    return 0;
}