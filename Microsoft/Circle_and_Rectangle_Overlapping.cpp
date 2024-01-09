#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2)
    {
        // Put given point in equation of circle and check if distance is less than radius
        auto check = [&](int x, int y)
        {
            return (((x - xCenter) * (x - xCenter)) +
                    ((y - yCenter) * (y - yCenter))) <= radius * radius;
        };
        /*
        Brute Force
        for(int i = x1; i <= x2; i++)
        {
            for(int j = y1; j <= y2; j++)
            {
                if(check(i, j)) return true;
            }
        }
        */
        // Check if circle is totally inside rectangle
        if (xCenter >= x1 && xCenter <= x2 && yCenter >= y1 && yCenter <= y2)
            return true;
        // Check if circle is present in lower half
        for (int i = x1; i <= x2; i++)
        {
            if (check(i, y1) || check(i, y2))
                return true;
        }
        // Check if circle is present in upper half
        for (int i = y1; i <= y2; i++)
        {
            if (check(x1, i) || check(x2, i))
                return true;
        }
        return false;
    }
};

int main()
{
    int rad, xc, yc, x1, y1, x2, y2;
    cin >> rad >> xc >> yc >> x1 >> y1 >> x2 >> y2;
    Solution obj;
    cout << obj.checkOverlap(rad, xc, yc, x1, y1, x2, y2);
    return 0;
}