#include <stdio.h>

struct Rectangle {
    float length;
    float width;
};

int check(struct Rectangle r) {
    return r.length > 0.0 && r.length < 20.0 && r.width > 0.0 && r.width < 20.0;
}

float perimeter(struct Rectangle r) {
    return 2 * (r.length + r.width);
}

float area(struct Rectangle r) {
    return r.length * r.width;
}

int main() {
    struct Rectangle r = { 5.0, 10.0 };

    if (check(r)) {
        printf("Perimeter: %.2f\n", perimeter(r));
        printf("Area: %.2f\n", area(r));
    } else {
        printf(" dimensions are invalid\n");
    }

    return 0;
}

