#include <stdio.h>

int main() {
    int n = 5;

    for (int i = n; i >= 1; i--) {

        // print leading spaces
        for (int s = 0; s < n - i; s++) {
            printf(" ");
        }

        // print stars with space
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
