#include <iostream>
#include "Task.h"
#include "TaskManager.h"

// =====================
// Part A Helper Function
// =====================
void completeTask(Task* t) {
    if (t != nullptr) {
        t->markCompleted();
    }
}

// =====================
// Part B Functions
// =====================
void addTask(Task* tasks, int& size, int capacity, const std::string& desc) {
    if (size >= capacity) {
        std::cout << "Task list is full.\n";
        return;
    }
    tasks[size] = Task(size + 1, desc);
    size++;
}

void removeTask(Task* tasks, int& size, int id) {
    for (int i = 0; i < size; i++) {
        if ((tasks + i)->getId() == id) {
            for (int j = i; j < size - 1; j++) {
                *(tasks + j) = *(tasks + j + 1);
            }
            size--;
            return;
        }
    }
}

void listTasks(Task* tasks, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << (tasks + i)->getId()
                  << ". " << (tasks + i)->getDescription()
                  << std::endl;
    }
}

// =====================
// MAIN
// =====================
int main() {

    // =====================
    // Part A — Stack Objects
    // =====================
    std::cout << "=== Part A: Stack Pointers ===\n";

    Task t1(1, "Finish project");
    Task t2(2, "Study for exam");

    Task* p1 = &t1;
    Task* p2 = &t2;

    completeTask(p1);

    std::cout << p1->getDescription()
              << (p1->isCompleted() ? " [Done]\n" : "\n");

    std::cout << p2->getDescription()
              << (p2->isCompleted() ? " [Done]\n" : "\n");

    // =====================
    // Part B — Raw Heap Pointers
    // =====================
    std::cout << "\n=== Part B: Dynamic Raw Pointers ===\n";

    int capacity = 5;
    int size = 0;
    Task* tasks = new Task[capacity];

    addTask(tasks, size, capacity, "Read book");
    addTask(tasks, size, capacity, "Write report");
    addTask(tasks, size, capacity, "Go to gym");

    listTasks(tasks, size);
    removeTask(tasks, size, 2);

    std::cout << "\nAfter removal:\n";
    listTasks(tasks, size);

    delete[] tasks; 

    // =====================
    // Part C — Smart Pointers
    // =====================
    std::cout << "\n=== Part C: unique_ptr Task Manager ===\n";

    TaskManager manager(3);
    manager.addTask("Clean room");
    manager.addTask("Finish Finals");
    manager.addTask("Call family");

    manager.listTasks();
    manager.removeTask(2);

    std::cout << "\nAfter removal:\n";
    manager.listTasks();

    return 0;
}
