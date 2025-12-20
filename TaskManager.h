
#ifndef C___PROJECT_TASKMANAGER_H
#define C___PROJECT_TASKMANAGER_H

#include <memory>
#include "Task.h"

class TaskManager {
private:
    std::unique_ptr<Task[]> tasks;
    int size;
    int capacity;

    void resize();

public:
    TaskManager(int initialCapacity);

    void addTask(const std::string& desc);
    void removeTask(int id);
    void listTasks() const;
};

#endif //C___PROJECT_TASKMANAGER_H
