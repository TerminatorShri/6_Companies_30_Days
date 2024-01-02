#include <bits/stdc++.h>
using namespace std;

/*
Platform => LeetCode
Difficulty => Medium
*/

class Solution
{
    int n, m, i = 0, j = 0;

public:
    Solution(int m, int n)
    {
        this->n = n;
        this->m = m;
    }

    vector<int> flip()
    {
        int ans_i = i, ans_j = j;
        if (j + 1 < n) // Iterate over row
            j++;
        else if (i + 1 < m) // Shift to next row
        {
            i++;
            j = 0;
        }
        else // If all flipped start again
        {
            i = 0;
            j = 0;
        }
        return {ans_i, ans_j};
    }

    void reset()
    {
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Solution obj(n, m);
    vector<int> ans = obj.flip();
    for (auto it : ans)
        cout << it << " ";
    return 0;
}