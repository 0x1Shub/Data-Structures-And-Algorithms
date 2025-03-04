#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    string period = s.substr(s.size() - 2, 2);
    int hour = stoi(s.substr(0, 2));
    string minutes = s.substr(3, 2);
    string seconds = s.substr(6, 2);

    if (period == "AM")
    {
        if (hour == 12)
        {
            hour = 0;
        }
    }
    else
    {
        if (hour != 12)
        {
            hour += 12;
        }
    }

    string hour_str = (hour < 10) ? "0" + to_string(hour) : to_string(hour);

    string military_time = hour_str + ":" + minutes + ":" + seconds;

    return military_time;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
