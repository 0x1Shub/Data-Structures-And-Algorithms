#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                five++;
            }
            else if (bills[i] == 10)
            {
                if (five)
                {
                    ten++;
                    five--;
                }
                else
                    return false;
            }
            else
            {
                if (five && ten)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queues of customers: ";
    for (int bill : bills)
    {
        cout << bill << " ";
    }
    cout << endl;
    Solution sol;
    bool ans = sol.lemonadeChange(bills);
    if (ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}