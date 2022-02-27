#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "loadfile.h"
#include "logging.h"

const int STEPSIZE = 128;
const int BUFSIZE = 1024;


/**
 * @brief load file of arbitrary size into memory
 * 
 * @param filename 
 * @return char** 
 */
char ** loadfile(char * filename) 
{
    FILE *fptr = fopen(filename, "r");
    if (!fptr)
        exitWithMsg("Couldn't open %s\n", filename);

    char ** lines = NULL;
    char buf[BUFSIZE];
    int arrlen = 0;
    int i = 0;
    while (fgets(buf, BUFSIZE, fptr)) {
        // Allocate more memory if necessary
        if (i == arrlen) {
            arrlen += STEPSIZE;
            char ** newlines = realloc(lines, arrlen * sizeof(char *));
            if (!newlines)
                exitWithMsg("Couldn't realloc.");
            lines =  newlines;
        }
        buf[strlen(buf) - 1] = '\0';
        int slen = strlen(buf);
        char * str = malloc((slen + 1) * sizeof(char));
        strcpy(str, buf);
        lines[i] = str;
        i++;
    }
    if (i == arrlen) {
        char ** newlines = realloc(lines, (arrlen + 1) * sizeof(char *));
        if (!newlines) 
            exitWithMsg("Couldn't realloc.");
        lines =  newlines;
    }
    lines[i] = NULL;
    return lines;
}
