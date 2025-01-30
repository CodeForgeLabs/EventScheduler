# Event Scheduler

## Overview

The Event Scheduler is a C++ application that allows users to manage events with priorities and times.
It uses a priority queue to ensure that events are processed based on their priority and time of occurrence.

## Features

- Add new events with a name, date, time, and priority.
- View the next event in the queue.
- Print all events in the queue.
- Edit existing events.
- Remove the next event from the queue.
- Clear all events from the queue.
- Display help/instructions.
- Exit the application.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++)
- Make (optional, for using the provided Makefile)

### Building the Project

1. Clone the repository:

   ```sh
   git clone https://github.com/CodeForgeLabs/EventScheduler
   ```

2. Go to the cloned repository and run the make command(need Make for this to work)

   ```sh
   cd EventScheduler
   make
   ```
   or alternatively run the following command
   ```sh
   cd EventScheduler
   g++ main.cpp priorityQueue.cpp event.cpp -o main
   ```
   

3. Run the executable

   ```sh
   ./main
   ```

