//
// CISC 192 Shada E.
//

#include "TaskManager.h"
#include <iostream>

TaskManager::TaskManager(int initialCapacity)
    : size(0), capacity(initialCapacity) {
    tasks = std::make_unique<Task[]>(capacity);
}

void TaskManager::resize() {
    capacity *= 2;
    auto newTasks = std::make_unique<Task[]>(capacity);

    for (int i = 0; i < size; i++) {
        newTasks[i] = tasks[i];
    }

    tasks = std::move(newTasks);
}

void TaskManager::addTask(const std::string& desc) {
    if (size == capacity) {
        resize();
    }

    tasks[size] = Task(size + 1, desc);
    size++;
}

void TaskManager::removeTask(int id) {
    for (int i = 0; i < size; i++) {
        if (tasks[i].getId() == id) {
            for (int j = i; j < size - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            size--;
            return;
        }
    }
}

void TaskManager::listTasks() const {
    for (int i = 0; i < size; i++) {
        std::cout << tasks[i].getId() << ". "
                  << tasks[i].getDescription()
                  << (tasks[i].isCompleted() ? " [Done]" : "")
                  << std::endl;
    }
}
