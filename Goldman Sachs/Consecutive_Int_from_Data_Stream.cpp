#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class DataStream
{
public:
    int value, k, freq = 0;
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
        freq = 0;
    }

    bool consec(int num)
    {
        if (value == num) // Increment the count if num is equal to given value
        {
            freq++;
        }
        else // Else set count to zero
        {
            freq = 0;
        }
        return freq >= k; // Return 'true' if value has occurred more then k times consecutively else return 'false'
    }
};

int main()
{
    int val, k;
    cin >> val >> k;
    DataStream obj(val, k);
    int cnt, temp;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> temp;
        cout << obj.consec(temp) << "\n";
    }
    return 0;
}