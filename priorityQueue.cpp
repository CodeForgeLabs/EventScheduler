#include "priorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::~PriorityQueue()
{
    clear();
}

void PriorityQueue::insert(Event event)
{
    Node *newEvent = new Node(event);

    if (!head || head->event < event )
    {
        newEvent->next = head;
        head = newEvent;
        return;
    }

    Node *ptr = head;
    while (ptr->next && !(ptr->next->event < event))
    {
        ptr = ptr->next;
    }

    newEvent->next = ptr->next;
    ptr->next = newEvent;
}

Node *PriorityQueue::peek()
{
    if (head)
    {
        return head;
    }

    cout << "Queue is empty\n";
    return nullptr;
}

bool PriorityQueue::isEmpty()
{
    return !head;
}

void PriorityQueue::print()
{
    if (!head)
    {
        cout << "Queue is empty\n";
        return;
    }

    Node *ptr = head;
    while (ptr)
    {
        ptr->event.print();
        ptr = ptr->next;
    }
}

void PriorityQueue::clear()
{
    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}