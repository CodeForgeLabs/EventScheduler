#ifndef EVENT_H
#define EVENT_H

using namespace std;

struct Event
{
    string name;
    string date;
    string time;
    int priority;

    void print();

    bool operator<(const Event &other) const;
    /*
    this is used to overload the ">" operator so when comparing events
    we can compare the events themselves like event1 >event2 instead 
    of event1.priority > event2.priority
    */

    static Event AddEvent();

    Event() {}; //default constructor

    Event(string n, string d, string t, int p) : name(n), date(d), time(t), priority(p) {};
};

#endif