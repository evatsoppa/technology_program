#include <iostream>
#include <string>

struct Node {
    std::string name;
    int age;
    double salary;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addToBeginning(std::string name, int age, double salary) {
        Node* newNode = new Node{ name, age, salary, head };
        head = newNode;
    }

    void addToEnd(std::string name, int age, double salary) {
        Node* newNode = new Node{ name, age, salary, nullptr };

        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Добавление элемента после указанного элемента (по имени)
    void addAfter(std::string targetName, std::string name, int age, double salary) {
        Node* current = head;
        while (current && current->name != targetName) {
            current = current->next;
        }

        if (current) {
            Node* newNode = new Node{ name, age, salary, current->next };
            current->next = newNode;
        }
    }

    // Удаление элемента по имени
    void remove(std::string targetName) {
        if (!head) return;

        if (head->name == targetName) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next && current->next->name != targetName) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Вывод списка на экран
    void displayList() {
        Node* current = head;
        while (current) {
            std::cout << "Name: " << current->name << ", Age: " << current->age << ", Salary: " << current->salary << std::endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList myList;

    myList.addToBeginning("John", 25, 50000.0);
    myList.addToEnd("Alice", 30, 60000.0);
    myList.addAfter("John", "Bob", 28, 55000.0);
    myList.displayList();

    myList.remove("Alice");
    myList.displayList();

    return 0;
}
