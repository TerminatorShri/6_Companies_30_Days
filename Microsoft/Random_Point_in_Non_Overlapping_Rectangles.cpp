#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    vector<vector<int>> temp;
    int i = 0, x, y;
    Solution(vector<vector<int>> &rects)
    {
        temp = rects;
        i = 0;
        x = temp[i][0];
        y = temp[i][1];
    }

    vector<int> pick()
    {
        // Store current co-ordinates as answer
        vector<int> ans = {x, y};
        // Iterate over the current row horizontally
        x++;
        // If reached perimeter get back to starting point and increment y co-ordinate by 1
        if (x > temp[i][2])
        {
            x = temp[i][0];
            y++;
        }
        // If y co-ordinate has reached maximum height
        if (y > temp[i][3])
        {
            // If more rectangles are remaining switch to next one
            if (i < temp.size() - 1)
            {
                i++;
            }
            // Get back to first rectangle
            else
            {
                i = 0;
            }
            x = temp[i][0];
            y = temp[i][1];
        }
        return ans;
    }
};

int main()
{
    int sz;
    cin >> sz;
    vector<vector<int>> rects(sz, vector<int>(4));
    for (int i = 0; i < sz; i++)
    {
        cin >> rects[i][0] >> rects[i][1] >> rects[i][2] >> rects[i][3];
    }
    Solution obj(rects);
    vector<int> ans = obj.pick();
    cout << ans[0] << ans[1] << "\n";
    return 0;
}