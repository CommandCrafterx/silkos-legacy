/*
 * MIT License
 *
 * Copyright (c) 2025 FlipArt
 * * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <str.h>
#include <mem.h>

static int game(void);

int str_cmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int main(void) {
    int status;
    while (true) {
        status = game();
        if (status == 0) {
            break;
        }
    }
    return 0;
}

static int game(void) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }

    int userin, tries = 0;
    int randnum = rand() % 100 + 1;

    printf("_________________________________________\n");
    printf("PB LOST DATA 1.0 - ALL PRPGRESS RESERVED\n");
    printf("        TYPE A NUMBER TO START\n");
    printf("_________________________________________\n\n");

    while (true) {
        do {
            printf("> ");
            if (scanf("%d", &userin) != 1) {
                printf("Invalid Input\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                userin = -1;
            }
        } while (userin < 0 || userin > 100);

        tries++;

        if (tries > 10) {
            printf("GAME OVER!\n");
            break;
        }

        if (userin < randnum) {
            printf("Too small\n");
        } else if (userin > randnum) {
            printf("Too high\n");
        } else {
            printf("YOU WIN! TRIES: %d\n", tries);
            break;
        }
    }

    char playagain[2];

    while (true) {
        printf("Play again? (y/n) > ");
        scanf("%1s", playagain);
        if (str_cmp(playagain, "y") == 0) {
            return 1;
        } else if (str_cmp(playagain, "n") == 0) {
            return 0;
        } else {
            printf("Invalid Input\n");
        }
    }
}