#include <iostream>
#include <iomanip>
using namespace std;

class Digitalclock
{
private:
    int hour, minute, seconds;

public:
    Digitalclock(int h, int m, int s)
    {
        hour = h;
        minute = m;
        seconds = s;
    }

    void display()
    {
        if (hour < 10 || minute < 10 || seconds < 10)
        {
            cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << seconds <<" ";
        }
        else
        {
            cout<< hour << ":"<< minute << ":" <<seconds <<" ";
        }
        if (hour >= 12)
        {
            cout << "PM";
        }
        else
        {
            cout << "AM";
        }
    }
};

int main()
{
    int hour, minute, second;
    cout << "Enter Hour:";
    cin >> hour;
    cout << "Enter Minute:";
    cin >> minute;
    cout << "Enter Seconds:";
    cin >> second;
    Digitalclock clock(hour, minute, second);
    clock.display();
    return 0;
}
