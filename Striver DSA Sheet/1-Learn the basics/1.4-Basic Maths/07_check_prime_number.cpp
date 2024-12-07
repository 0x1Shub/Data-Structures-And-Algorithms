#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool checkPrime(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cnt = cnt + 1;
            if (n / i != i)
            {
                cnt = cnt + 1;
            }
        }
    }
    if (cnt == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n = 1483;
    bool isPrime = checkPrime(n);
    if (isPrime)
    {
        cout << n << " is a prime number." << endl;
    }
    else
    {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
