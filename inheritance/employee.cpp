#include <iostream>
#include <string>

class Employee {
    protected:
        std::string name;
        int age;

        std::string position;
        int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank)
            :   name(name), age(age), position(position), rank(rank) {}

        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        Employee() {}

        virtual void print_info() {
            std::cout << name << " (" << position << " , " << age << ") ==> " 
            << calculate_pay() << "won(10k) " << std::endl;
        }
        virtual int calculate_pay() { return 200 + rank * 50; }
};

class Manager : public Employee {
    int year_of_service;

    public:
        Manager(std::string name, int age, std::string position, int rank, int year_of_service)
            :   year_of_service(year_of_service), Employee(name, age, position, rank) {}

        Manager(const Manager& manager)
            :   Employee(manager.name, manager.age, manager.position, manager.rank) {
                year_of_service = manager.year_of_service;
            }

        Manager() : Employee() {}

        int calculate_pay() override { return 200 + rank * 50 + 5 * year_of_service; }
        void print_info() override {
            std::cout << name << " (" << position << " , " << age << " , "
            << year_of_service << "years) ==> " << calculate_pay() << "won(10k)" << std::endl;
        }
};

class EmployeeList {
    int alloc_employee;
    int current_employee;

    Employee **employee_list;

    public:
        EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
            employee_list = new Employee*[alloc_employee];
            current_employee = 0;
        }

        void add_employee(Employee* employee) {
            if (current_employee == alloc_employee) {
                Employee **temp = new Employee*[alloc_employee*2];
                for (int i = 0; i < current_employee; i++) {
                    temp[i] = employee_list[i];
                }

                delete[] employee_list;
                employee_list = temp;
                for (int i = 0; i < current_employee; i++) {
                    delete temp[i];
                }
                delete[] temp;
                alloc_employee *= 2;
            }

            employee_list[current_employee] = employee;
            current_employee++;
        }

        int current_employee_num() { return current_employee; }

        void print_employee_info() {
            int total_pay = 0;
            for (int i = 0; i < current_employee; i++) {
                employee_list[i]->print_info();
                total_pay += employee_list[i]->calculate_pay();
            }

            std::cout << "total cost : " << total_pay << "won(10k) " << std::endl;
        }

        ~EmployeeList() {
            for (int i = 0; i < current_employee; i++) {
                delete employee_list[i];
            }
            delete[] employee_list;
        }
};

int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("No", 34, "Normal", 1));
    emp_list.add_employee(new Employee("Ha", 34, "Normal", 1));

    emp_list.add_employee(new Manager("Yoo", 41, "hod", 7, 12));
    emp_list.add_employee(new Manager("JungJ", 43, "hos", 4, 15));
    emp_list.add_employee(new Manager("Park", 43, "dhod", 5, 13));
    emp_list.add_employee(new Employee("JungH", 36, "dhos", 2));
    emp_list.add_employee(new Employee("Gill", 36, "Intern", -2));
    emp_list.print_employee_info();
    return 0;
}
