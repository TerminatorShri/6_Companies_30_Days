#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool isSafe(vector<vector<int>> &isWater, int x, int y,
                vector<vector<int>> &ans)
    {
        // Cell is valid if co-ordinates are valid and it is not water cell and it is not visited
        if (x < 0 || y < 0 || x == isWater.size() || y == isWater[0].size() ||
            isWater[x][y] == 1 || ans[x][y] > 0)
            return false;
        return true;
    }
    void bfs(vector<vector<int>> &isWater, vector<vector<int>> &ans,
             queue<pair<int, int>> &q)
    {
        // Standard bfs
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                int height = ans[i][j];
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (isSafe(isWater, ni, nj, ans))
                    {
                        // Assign height according to nearby cell and then again push in queue for bfs
                        ans[ni][nj] = height + 1;
                        q.push({ni, nj});
                    }
                }
            }
        }
    }
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int r = isWater.size(), c = isWater[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (isWater[i][j])
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        bfs(isWater, ans, q);
        return ans;
    }
};

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> isWater(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> isWater[i][j];
        }
    }
    Solution obj;
    vector<vector<int>> ans = obj.highestPeak(isWater);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}