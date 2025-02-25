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
        printf("~Point()");
    }
};

int main(){
    return 0;
}