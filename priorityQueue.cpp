#include "priorityQueue.h"
#include <iostream>

using namespace std;

PriorityQueue::~PriorityQueue()
{
    clear();
}

Node* PriorityQueue::findEventByName(string &name){
    Node *ptr = head;
    while (ptr)
    {
        if (ptr->event.name == name)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}

void PriorityQueue::updateEvent(Node *node,Event &newEvent){
    if (node)
    {
       node->event = newEvent;
    }
    
}

void PriorityQueue::dequeue()
{
    if (!head)
    {
        cout << "Queue is empty\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    if (head)
    {
        head->prev = nullptr; 
    }
    delete temp;
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