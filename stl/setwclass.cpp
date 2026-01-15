#include <iostream>
#include <set>
#include <string>

template <typename T, typename C>
void print_set(std::set<T, C>& s) {
    for (const auto& elem : s) {
        std::cout << elem << " " << std::endl;
    }
}

class Todo {
    int priority;
    std::string job_desc;

    public:
        Todo(int priority, std::string job_desc)
            :   priority(priority), job_desc(job_desc) {}

        // bool operator<(const Todo& t) const {
        //     if (priority == t.priority) {
        //         return job_desc < t.job_desc;
        //     }
        //     return priority > t.priority;
        // }
    friend struct TodoCmp;

    friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

struct TodoCmp {
    bool operator()(const Todo& t1, const Todo& t2) const {
        if (t1.priority == t2.priority) {
            return t1.job_desc < t2.job_desc;
        }
        return t1.priority > t2.priority;
    }
};

std::ostream& operator<<(std::ostream& o, const Todo& td) {
    o << "[ priority: " << td.priority << "] " << td.job_desc;
    return o;
}

int main() {
    std::set<Todo, TodoCmp> todos;

    todos.insert(Todo(1, "Basketball"));
    todos.insert(Todo(2, "Math homework"));
    todos.insert(Todo(1, "Programming project"));
    todos.insert(Todo(3, "Meet friends"));
    todos.insert(Todo(2, "Watch movie"));

    print_set(todos);

    std::cout << "-------------" << std::endl;
    std::cout << "When you finish the homework!" << std::endl;
    todos.erase(todos.find(Todo(2, "Math homework")));
    print_set(todos);
}
