#include <iostream>


class Point{
public:
    int x, y;
    Point(){
        printf("Point()\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y){
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point &p){
        printf("Point(const Point &p)\n");
        x = p.x;
        y = p.y;
    }
    ~Point(){
        printf("%d, %d\n", x, y);
        printf("~Point()\n");
    }
};
//Инициализация полей класса в списке инициализации
class Shape{
protected:
    int area;
public:
    Shape() : area(0) {
        printf("Shape()\n");
    }
    Shape(int area) : area(area) {
        printf("Shape(int area)\n");
    }
    Shape(const Shape &s) : area(s.area) {
        printf("Shape(const Shape &s)\n");
    }
    ~Shape() {
        printf("%d\n", area);
        printf("~Shape()\n");
    }
};

int main(){
    Point *p = new Point;
    Point *p2 = new Point(5, 10);
    Point *p3 = new Point(*p2);

    delete p;
    delete p2;
    delete p3;

    printf("-------------------\n");
    Shape *s = new Shape;

    delete s;
    
    return 0;
}