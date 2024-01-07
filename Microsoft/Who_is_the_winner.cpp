#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        // USing queue
        queue<int> q;
        // Add all elements from 1 to n to queue
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
        }
        int cnt = 1;
        while (q.size() != 1)
        {
            if (cnt == k)
            {
                // pop() every k'th element and reset cnt to 1
                q.pop();
                cnt = 1;
            }
            else
            {
                // pop() front element and push back again in queue and increment cnt
                int temp = q.front();
                q.pop();
                q.push(temp);
                cnt++;
            }
        }
        return q.front();

        /*
            vector<int> ans(n);
            for(int i = 0; i < n; i++)
            {
                ans[i] = i + 1;
            }
            int indx = 0;
            while(ans.size() != 1)
            {
                indx = (indx + k - 1) % ans.size();
                ans.erase(ans.begin() + indx);
            }
            return ans[0];
        */
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution obj;
    cout << obj.findTheWinner(n, k) << "\n";
    return 0;
}