#include <iostream>


class Point{
protected:
    int x, y;
public:
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
    virtual ~Point(){
        printf("%d, %d\n", x, y);
        printf("~Point()\n");
    }
    void change(int dx, int dy){
        x = dx;
        y = dy;
    }
    void reset();
};

void Point::reset(){
    x = 0;
    y = 0;
}

class ColoredPoint: public Point{
protected:
    int color;
public:
    ColoredPoint() : Point(){
        printf("ColoredPoint()\n");
        color = 0;
    }
    ColoredPoint(int x, int y, int color) : Point(x, y){
        printf("ColoredPoint(int x, int y, int color)\n");
        this->color = color;
    }
    ColoredPoint(const ColoredPoint &p) : Point(p) {
        printf("ColoredPoint(const ColoredPoint &p)\n");
        color = p.color;
    }
    ~ColoredPoint(){
        printf("%d, %d, color=%d\n", x, y, color);
        printf("~ColoredPoint()\n");
    }
    void change_color(int new_color){
        color = new_color;
    }
};

int main(){
    //Создание объектов класса
    Point *p = new Point(5, 15);
    Point *p2 = new Point(*p);

    p->change(10, 10);
    p2->reset();

    delete p;
    delete p2;

    printf("-----------------\n");
    //Создание объекта класса-наследника
    ColoredPoint *pp3 = new ColoredPoint(1, 1, 32);
    ColoredPoint *p3 = new ColoredPoint(*pp3);
    p3->change(10, 10);
    p3->change_color(27);
    delete pp3;
    delete p3;
    
    printf("-----------------\n");
    Point *p4 = new ColoredPoint(4, 4, 20);
    ColoredPoint *p5 = new ColoredPoint(5, 5, 25);
    delete p4;
    delete p5;

    return 0;
}