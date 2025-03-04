#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int most_k_chars(string &s, int k)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        int map[26] = {};
        long long int num = 0;
        int left = 0;
        int dist = 0;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i] - 'a']++;
            if (map[s[i] - 'a'] == 1)
            {
                dist++;
            }
            while (dist > k)
            {
                map[s[left] - 'a']--;
                if (map[s[left] - 'a'] == 0)
                {
                    dist--;
                }
                left++;
            }
            num = num + (i - left + 1);
        }
        return num;
    }
    long long int substrCount(string s, int k)
    {
        return most_k_chars(s, k) - most_k_chars(s, k - 1);
    }
};

int main()
{
    string str = "abaaca";
    int k = 1;

    return 0;
}