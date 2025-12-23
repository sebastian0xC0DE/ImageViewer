#include <SDL3/SDL.h>

int main() {

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

    // "paint" the window
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x0, 0x0, 0xFF);
    SDL_RenderClear(renderer);
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
