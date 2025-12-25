#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "image.h"
#include "ppm.h"

Image *loadImage(const char *path) {
    // Tries to the file
    FILE *pf = fopen(path, "r");
    // Checks if the file was opened succesfully
    if (pf == NULL) {
        printf("Error: Failed on load image\n");
        return NULL;
    };

    char imageType[4];
    fgets(imageType, 4, pf);
    // Checks if the image format is PPM
    if (strcmp(imageType, "P3\n") == 0 || strcmp(imageType, "P6\n") == 0) {
        Image *img = loadPPM(path);
        return img;
    } else {
        printf("image.c linha 22\n");
        return NULL;
    }

}

void freeImage(Image *img) {
    if (!img) return;

    free(img->pixels);
    free(img);
};

