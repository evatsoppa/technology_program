#include <iostream>
#include <cmath>

// класс для геом. фигуры
class Shape {
public:
    virtual void draw() const = 0;           // метод для изображения фигуры
    virtual void erase() = 0;                //           удаления фигуры
    virtual void move(double dx, double dy); //           перемещения фигуры
    virtual void rotate(double angle) = 0;   //           поворота фигуры
    virtual ~Shape() {}                      // вирт. деструктор
};

// класс для точки
class Point : public Shape {
protected:
    double x;
    double y;

public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    void draw() const override {
        std::cout << "точка (" << x << ", " << y << ")" << std::endl;
    }

    void erase() override {
        std::cout << "удал. точки (" << x << ", " << y << ")" << std::endl;
        // вывела сообщение об удалении точки
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "перемещ. точки на (" << dx << ", " << dy << ").  координаты новые: (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) override {
        // поворот можно не делать(нет смысла)
        std::cout << "поворот точки на " << angle << " град." << std::endl;
    }
};

// класс для линии 
class Line : public Shape {
protected:
    Point startPoint;
    Point endPoint;

public:
    Line(const Point& start, const Point& end) : startPoint(start), endPoint(end) {}

    void draw() const override {
        std::cout << "линия от (" << startPoint.x << ", " << startPoint.y << ") до (" << endPoint.x << ", " << endPoint.y << ")" << std::endl;
    }

    void erase() override {
        std::cout << "удал. линии от (" << startPoint.x << ", " << startPoint.y << ") до (" << endPoint.x << ", " << endPoint.y << ")" << std::endl;
        // удалила линию
    }

    void move(double dx, double dy) override {
        startPoint.move(dx, dy);
        endPoint.move(dx, dy);
        std::cout << "перемещ. линии на (" << dx << ", " << dy << ")." << std::endl;
    }

    void rotate(double angle) override {
        // также нет смысла, как и с точкой
        std::cout << "поворот линии на " << angle << " градусов" << std::endl;
    }
};

// класс для квадрата 
class Square : public Shape {
protected:
    Point topLeft;
    double sideLength;

public:
    Square(const Point& topLeftCorner, double length) : topLeft(topLeftCorner), sideLength(length) {}

    void draw() const override {
        std::cout << "квадрат с верхним левым углом в точке (" << topLeft.x << ", " << topLeft.y << ") и длиной стороны " << sideLength << std::endl;
    }

    void erase() override {
        std::cout << "удал. квадрата с верхним левым углом в точке (" << topLeft.x << ", " << topLeft.y << ")" << std::endl;
        // удалила квадрат
    }

    void move(double dx, double dy) override {
        topLeft.move(dx, dy);
        std::cout << "перемещ. квадрата на (" << dx << ", " << dy << ")." << std::endl;
    }

    void rotate(double angle) override {
        std::cout << "поворот квадрата на " << angle << " градусов." << std::endl;
    }
};

int main() {

    // точка
    Point point(3.0, 4.0);
    point.draw();
    point.move(1.0, -2.0);

    std::cout << std::endl;

    // линия
    Point startPoint(1.0, 1.0);
    Point endPoint(5.0, 5.0);
    Line line(startPoint, endPoint);
    line.draw();
    line.move(-1.0, 2.0);

    std::cout << std::endl;

    // квадрат
    Point squareTopLeft(2.0, 2.0);
    Square square(squareTopLeft, 4.0);
    square.draw();
    square.move(3.0, 1.5);

    return 0;
}
