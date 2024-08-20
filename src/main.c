#include "../libs/iso.h"

/*********************************/
/*                               */
/*         SDL Stuff             */
/*                               */
/*********************************/

int init(SDL_Window **window, SDL_Renderer **renderer, int w, int h) {
    if(0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init : %s\n", SDL_GetError());
        return -1;
    }
    if(0 != SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE, window, renderer)) {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

int setWindowColor(SDL_Renderer* renderer, SDL_Color color) {
    if (SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a)) {
        return -1;
    }
    if (SDL_RenderClear(renderer) < 0) return -1;
}


/*
 ██████   ██████   █████████   █████ ██████   █████
░░██████ ██████   ███░░░░░███ ░░███ ░░██████ ░░███ 
 ░███░█████░███  ░███    ░███  ░███  ░███░███ ░███ 
 ░███░░███ ░███  ░███████████  ░███  ░███░░███░███ 
 ░███ ░░░  ░███  ░███░░░░░███  ░███  ░███ ░░██████ 
 ░███      ░███  ░███    ░███  ░███  ░███  ░░█████ 
 █████     █████ █████   █████ █████ █████  ░░█████
░░░░░     ░░░░░ ░░░░░   ░░░░░ ░░░░░ ░░░░░    ░░░░░ 
*/

int main(void) {
  /* SDL Init */
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture* spritsheet = NULL;
  int statut = EXIT_FAILURE;

  if (0 != init(&window, &renderer, 1000, 1000)){
      goto Quit;
  }

  SDL_SetWindowTitle(window, "Isometric Game");
  /* Some Colors */
  SDL_Color blue_up = {121, 181, 254, 255};
  SDL_Color blue_right = {169, 216, 248, 255};
  SDL_Color blue_left = {91, 123, 195, 255};
  SDL_Color black = {0, 0, 0, 255}; 
  SDL_Color background = {144, 101, 254, 255};
  SDL_Color white = {255, 255, 255, 255};
  SDL_Color lightgray = {205, 209, 219, 255};

  setWindowColor(renderer, background);

  SDL_Event e;
  int quit = 0;
  while (!quit) {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
     while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = 1;
      }
    }
  }


  Quit:
    if(NULL != renderer)
        SDL_DestroyRenderer(renderer);
    if(NULL != window)
        SDL_DestroyWindow(window);
    SDL_Quit();
  return statut; 
}
