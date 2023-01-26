#include <stdio.h>
#include <stdlib.h>

#include "mymath.h"
#include "myhello.h"
#include "mydef.h"

int main() {
    int a = 1, b = 2;
    printf("a + b = %d\n", add(1, 2));
    printf("MAX_LINE = %d\n", MAX_LINE);
    hello("DDQ");
    return EXIT_SUCCESS;
}
