#include <stdio.h>
#include <stdlib.h>

#include "image.h"
#include "ppm.h"

Image *loadPPM(const char *path) {
    FILE *pf = fopen(path, "rb");
    
    if (pf == NULL) {
        printf("Error: failed loading image ppm.c line 10");
        return NULL;
    }
    
    Image *img = malloc(sizeof(Image));

    char imgType[4];
    char comment[50];
    unsigned int maxColor;

    fgets(imgType, 4, pf);

    fgets(comment, 50, pf);

    fscanf(pf, "%d %d\n", &img->width, &img->height);

    fscanf(pf, "%d\n", &maxColor);

    img->pixels = malloc(img->width * img->height * 3);

    fread(img->pixels, 1, img->width * img->height * 3, pf);

    return img;
}

