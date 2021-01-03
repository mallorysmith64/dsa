#include <stdio.h>

struct rect {
    int length;
    int breadth;
};

int main() {
    struct rect r={2,3};
    printf("Length is: %d\nBreadth is: %d", r.length, r.breadth);

    return 0;
}