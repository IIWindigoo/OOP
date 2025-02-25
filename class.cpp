#include <iostream>


class Point{
private:
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
    ~Point(){
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

int main(){
    Point *p = new Point(5, 15);
    Point *p2 = new Point(*p);

    p->change(10, 10);
    p2->reset();

    delete p;
    delete p2;
    
    return 0;
}