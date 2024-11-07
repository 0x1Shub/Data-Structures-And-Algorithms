// Data Type - Character, Integer, Long, Float and Double

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dataType(string str)
    {
        int n = str.size();
        if (str == "Character")
        {
            return sizeof(char);
        }
        else if (str == "Integer")
        {
            return sizeof(int);
        }
        else if (str == "Long")
        {
            return sizeof(long);
        }
        else if (str == "Float")
        {
            return sizeof(float);
        }
        else if (str == "Double")
        {
            return sizeof(double);
        }
    }
};

int main()
{
    Solution sol;
    cout << "Size of Integer: " << sol.dataType("Integer") << endl;
    return 0;
}