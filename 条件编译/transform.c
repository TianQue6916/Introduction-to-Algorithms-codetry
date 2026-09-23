#include "transform.h"
#include <stdio.h>

// ÊµÏÖº¯Êý
void transform(int num) {
    printf("0b");
    for (int i = 31; i >= 0; i--) {
        printf("%c", (num & (1u << i)) ? '1' : '0');
        if (i % 4 == 0 && i != 0) printf(" ");
    }
}