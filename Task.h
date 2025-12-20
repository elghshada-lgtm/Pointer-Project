#ifndef C___PROJECT_TASK_H
#define C___PROJECT_TASK_H

#include <string>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    Task();
    Task(int id, const std::string& desc);

    void markCompleted();
    bool isCompleted() const;
    int getId() const;
    std::string getDescription() const;
};

#endif //C___PROJECT_TASK_H
