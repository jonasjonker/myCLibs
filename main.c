#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/loadfile.h"
#include "utils/logging.h"

/**
 * @brief test
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv) 
{
    if (argc == 1)
        exitWithMsg("Usage: <filename>\n");

    char **words = loadfile(argv[1]);
    if (!words)
        exitWithMsg("Can't loadfile.");

    for (int i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
    }
    printf("Done\n");
}
