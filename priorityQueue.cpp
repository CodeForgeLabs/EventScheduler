#include <vector>
#include <iostream>
#include "event.h" 
#include <unordered_map>

using namespace std;

class PriorityQueue
{
private:
    vector<Event> heap;
    unordered_map<int,int> eventIndexMap;
    int size;

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }

    void heapifyUp(int index)
    {
        while (index != 0 && heap[parent(index)] < heap[index])
        { 
            swap(heap[index], heap[parent(index)]);
            eventIndexMap[heap[index].id] = index; //updating the map with the correct index               
            eventIndexMap[heap[parent(index)].id] = parent(index);  //updating the map with the correct index for the parent 
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        if (left < heap.size() && heap[left] > heap[largest]) 
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest]) 
            largest = right;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            eventIndexMap[heap[index].id] = index;      
            eventIndexMap[heap[largest].id] = largest; 
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() {};

    void clear(){
        heap.clear();
        eventIndexMap.clear();
    }

    Event *findEventById(int id)
    {
       if (eventIndexMap.find(id) != eventIndexMap.end())
       {
        return &heap[eventIndexMap[id]];
       }
       return nullptr;
    }

    Event *findEventByName(string name)
    {
        for (auto &event : heap )
        {
            if(event.name == name){
                return &event;
            }
        }
        return nullptr;
    }

    void updateEvent(Event *event, const Event &newEvent)
    {
        if (event)
        {
            *event = newEvent;

            heapifyDown(findEventIndex(event));
            heapifyUp(findEventIndex(event));
        }
    }

    int findEventIndex(Event *event)
    {
        for (int i = 0; i < heap.size(); ++i)
        {
            if (&heap[i] == event)
            {
                return i;
            }
        }
        return -1;
    }

    void enqueue(Event event)
    {
        heap.push_back(event);
        heapifyUp(heap.size() - 1);
    }

    Event dequeue()
    {
        if (heap.empty())
        {
            cout << "Heap is empty\n";
            return Event(); 
        }

        Event maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0); 
        return maxValue;
    }

    Event peek()
    {
        if (heap.empty())
        {
            cout << "Heap is empty" << endl;
            return Event(); 
        }
        return heap[0];
    }

    bool isEmpty()
    {
        return heap.empty();
    }

    int getSize() const
    {
        return heap.size();
    }

    void printQueue()
    {
        for ( auto &event : heap)
        {
            event.print(); 
        }
        cout << endl;
    }
};
