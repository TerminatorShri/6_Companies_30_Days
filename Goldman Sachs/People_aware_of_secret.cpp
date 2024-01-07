#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int dp[1001];
    int mod = 1e9 + 7;
    int solve(int day, int delay, int forget, int n)
    {
        int start_telling = day + delay;
        int will_forget = day + forget;
        int ans = 0;
        if (will_forget > n) // If day on which one will forget is > n increment ans
            ans++;
        if (dp[day] != -1)
            return dp[day];
        for (int j = start_telling; j < min(will_forget, n + 1); j++)
        {
            // After delay make a recusive call for every day till one remembers secret
            (ans += solve(j, delay, forget, n)) %= mod;
        }
        return dp[day] = ans % mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        memset(dp, -1, sizeof(dp));
        return solve(1, delay, forget, n);
    }
};

int main()
{
    int n, d, f;
    cin >> n >> d >> f;
    Solution obj;
    cout << obj.peopleAwareOfSecret(n, d, f) << "\n";
    return 0;
}