#include <bits/stdc++.h>
using namespace std;

void func(int i, int n)
{

    if (i > n)
        return;
    cout << "Tiger" << endl;
    func(i + 1, n);
}

int main()
{
    int n = 4;
    func(1, n);
    return 0;
}