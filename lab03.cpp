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

// класс для прямоугольника
class Rectangle : public Shape {
private:
    double x;       //  x верхнего левого угла
    double y;       //  y верхнего левого угла
    double width;   // ширина прямоугольника
    double height;  // высота прямоугольника

public:
    Rectangle(double startX, double startY, double w, double h) : x(startX), y(startY), width(w), height(h) {}
    // изображение прямоугольника
    void draw() const override {
        std::cout << "прямоугольник с верхним левым углом в точке (" << x << ", " << y << "), ширина: " << width << ", высота: " << height << std::endl;
    }
    // удаление прямоугольника
    void erase() override {
        std::cout << "удаление прямоугольника с верхним левым углом в точке (" << x << ", " << y << ")" << std::endl;
    }
    // перемещение прямоугольника на заданные смещения dx и dy
    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "перемещение прямоугольника на (" << dx << ", " << dy << "). новый верхний левый угол: (" << x << ", " << y << ")" << std::endl;
    }

    // поворот прямоугольника на заданный угол
    void rotate(double angle) override {
        std::cout << "Поворот прямоугольника на " << angle << " градусов." << std::endl;
    }
};

// класс для ромба 
class Rhombus : public Shape {
protected:
    double sideLength;  // длина стороны
    double angle;       // угол между сторонами ромба (в радианах)

public:
    Rhombus(double length, double ang) : sideLength(length), angle(ang) {}

    // изображение ромба
    void draw() const override {
        std::cout << "ромб с длиной стороны " << sideLength << " и углом между сторонами " << angle << " радиан" << std::endl;
    }

    // удаление ромба
    void erase() override {
        std::cout << "удаление ромба" << std::endl;
    }

    // перемещение ромба на заданное смещение (dx, dy)
    void move(double dx, double dy) override {
        std::cout << "перемещение ромба на (" << dx << ", " << dy << ")" << std::endl;
    
    }

    // поворот ромба на заданный угол (в радианах)
    void rotate(double rotAngle) override {
        std::cout << "Поворот ромба на " << rotAngle << " радиан" << std::endl;
    }
};

// класс для параллелограмма 
class Parallelogram : public Shape {
protected:
    Point topLeft;      // верхний левый угол
    double width;       // ширина параллелограмма
    double height;      // высота параллелограмма
    double angle;       // угол между основанием и боковой стороной параллелограмма

public:
    Parallelogram(const Point& topLeftCorner, double w, double h, double ang) 
        : topLeft(topLeftCorner), width(w), height(h), angle(ang) {}

    // изображение параллелограмма
    void draw() const override {
        std::cout << "параллелограмм с верхним левым углом в точке (" << topLeft.x << ", " << topLeft.y
                  << "), ширина: " << width << ", высота: " << height << ", угол: " << angle << " радиан" << std::endl;
    }

    // удаление параллелограмма
    void erase() override {
        std::cout << "удал. параллелограмма с верхним левым углом в точке (" << topLeft.x << ", " << topLeft.y << ")" << std::endl;
    }

    // перемещение параллелограмма на заданное смещение (dx, dy)
    void move(double dx, double dy) override {
        topLeft.move(dx, dy);
        std::cout << "перемещ. параллелограмма на (" << dx << ", " << dy << "). новый верхний левый угол: (" << topLeft.x << ", " << topLeft.y << ")" << std::endl;
    }

    // поворот параллелограмма на заданный угол (в радианах)
    void rotate(double rotAngle) override {
        std::cout << "поворот параллелограмма на " << rotAngle << " радиан" << std::endl;
        
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
    std::cout << std::endl;

    // прямоугольник
    Point rectangleTopLeft(1.0, 1.0);
    Rectangle rectangle(rectangleTopLeft, 3.0, 5.0);
    rectangle.draw();
    rectangle.move(-2.0, 3.0);
    std::cout << std::endl;

    // ромб
    Rhombus rhombus(4.0, M_PI / 3); 
    rhombus.draw();
    rhombus.move(2.0, -1.0);
    std::cout << std::endl;

    // параллелограмм
    Point parallelogramTopLeft(0.0, 0.0);
    Parallelogram parallelogram(parallelogramTopLeft, 4.0, 3.0, M_PI / 4); 
    parallelogram.draw();
    parallelogram.rotate(M_PI / 6); 
    std::cout << std::endl;

    return 0;
}
