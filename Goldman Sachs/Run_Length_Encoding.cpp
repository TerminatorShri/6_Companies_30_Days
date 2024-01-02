#include <bits/stdc++.h>
using namespace std;
/*
PLATFORM => GeeksForGeeks
Difficulty => Easy
*/
/*You are required to complete this function */

string encode(string src)
{
    // Your code here
    int sz = src.length();
    string ans = "";
    int cnt = 1; //Set the count to 1 as we are considering first variable is counted
    for (int i = 1; i < sz; i++)
    {
        if (src[i] == src[i - 1]) //If character at current index is equal to charcter at previous index increment count
            cnt++;
        else // Else store the previous charcter and its count in ans string
        {
            ans += src[i - 1];
            ans += to_string(cnt);
            cnt = 1;
        }
    }
    ans += src[sz - 1] + to_string(cnt); //Store the count of last consecutive charcters counted
    return ans;
}

int main()
{
    string temp;
    cin >> temp;
    string ans = encode(temp);
    cout << ans << "\n";
    return 0;
}