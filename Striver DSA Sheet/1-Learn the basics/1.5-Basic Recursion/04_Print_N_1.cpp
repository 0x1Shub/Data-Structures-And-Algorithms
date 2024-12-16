#include <bits/stdc++.h>
using namespace std;

void func(int i, int n)
{

    if (i < 1)
        return;
    cout << i << endl;

    func(i - 1, n);
}

int main()
{

    int n = 4;
    func(n, n);
    return 0;
}
