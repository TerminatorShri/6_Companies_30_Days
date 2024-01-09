#include <bits/stdc++.h>
using namespace std;

/*
Platform => Leetcode
Difficulty => Medium
*/

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int x = 0;
        int len = secret.length();
        map<char, int> mp1, mp2;
        // Count number of Bulls i.e. if char at index is same otherwise store count of char in different maps for secret and guess
        for (int i = 0; i < len; i++)
        {
            if (secret[i] == guess[i])
                x++;
            else
            {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        int y = 0;
        for (auto it1 : mp1)
        {
            // Find if current element in guess
            auto it2 = mp2.find(it1.first);
            if (it2 != mp2.end())
            {
                // If number of occurences in guess (except for bulls) is greater than in secret add count of occurences from guess
                // Secret = "1234" Guess = "0111"
                if (it2->second >= it1.second)
                {
                    y += it1.second;
                }
                // Else add occurences from guess as that is the minimum number of elements that can be considered to be wrongly located
                // Secret = "1122" Guess = "0001"
                else
                {
                    y += it2->second;
                }
            }
        }
        return to_string(x) + "A" + to_string(y) + "B";
    }
};

int main()
{
    string secret, guess;
    cin >> secret >> guess;
    Solution obj;
    cout << obj.getHint(secret, guess) << "\n";
    return 0;
}