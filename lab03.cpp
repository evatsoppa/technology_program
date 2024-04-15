#include <iostream>
#include <cmath>

// Базовый абстрактный класс для геометрической фигуры
class Shape {
public:
    virtual void draw() const = 0;           // Метод для отображения фигуры
    virtual void erase() = 0;                // Метод для удаления фигуры
    virtual void move(double dx, double dy); // Метод для перемещения фигуры
    virtual void rotate(double angle) = 0;   // Метод для поворота фигуры
    virtual ~Shape() {}                      // Виртуальный деструктор
};

// Класс для точки (наследуется от Shape)
class Point : public Shape {
protected:
    double x;
    double y;

public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    void draw() const override {
        std::cout << "Точка (" << x << ", " << y << ")" << std::endl;
    }

    void erase() override {
        std::cout << "Удаление точки (" << x << ", " << y << ")" << std::endl;
        // В данном примере просто выводим сообщение об удалении точки
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Перемещение точки на (" << dx << ", " << dy << "). Новые координаты: (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) override {
        // Для точки поворот не имеет смысла, поэтому метод остается пустым
        std::cout << "Поворот точки на " << angle << " градусов (нет эффекта для точки)." << std::endl;
    }
};

// Класс для линии (наследуется от Shape)
class Line : public Shape {
protected:
    Point startPoint;
    Point endPoint;

public:
    Line(const Point& start, const Point& end) : startPoint(start), endPoint(end) {}

    void draw() const override {
        std::cout << "Линия от (" << startPoint.x << ", " << startPoint.y << ") до (" << endPoint.x << ", " << endPoint.y << ")" << std::endl;
    }

    void erase() override {
        std::cout << "Удаление линии от (" << startPoint.x << ", " << startPoint.y << ") до (" << endPoint.x << ", " << endPoint.y << ")" << std::endl;
        // В данном примере просто выводим сообщение об удалении линии
    }

    void move(double dx, double dy) override {
        startPoint.move(dx, dy);
        endPoint.move(dx, dy);
        std::cout << "Перемещение линии на (" << dx << ", " << dy << ")." << std::endl;
    }

    void rotate(double angle) override {
        // Для линии также не реализуем поворот в данном примере
        std::cout << "Поворот линии на " << angle << " градусов (нет эффекта для линии)." << std::endl;
    }
};

// Класс для квадрата (наследуется от Shape)
class Square : public Shape {
protected:
    Point topLeft;
    double sideLength;

public:
    Square(const Point& topLeftCorner, double length) : topLeft(topLeftCorner), sideLength(length) {}

    void draw() const override {
        std::cout << "Квадрат с верхним левым углом в точке (" << topLeft.x << ", " << topLeft.y << ") и длиной стороны " << sideLength << std::endl;
    }

    void erase() override {
        std::cout << "Удаление квадрата с верхним левым углом в точке (" << topLeft.x << ", " << topLeft.y << ")" << std::endl;
        // В данном примере просто выводим сообщение об удалении квадрата
    }

    void move(double dx, double dy) override {
        topLeft.move(dx, dy);
        std::cout << "Перемещение квадрата на (" << dx << ", " << dy << ")." << std::endl;
    }

    void rotate(double angle) override {
        // Реализация поворота квадрата
        std::cout << "Поворот квадрата на " << angle << " градусов." << std::endl;
    }
};

// Основная функция программы
int main() {
    // Создание объектов и использование методов

    // Создание и использование объекта Point
    Point point(3.0, 4.0);
    point.draw();
    point.move(1.0, -2.0);

    std::cout << std::endl;

    // Создание и использование объекта Line
    Point startPoint(1.0, 1.0);
    Point endPoint(5.0, 5.0);
    Line line(startPoint, endPoint);
    line.draw();
    line.move(-1.0, 2.0);

    std::cout << std::endl;

    // Создание и использование объекта Square
    Point squareTopLeft(2.0, 2.0);
    Square square(squareTopLeft, 4.0);
    square.draw();
    square.move(3.0, 1.5);

    return 0;
}
