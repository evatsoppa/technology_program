#include <iostream>
class vect {
public:
    int dim;
    double* b;
    int num;
    static int count;
    vect(int d, double* arr) : dim(d), b(arr), num(++count) {
        std::cout << "Created vector " << num << std::endl;
    }
    ~vect() {
        std::cout << "Destroyed vector " << num << std::endl;
    }
    vect operator+(const vect& other) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = b[i] + other.b[i];
        }
        return vect(dim, result);
    }
    vect operator-(const vect& other) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = b[i] - other.b[i];
        }
        return vect(dim, result);
    }

    vect operator-() const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = -b[i];
        }
        return vect(dim, result);
    }
    double operator*(const vect& other) const {
        double result = 0.0;
        for (int i = 0; i < dim; ++i) {
            result += b[i] * other.b[i];
        }
        return result;
    }
    vect operator*(double k) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = k * b[i];
        }
        return vect(dim, result);
    }
    vect& operator=(const vect& other) {
        if (this != &other) {
            delete[] b;
            dim = other.dim;
            b = new double[dim];
            for (int i = 0; i < dim; ++i) {
                b[i] = other.b[i];
            }
        }
        return *this;
    }
};
int vect::count = 0;
class matr {
public:
    int dim;
    double* a;
    int num;
    static int count;
    matr(int d, double* arr) : dim(d), a(arr), num(++count) {
        std::cout << "Created matrix " << num << std::endl;
    }
    ~matr() {
        std::cout << "Destroyed matrix " << num << std::endl;
    }
    matr operator+(const matr& other) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = a[i] + other.a[i];
        }
        return matr(dim, result);
    }
    matr operator-(const matr& other) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = a[i] - other.a[i];
        }
        return matr(dim, result);
    }
    matr operator-() const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = -a[i];
        }
        return matr(dim, result);
    }
    matr operator*(const matr& other) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = a[i] * other.a[i];
        }
        return matr(dim, result);
    }
    matr operator*(double k) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = k * a[i];
        }
        return matr(dim, result);
    }
    matr& operator=(const matr& other) {
        if (this != &other) {
            delete[] a;
            dim = other.dim;
            a = new double[dim];
            for (int i = 0; i < dim; ++i) {
                a[i] = other.a[i];
            }
        }
        return *this;
    }
    vect operator*(const vect& v) const {
        double* result = new double[dim];
        for (int i = 0; i < dim; ++i) {
            result[i] = 0.0;
            for (int j = 0; j < dim; ++j) {
                result[i] += a[i * dim + j] * v.b[j];
            }
        }
        return vect(dim, result);
    }
};
int matr::count = 0;
int main() {
    double arr1[] = {1.0, 2.0, 3.0};
    double arr2[] = {4.0, 5.0, 6.0};
    double arr3[] = {7.0, 8.0, 9.0};
    vect v1(3, arr1);
    vect v2(3, arr2);
    matr m1(3, arr1);
    matr m2(3, arr2);
    vect result1 = v1 + v2;
    vect result2 = v1 - v2;
    vect result3 = -v1;
    double result4 = v1 * v2;
    vect result5 = 2.0 * v1;
    v1 = v2;
    matr result6 = m1 + m2;
    matr result7 = m1 - m2;
    matr result8 = -m1;
    matr result9 = m1 * m2;
    matr result10 = 2.0 * m1;
    m1 = m2;
    vect result11 = m1 * v1;
    delete[] result1.b;
    delete[] result2.b;
    delete[] result3.b;
    delete[] result6.a;
    delete[] result7.a;
    delete[] result8.a;
    delete[] result9.a;
    delete[] result10.a;
    return 0;
}
