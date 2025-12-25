#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "ppm.h"

Image *loadPPM(const char *path) {
    // Tries to open the file
    FILE *pf = fopen(path, "rb");
    // Checks if the file was opened succesfully
    if (pf == NULL) {
        printf("Error: failed loading image ppm.c line 10");
        return NULL;
    }
    
    Image *img = malloc(sizeof(Image));

    char imgType[4];
    char comment[50];
    unsigned int maxColor;
    // Reads the very first row of the image file (P3 or P6)
    fgets(imgType, 4, pf);
    // Reads the comment in the next line of the image file
    fgets(comment, 50, pf);
    // Reads the next line of the image file, wich is the width and height
    fscanf(pf, "%d %d\n", &img->width, &img->height);
    // Reads the next line of the image file, which is value of the brightest subpixel (normally 255)
    fscanf(pf, "%d\n", &maxColor);
    // Allocate enough memory to store all pixels values
    img->pixels = malloc(img->width * img->height * 3);

    if (strcmp(imgType, "P6\n") == 0) {
        // Stores all the pixels values
        fread(img->pixels, 1, img->width * img->height * 3, pf);
    } else if (strcmp(imgType, "P3\n") == 0) {
        // Stores all the pixels values
        for (int i = 0; i < (img->width * img->height * 3); i++) {
            int v;
            fscanf(pf, "%d\n", &v);
            img->pixels[i] = (unsigned char)v;
        }
    }

    return img;
}

