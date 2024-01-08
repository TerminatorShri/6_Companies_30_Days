#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Easy
*/

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int row = img.size();
        int col = img[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                // For every valid cell increment the cnt and add element in sum then store average in ans
                int sum = 0, cnt = 0;
                for (int x = max(0, i - 1); x < min(row, i + 2); x++)
                {
                    for (int y = max(0, j - 1); y < min(col, j + 2); y++)
                    {
                        sum += img[x][y];
                        cnt++;
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};

int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> img(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> img[i][j];
        }
    }
    Solution obj;
    vector<vector<int>> ans = obj.imageSmoother(img);
    for (auto it : ans)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}