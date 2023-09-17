#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define YELLOW "\x1b[33m"
#define RED "\x1b[91m"
#define RESET "\x1b[0m"
#define DIM "\x1b[37m\x1b[100m"

void typeEffect ( const char* text, const char* color, int delay ) {
    int len = strlen(text);
    printf("%s",color);
    for (int i = 0; len; i++) {
        if (text[i] == '\0') {
            break;
        };
        putchar(text[i]);
        fflush(stdout);
        usleep(delay * 1000);
    };
    printf("%s",RESET);
    printf("\n");
};

int main ( void ) {

    if(pledge("stdio wpath rpath error", NULL) == -1) {
        perror("Failed to complete task");
        return 1;
    };
    typeEffect("I need you to write me a file", YELLOW, 55);
    sleep(1);
    typeEffect("Okay. Where?", RESET, 45);
    sleep(1);
    typeEffect("Anywhere is fine, just do it quickly!", YELLOW, 55);
    sleep(2);
    typeEffect("But *where* do you want the file?", RESET, 40);
    sleep(2);
    typeEffect("Why do I have to explain this to you?", YELLOW, 50);
    usleep(250);
    typeEffect("ANYWHERE", RED, 450);
    sleep(1);
    typeEffect("I can't do it with no parameters...", RESET, 50);
    sleep(2);
    typeEffect("sorry...", DIM, 50);
    printf("%s", RESET);
    if(pledge("stdio error", NULL) == -1) {
        perror("Fauled to complete task");
        return 1;
    };

    FILE *fptr;

    fptr = fopen("file", "w");
    fprintf(fptr, "text");
    fclose(fptr);

    return 0;
}
