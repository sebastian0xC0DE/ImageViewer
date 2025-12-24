#include <SDL3/SDL.h>
#include <stdio.h>

#include "image.h"

int main() {

    char filePath[100];
    
    printf("Enter the full path to the image:\n");
    
    fgets(filePath, sizeof(filePath), stdin);
    // Remove \n from the end of the string
    filePath[strcspn(filePath, "\n")] = '\0';
    
    int funcao = loadImage(filePath);
    
    printf("%d\n", funcao);    

    return 0;

    // Initialize the SDL Video
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log(SDL_GetError());
        return -1;
    }
    
    // Create a window 900x600
    SDL_Window *window = SDL_CreateWindow("ImageViewer", 900, 600, 0);

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
    //unsigned char pixelColor[3];
    for (unsigned int y = 0; y < 600; y++) {
        for (unsigned int x = 0; x < 900; x++) {
            pixel.x = x;
            pixel.y = y;
            
            //fread(pixelColor, 1, 3, pf);     
            
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            
            SDL_RenderFillRect(renderer, &pixel);
        }
    }

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

    // Close the window
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
