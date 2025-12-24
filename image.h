#ifndef IMAGE_H
#define IMAGE_H

typedef struct {

    int width;
    int height;
    unsigned char *pixels;

} Image;

Image *loadImage(const char *path);
void freeImage(Image *img);

#endif
