#include <iostream>

// Класс для векторов
class Vector {
public:
    int dim;          // Размерность вектора
    double* elements;  // Массив элементов вектора
    int num;          // Номер вектора
    static int count;  // Счетчик созданных векторов

    // Конструктор создает вектор
    Vector(int dimension, double* array) : dim(dimension), elements(array), num(++count) {
        std::cout << "Создан вектор " << num << std::endl;
    }

    // Деструктор уничтожает вектор
    ~Vector() {
        std::cout << "Уничтожен вектор " << num << std::endl;
    }

    // Операторы векторной алгебры
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator-() const;
    double operator*(const Vector& other) const;
    Vector operator*(double scalar) const;
    Vector& operator=(const Vector& other);
};

// Статическая переменная инициализируется вне класса
int Vector::count = 0;

// Класс для матриц
class Matrix {
public:
    int dim;          // Размерность матрицы
    double* elements;  // Массив элементов матрицы
    int num;          // Номер матрицы
    static int count;  // Счетчик созданных матриц

    // Конструктор создает матрицу
    Matrix(int dimension, double* array) : dim(dimension), elements(array), num(++count) {
        std::cout << "Создана матрица " << num << std::endl;
    }

    // Деструктор уничтожает матрицу
    ~Matrix() {
        std::cout << "Уничтожена матрица " << num << std::endl;
    }

    // Операторы векторной алгебры для матрицы
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator-() const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix& operator=(const Matrix& other);

    // Оператор умножения матрицы на вектор
    Vector operator*(const Vector& vector) const;
};

// Статическая переменная инициализируется вне класса
int Matrix::count = 0;

// Главная функция, где происходит работа с векторами и матрицами
int main() {
    // Создаем векторы
    double arr1[] = {1.0, 2.0, 3.0};
    double arr2[] = {4.0, 5.0, 6.0};
    Vector vector1(3, arr1);
    Vector vector2(3, arr2);

    // Создаем матрицы
    double arr3[] = {7.0, 8.0, 9.0};
    Matrix matrix1(3, arr1);
    Matrix matrix2(3, arr3);

    // Выполняем операции векторной алгебры
    Vector resultVector = vector1 + vector2;
    Matrix resultMatrix = matrix1 + matrix2;

    // Освобождаем память
    delete[] resultVector.elements;
    delete[] resultMatrix.elements;

    return 0;
}
