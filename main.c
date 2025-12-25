#include <SDL3/SDL.h>
#include <stdio.h>

#include "image.h"

int main() {

    char filePath[100];
    
    printf("Enter the full path to the image:\n");
    
    fgets(filePath, sizeof(filePath), stdin);
    // Remove \n from the end of the string
    filePath[strcspn(filePath, "\n")] = '\0';
    
    Image *img = loadImage(filePath);  

    if (img == NULL) {
        printf("img é null\n");
        return -1;
    }

    // Initialize the SDL Video
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log(SDL_GetError());
        return -1;
    }
    
    // Create a window with the same dimensions as the image
    SDL_Window *window = SDL_CreateWindow("ImageViewer", img->width, img->height, 0);

    if (window == NULL) {
        SDL_Log(SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);

    if (renderer == NULL) {
        SDL_Log(SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Render the window
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
    SDL_RenderClear(renderer);
    
    SDL_FRect pixel = {0, 0, 1, 1};
    int index;

    // It scans the entire window checking the color of the image pixels and reproducing them
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel.x = x;
            pixel.y = y;
            // Calculate the pixel index
            index = (y * img->width + x) * 3;

            unsigned char r = img->pixels[index];
            unsigned char g = img->pixels[index + 1];
            unsigned char b = img->pixels[index + 2];
            // Render the pixel with the right color
            SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
            
            SDL_RenderFillRect(renderer, &pixel);
        }
    }
    // Present the image render
    SDL_RenderPresent(renderer);
    // Create an event to display the window
    char running = 1;
    SDL_Event event;

    // Run the event
    while (running != 0) {
        while(SDL_PollEvent(&event)) {
            // Stop running the event if the user want
            if (event.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }
        SDL_Delay(16); // Aprox. 60 FPS
    }
    // Frees up memory
    freeImage(img);

    // Close the window
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
