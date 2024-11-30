// String to Integer (atoi)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxVal = INT_MAX;
    int minVal = INT_MIN;

    int recursiveapp(string &s, int index, int n, double result, int sign)
    {
        if (s[index] < '0' || s[index] > '9')
            return result;
        result = result * 10 + (sign * (s[index] - '0'));
        if (result <= minVal)
            return minVal;
        if (result >= maxVal)
            return maxVal;

        return recursiveapp(s, index + 1, n, result, sign);
    }

    int myAtoi(string s)
    {

        int sign = 1;
        int n = s.length();
        int index = 0;
        int result = 0;

        if (n == 0)
            return 0;

        while (index < n && s[index] == ' ')
            index++;

        if (index == n)
            return 0;

        if (s[index] == '+')
        {
            sign = 1;
            index++;
        }
        else if (s[index] == '-')
        {
            sign = -1;
            index++;
        }

        return recursiveapp(s, index, n, 0, sign);
    }
};

int main()
{
    Solution sol;
    vector<string> testCases = {"42", " -42", "4193 with words", "words and 987", "-91283472332", "3.14159"};
    for (const string &test : testCases)
    {
        cout << "Input: \"" << test << "\" => Output: " << sol.myAtoi(test) << endl;
    }
    return 0;
}