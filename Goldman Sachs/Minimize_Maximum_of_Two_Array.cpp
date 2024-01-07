#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2)
    {
        long long lcm =
            ((long long)divisor1 * divisor2) / __gcd(divisor1, divisor2);
        long long req = uniqueCnt1 + uniqueCnt2;
        long long l = req, r = 1e12;
        long long ans = 0;
        while (l <= r)
        {
            // m be total number of elements we are considering from 1 to m
            long long m = l + (r - l) / 2;
            // Gives number of elements that are divisible by both
            long long intersection = m / lcm;
            // Gives number of elements that are only divisible by divisor1
            long long acnt = m / divisor2 - intersection;
            // Gives number of elements that are only divisible by divisor2
            long long bcnt = m / divisor1 - intersection;
            // Number of elements to make 2 arrays
            req = max(0LL, uniqueCnt1 - acnt) + max(0LL, uniqueCnt2 - bcnt);
            // If in given range number of elements are greater than sum of elements for req and common to both then m can be considered
            if (m - acnt - bcnt >= req + intersection)
            {
                ans = m;
                r = m - 1;
            }
            // Else we have to increment m so we are increasing lower limit
            else
            {
                l = m + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int d1, d2, c1, c2;
    cin >> d1 >> d2 >> c1 >> c2;
    Solution obj;
    cout << obj.minimizeSet(d1, d2, c1, c2) << "\n";
    return 0;
}