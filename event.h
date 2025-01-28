#ifndef EVENT_H
#define EVENT_H

using namespace std;

struct Event
{
    string name;
    int id;
    string date;
    string event_time;
    int priority;

    void print() const;

    bool operator>(const Event &other) const;
    bool operator<(const Event &other) const;
    /*
    these are used to overload the ">" operator  and "<" operators so when comparing events
    we can compare the events themselves like event1 >event2  or event1 < event2 instead 
    of event1->priority > event2->priority
    */
    static int nextId;
    static Event AddEvent();

    Event(string name = "", string date = "", string event_time = "", int priority = 0)
        : name(name), date(date), event_time(event_time), priority(priority), id(nextId++) {};
};

#endif