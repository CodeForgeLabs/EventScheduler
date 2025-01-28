#include <iostream>
#include "priorityQueue.cpp"
#include "event.h"
#include <limits>

using namespace std;

// Color codes
#define RESET "\033[0m"
#define CYAN "\033[1;36m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"

int main()
{
    PriorityQueue eventQueue;
    bool flag = true;
    string filename = "events.txt";
    eventQueue.loadFromFile(filename);

    while (flag)
    {
        cout << CYAN << "\n-------------Menu--------------\n"
             << RESET;
        cout << GREEN << "1.  Add Event\n";
        cout << "2.  View Next Event\n";
        cout << "3.  Print All Events\n";
        cout << "4.  Edit Event\n";
        cout << "5.  Remove Next Event\n";
        cout << "6.  Clear All Events\n";
        cout << "7.  Help/Instructions\n";
        cout << "8.  Exit\n\n"
             << RESET;

        cout << YELLOW << "Enter your menu selection (1-8): " << RESET;
        int choice;
        while (!(cin >> choice))
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << RED << "Invalid input. Please enter a number between 1 and 8: " << RESET;
        }

        switch (choice)
        {
        case 1:
        {
            Event newEvent = Event::AddEvent();
            eventQueue.enqueue(newEvent);
            break;
        }
        case 2:
        {
            cout << CYAN << "\nNext Event:\n"
                 << RESET;
            Event nextEvent = eventQueue.peek();
            if (!nextEvent.name.empty())
            {
                nextEvent.print();
            }
            else
            {
                cout << RED << "No events in the queue.\n\n"
                     << RESET;
            }
            break;
        }
        case 3:
            cout << CYAN << "\nAll Events:\n"
                 << RESET;
            eventQueue.printQueue();
            break;
        case 4:
        {
            cout << YELLOW << "Enter the name of the event to edit: " << RESET;
            string eventName;
            cin >> eventName;
            Event *eventToEdit = eventQueue.findEventByName(eventName);
            if (eventToEdit)
            {
                cout << GREEN << "Editing event: " << eventName << RESET << endl;
                Event updatedEvent = Event::AddEvent();
                eventQueue.updateEvent(eventToEdit, updatedEvent);
            }
            else
            {
                cout << RED << "Event not found." << RESET << endl;
            }
            break;
        }
        case 5:
        {
            eventQueue.dequeue();
            break;
        }
        case 6:
        {
            if (eventQueue.isEmpty())
            {
                cout << RED << "Queue is Empty!\n\n"
                     << RESET;
            }
            else
            {
                eventQueue.clear();
                eventQueue.clearFromFile(filename);
                cout << GREEN << "All events cleared.\n\n"
                     << RESET;
            }
            break;
        }
        case 7:
            cout << CYAN << "Instructions:\n\n"
                 << RESET;
            cout << GREEN << "1. Add Event: " << RESET << "Add a new event to the scheduler.\n";
            cout << GREEN << "2. View Next Event: " << RESET << "View the next event in the queue.\n";
            cout << GREEN << "3. Print All Events: " << RESET << "Print all events in the queue.\n";
            cout << GREEN << "4. Edit Event: " << RESET << "Edit the details of an existing event.\n";
            cout << GREEN << "5. Remove Next Event: " << RESET << "Remove the next event from the queue.\n";
            cout << GREEN << "6. Clear All Events: " << RESET << "Clear all events from the queue.\n";
            cout << GREEN << "7. Help/Instructions: " << RESET << "View instructions on how to use the scheduler.\n";
            cout << GREEN << "8. Exit: " << RESET << "Exit the scheduler.\n\n";
            break;
        case 8:
            eventQueue.saveToFile(filename);
            flag = false;
            break;
        default:
            cout << RED << "Invalid choice. Please try again.\n"
                 << RESET;
        }
    }

    return 0;
}
