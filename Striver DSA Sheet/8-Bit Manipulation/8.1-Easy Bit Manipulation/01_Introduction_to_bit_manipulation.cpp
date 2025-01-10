#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bitManipulation(int num, int i)
    {
        int ith_bit = (num >> i - 1) & 1;
        int set_ith_bit = (num | (1 << i - 1));
        int clear_bit = (num & ~(1 << i - 1));
        cout << ith_bit << " " << set_ith_bit << " " << clear_bit << endl;
    }
};

int main()
{
    int num = 70;
    int i = 3;
    Solution sol;
    sol.bitManipulation(num, i);

    return 0;
}