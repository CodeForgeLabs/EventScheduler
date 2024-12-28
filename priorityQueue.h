#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include "event.h"

using namespace std;

struct Node
{
    Event event;
    Node *next;
    Node *prev;

    Node(Event e) : event(e), next(nullptr), prev(nullptr) {}
};

class PriorityQueue
{
private:
    Node *head;

public:
    PriorityQueue() : head(nullptr) {};
    ~PriorityQueue();

    void insert(Event event);
    Node *peek();
    void dequeue();
    bool isEmpty() ;
    void clear();
    void print();
    Node *findEventByName(string &name);
    void updateEvent(Node *node,Event& newEvent);
};

#endif