#include <iostream>
#include "priorityQueue.h"
#include "event.h"
#include <limits>

using namespace std;

int main()
{
    PriorityQueue eventQueue;
    bool flag = true;

    while (flag)
    {
        cout << "---------Menu---------" << endl;
        cout << "1. Add Event\n";
        cout << "2. View Next Event\n";
        cout << "3. Print All Events\n";
        cout << "4. Edit Event\n";
        cout << "5. Remove Next Event\n";
        cout << "6. Clear All Events\n";
        cout << "7. Help/Instructions\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        while (!(cin >> choice))
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number between 1 and 8: ";
        }

        switch (choice)
        {
        case 1:
        {
            Event newEvent = Event::AddEvent();
            eventQueue.insert(newEvent);
            break;
        }
        case 2:
        {
            Node *nextEvent = eventQueue.peek();
            if (nextEvent)
            {
                nextEvent->event.print();
            }
            break;
        }
        case 3:
            eventQueue.print();
            break;
        case 4:
        {
            cout << "Coming soon!\n";
            break;
            
        }
        case 5:
        {
            eventQueue.dequeue();
            break;
        }
        case 6:
        if (eventQueue.isEmpty())
        {
            cout << "Queue is Empty!\n";
            break;
        }
        else
        {
            eventQueue.clear();
            break;
        }
        case 7:
            cout << "Instructions:\n";
            cout << "1. Add Event: Add a new event to the scheduler.\n";
            cout << "2. View Next Event: View the next event in the queue.\n";
            cout << "3. Print All Events: Print all events in the queue.\n";
            cout << "4. Edit Event: Edit the details of an existing event.\n";
            cout << "5. Remove Next Event: Remove the next event from the queue.\n";
            cout << "6. Clear All Events: Clear all events from the queue.\n";
            cout << "7. Help/Instructions: View instructions on how to use the scheduler.\n";
            cout << "8. Exit: Exit the scheduler.\n";
            break;
        case 8:
            flag = false;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}