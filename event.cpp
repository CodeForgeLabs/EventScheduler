#include <iostream>
#include "event.h"
#include <limits>

using namespace std;

bool Event::operator<(const Event& other) const {
    if (priority != other.priority) {
        return priority < other.priority;
    } else {
        if (date != other.date) {
            return date < other.date;
        } else {
            return time < other.time;
        }
    }
}

Event Event::AddEvent() {
    string name, date, time;
    int priority;
    cout << "Add name of event: ";
    cin >> name;
    cout << "Set date of event (YYYY-MM-DD): ";
    cin >> date;
    cout << "Set time of event (HH:MM): ";
    cin >> time;
    while (true) {
        cout << "Set priority of event: ";
        cin >> priority;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    return Event(name, date, time, priority);
}

void Event::print()
{
    cout << "Name: " << name << 
            ", Date: " << date << 
            ", Time: " << time << 
            ", Priority: " << priority << endl;
}