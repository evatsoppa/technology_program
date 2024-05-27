#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// информация о студенте
struct Student {
    int id;
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// управление базой студентов
class StudentDB {
private:
    std::vector<Student> students;  // записи о студентах
    const std::string filename = "students_db.txt";  //  файл

public:
    // загружает данные из файла
    StudentDB() {
        loadFromFile();
    }

    // сохраняет данные в файл 
    ~StudentDB() {
        saveToFile();
    }

    // загрузка данных
    void loadFromFile() {
        std::ifstream file(filename);
        if (!file.is_open()) return;

        std::string line;
        while (getline(file, line)) {
            std::stringstream ss(line);
            Student student;
            ss >> student.id >> student.name >> student.age >> student.major >> student.gpa;
            students.push_back(student);
        }
        file.close();
    }

    // сохранение
    void saveToFile() {
        std::ofstream file(filename);
        for (const auto& student : students) {
            file << student.id << " " << student.name << " " << student.age << " " 
                 << student.major << " " << student.gpa << "\n";
        }
        file.close();
    }

    // добавила студента
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // редактор
    void editStudent(int id, const Student& updatedStudent) {
        for (auto& student : students) {
            if (student.id == id) {
                student = updatedStudent;
                break;
            }
        }
    }

    // удалить 
    void deleteStudent(int id) {
        students.erase(std::remove_if(students.begin(), students.end(), [id](const Student& student) { return student.id == id; }), students.end());
    }

    // поиск по айди
    void searchStudent(int id) {
        for (const auto& student : students) {
            if (student.id == id) {
                std::cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age 
                          << ", Major: " << student.major << ", GPA: " << student.gpa << "\n";
                return;
            }
        }
        std::cout << "Student not found.\n";
    }

    // список всех студентов
    void listStudents() {
        for (const auto& student : students) {
            std::cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age 
                      << ", Major: " << student.major << ", GPA: " << student.gpa << "\n";
        }
    }
};

int main() {
    StudentDB db;  
    int choice;

    do {
        std::cout << "\nSimple Student Registry Database\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Edit Student\n";
        std::cout << "3. Delete Student\n";
        std::cout << "4. Search Student\n";
        std::cout << "5. List All Students\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Student student;
                std::cout << "Enter ID: "; std::cin >> student.id;
                std::cout << "Enter Name: "; std::cin >> student.name;
                std::cout << "Enter Age: "; std::cin >> student.age;
                std::cout << "Enter Major: "; std::cin >> student.major;
                std::cout << "Enter GPA: "; std::cin >> student.gpa;
                db.addStudent(student);
                break;
            }
            case 2: {
                int id;
                Student student;
                std::cout << "Enter ID of student to edit: "; std::cin >> id;
std::cout << "Enter new Name: "; std::cin >> student.name;
                std::cout << "Enter new Age: "; std::cin >> student.age;
                std::cout << "Enter new Major: "; std::cin >> student.major;
                std::cout << "Enter new GPA: "; std::cin >> student.gpa;
                student.id = id;
                db.editStudent(id, student);
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter ID of student to delete: "; std::cin >> id;
                db.deleteStudent(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter ID of student to search: "; std::cin >> id;
                db.searchStudent(id);
                break;
            }
            case 5: {
                db.listStudents();
                break;
            }
            case 6: {
                std::cout << "Exiting...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
