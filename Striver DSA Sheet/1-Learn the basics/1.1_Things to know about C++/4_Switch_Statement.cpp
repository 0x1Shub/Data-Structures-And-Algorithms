#include <bits/stdc++.h>
using namespace std;

int main()
{
    char grade = 'B';

    switch (grade)
    {
    case 'A':
        cout << "Excellent!" << endl;
        break;
    case 'B':
        cout << "Good!" << endl;
        break;
    case 'C':
        cout << "Work Hard" << endl;
        break;
    default:
        cout << "Not Specified" << endl;
        break;
    }

    return 0;
}