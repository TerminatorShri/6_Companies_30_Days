#include <bits/stdc++.h>
using namespace std;

/*
Platform => GeeksForGeeks
Difficulty => Medium
*/

class Solution
{
public:
    vector<int> findTwoElement(vector<int> vec, int n)
    {
        // code here
        int arr[n + 1] = {0};
        for (auto it : vec)
        {
            arr[it]++; // Store frequency of each element
        }
        int miss, twice;
        for (int i = 1; i <= n; i++)
        {
            // Store index with zero and two frequency for missing an repeating element resp
            if (arr[i] == 0)
                miss = i; // 
            if (arr[i] == 2)
                twice = i;
        }
        vector<int> ans;
        ans.push_back(twice);
        ans.push_back(miss);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution obj;
    vector<int> ans = obj.findTwoElement(v, n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}