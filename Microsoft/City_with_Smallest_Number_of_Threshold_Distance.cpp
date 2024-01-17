#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> adj(n);
        // Make an adjecency matrix
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        // Use dijkastra's algorithm to find shortest path for each node
        int mini = INT_MAX, ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            q.push(i);
            vector<int> dis(n, INT_MAX);
            dis[i] = 0;
            while (!q.empty())
            {
                int f = q.front();
                q.pop();
                int d = dis[f];
                for (auto it : adj[f])
                {
                    int node = it.first;
                    int weight = it.second;
                    if (d + weight <= dis[node])
                    {
                        dis[node] = d + weight;
                        q.push(node);
                    }
                }
            }
            int cnt = 0;
            for (int k = 0; k < dis.size(); k++)
            {
                if (dis[k] <= distanceThreshold)
                    cnt++;
            }
            if (cnt <= mini)
            {
                mini = cnt;
                ans = i;
            }
        }
        return ans;
    }
};

int main()
{
    int n, distanceThreshold;
    cin >> n >> distanceThreshold;
    int cnt;
    vector<vector<int>> v;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        v.push_back({t1, t2, t3});
    }
    Solution obj;
    int ans = obj.findTheCity(n, v, distanceThreshold);
    cout << ans << "\n";
    return 0;
}