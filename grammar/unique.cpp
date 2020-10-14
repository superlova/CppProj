#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <memory>
using namespace std;

struct solution {
    int x;
    int y;
    solution(int _x, int _y) :x(_x), y(_y) {}
};

void fun(unique_ptr<solution> p) {
    printf("%d\n", p->y);
}



int main() {
    auto p = make_unique<solution>(1,2);
    auto ptr = new solution(1,2);
    fun(make_unique<solution>(ptr));

    printf("%d\n", ptr->x);
    system("PAUSE");
    return 0;
}