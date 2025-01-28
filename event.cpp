#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <string>
#include <ctime>
#include "event.h"

using namespace std;



//intializing static counter
int Event::nextId = 0;

bool Event::operator>(const Event &other) const
{
    if (priority != other.priority)
    {
        return priority > other.priority;
    }
    else
    {
        if (date != other.date)
        {
            return date < other.date;
        }
        else
        {
            return event_time < other.event_time;
        }
    }
}

bool Event::operator<(const Event &other) const
{
    if (priority != other.priority)
    {
        return priority < other.priority;
    }
    else
    {
        if (date != other.date)
        {
            return date > other.date;
        }
        else
        {
            return event_time > other.event_time;
        }
    }
}

Event Event::AddEvent()
{
    string name, date, event_time;
    int priority;
    nextId += 1;
    cout << "Add name of event: ";
    cin >> name;
    tm date_tm = {};
    while (true)
    {
        cout << "Set date of event (YYYY-MM-DD): ";
        cin >> date;
        stringstream ss(date);
        ss >> get_time(&date_tm, "%Y-%m-%d");
        if (ss.fail())
        {
            cout << "Invalid date format. Please try again." << endl;
            ss.clear();
        }
        else
        {
            time_t now = time(0);
            tm *now_tm = localtime(&now);
            if (mktime(&date_tm) <= mktime(now_tm))
            {
                cout << "The date is in the past. Please enter a future date." << endl;
            }
            else
            {
                break;
            }
        }
    }
    tm time_tm = {};
    while (true)
    {
        cout << "Set time of event (HH:MM): ";
        cin >> event_time;
        stringstream ss(event_time);
        ss >> get_time(&time_tm, "%H:%M");
        if (ss.fail())
        {
            cout << "Invalid time format. Please try again." << endl;
            ss.clear();
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Set priority of event: ";
        cin >> priority;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    return Event(name, date, event_time, priority);
}

// Print method
void Event::print() const
{
    cout << "ID: " << id
         << ", Name: " << name
         << ", Date: " << date
         << ", Time: " << event_time
         << ", Priority: " << priority << endl;
}