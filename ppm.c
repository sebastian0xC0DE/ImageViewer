#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    if (strcmp(imgType, "P6\n") == 0) {
        fread(img->pixels, 1, img->width * img->height * 3, pf);
    } else if (strcmp(imgType, "P3\n") == 0) {
        for (int i = 0; i < (img->width * img->height * 3); i++) {
            int v;
            fscanf(pf, "%d\n", &v);
            img->pixels[i] = (unsigned char)v;
        }
    }

    return img;
}

