#include <iostream>

class vect {
public:
    int dim;
    double* b;
    int num;
    static int count;

    // Конструктор для вектора
    vect(int d, double* arr) : dim(d), b(arr), num(++count) {
        std::cout << "Создан вектор " << num << std::endl;
    }

    // Деструктор для вектора
    ~vect() {
        std::cout << "Уничтожен вектор " << num << std::endl;
    }

    // Операторы векторной алгебры
    vect operator+(const vect& other) const;
    vect operator-(const vect& other) const;
    vect operator-() const;
    double operator*(const vect& other) const;
    vect operator*(double k) const;
    vect& operator=(const vect& other);
};

int vect::count = 0;

class matr {
public:
    int dim;
    double* a;
    int num;
    static int count;

    // Конструктор для матрицы
    matr(int d, double* arr) : dim(d), a(arr), num(++count) {
        std::cout << "Создана матрица " << num << std::endl;
    }

    // Деструктор для матрицы
    ~matr() {
        std::cout << "Уничтожена матрица " << num << std::endl;
    }

    // Операторы векторной алгебры для матрицы
    matr operator+(const matr& other) const;
    matr operator-(const matr& other) const;
    matr operator-() const;
    matr operator*(const matr& other) const;
    matr operator*(double k) const;
    matr& operator=(const matr& other);

    // Оператор умножения матрицы на вектор
    vect operator*(const vect& vector) const;
};

int matr::count = 0;

int main() {
    double arr1[] = {1.0, 2.0, 3.0};
    double arr2[] = {4.0, 5.0, 6.0};
    double arr3[] = {7.0, 8.0, 9.0};

    // Создаем векторы и матрицы
    vect vector1(3, arr1);
    vect vector2(3, arr2);
    matr matrix1(3, arr1);
    matr matrix2(3, arr3);

    // Выполняем операции векторной алгебры
    vect resultVector = vector1 + vector2;
    vect negatedVector = -vector1;
    double dotProduct = vector1 * vector2;
    vect scaledVector = vector1 * 2.5;
    vector1 = vector2;

    matr resultMatrix = matrix1 + matrix2;
    matr negatedMatrix = -matrix1;
    matr elementwiseProduct = matrix1 * matrix2;
    matr scaledMatrix = matrix1 * 1.5;
    matrix1 = matrix2;

    vect matrixVectorProduct = matrix1 * vector1;

    // Освобождаем память
    delete[] resultVector.b;
    delete[] negatedVector.b;
    delete[] resultMatrix.a;
    delete[] negatedMatrix.a;
    delete[] elementwiseProduct.a;
    delete[] scaledMatrix.a;

    return 0;
}
