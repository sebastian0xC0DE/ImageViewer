#include <stdio.h>
#include <string.h>

#include "image.h"

int loadImage(const char *path) {

    FILE *pf = fopen(path, "r");
    
    if (pf == NULL) {
        printf("Error: Failed on load image");
        return -1;
    };

    char imageType[4];
    fgets(imageType, 4, pf);

    if (strcmp(imageType, "P3\n") == 0 || strcmp(imageType, "P6\n") == 0) {
        printf("o if deu certo\n");
        return 1;
    } else {
        printf("image.c linha 22\n");
        return 1;
    }

}
