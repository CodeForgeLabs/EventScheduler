#include <iostream>
#include "priorityQueue.h"
#include "event.h"
#include <chrono>


using namespace std;
using namespace std::chrono;


int main() {

    int choice;
    PriorityQueue eventQueue;
    bool flag = true;
    while (flag)
    {
        cout << "---------Menu--------\n";
        cout << "1.Add Event\n";
        cout << "2.Remove Event\n";
        cout << "3.See All Events\n";
        cout << "4.Edit Event\n";
        cout << "5.Exit\n";
        cin >> choice;
        switch(choice)
        {
        case 1: {
            Event newEvent = Event::AddEvent();
            eventQueue.insert(newEvent);
            break;
        }
        case 3:
            eventQueue.print();
            break;
        case 5:
            flag = false;
            break;
        }
    }
    
    
    
    return 0;
}