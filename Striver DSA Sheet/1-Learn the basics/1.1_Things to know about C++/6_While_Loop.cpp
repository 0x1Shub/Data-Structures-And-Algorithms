// Factorial by while loop

#include <bits/stdc++.h>
using namespace std;

// Optimization of while loop

void optimization()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;

    // Using 'break' to exit the loop early when the target is found
    for (int num : numbers)
    {
        if (num == target)
        {
            cout << "Target found: " << target << endl;
            break;
        }
        cout << "Checking num: " << num << endl;
    }

    // Using 'continue' to skip specific elements
    for (int num : numbers)
    {
        if (num % 2 == 0)
        {
            continue; // Skip even numbers
        }
        cout << "Odd number: " << num << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int fact = 1;
    while (n > 0)
    {
        fact = fact * n;
        n--;
    }
    cout << fact << endl;

    cout << "\nOptimization function output:\n";
    optimization();

    return 0;
}
