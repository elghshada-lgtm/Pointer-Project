#include "Task.h"

Task::Task() : id(0), description(""), completed(false) {}

Task::Task(int id, const std::string& desc)
    : id(id), description(desc), completed(false) {}

void Task::markCompleted() {
    completed = true;
}

bool Task::isCompleted() const {
    return completed;
}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const {
    return description;
}
