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
};

int main(){
    Point *p = new Point;
    Point *p2 = new Point(5, 10);
    Point *p3 = new Point(*p2);

    delete p;
    delete p2;
    delete p3;
    
    return 0;
}