#include <bits/stdc++.h>
using namespace std;

void recursion(int count)
{
    if (count == 4)
    {
        return;
    }
    cout << count << endl;
    count++;
    recursion(count);
}

int main()
{
    int count = 0;
    recursion(count);
    return 0;
}