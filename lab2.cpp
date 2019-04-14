
#include <SDL2/SDL.h>

# define FPS 60
# define WIDTH 1300
# define HEIGHT 1000
# define MUL  80

double f(const double &x)
{
    return (sqrt(x));
}


double draw_zero_pow()
{
    return (1. / 2);
}

double draw_first_pow(const double &x)
{
    return (x + 1. / 8);
}

void draw_lines(SDL_Renderer *renderer)
{
    for (int y = 0; y < HEIGHT; y += 1)
    {
        SDL_RenderDrawPoint(renderer, WIDTH / 2, y);
    }
    for (int x = 0; x < WIDTH; ++x)
    {
        SDL_RenderDrawPoint(renderer, x, HEIGHT / 2);
    }
}

void draw_plots(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 169, 169, 169, 0);
    draw_lines(renderer);
    for (double x = 0; x <= 10; x += 0.0001)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
        SDL_RenderDrawPoint(renderer, WIDTH / 2 + x * MUL, HEIGHT / 2 - f(x) * MUL + 1);
        SDL_SetRenderDrawColor(renderer, 255, 255, 51, 0);
        SDL_RenderDrawPoint(renderer, WIDTH / 2 + x * MUL, HEIGHT / 2 - draw_zero_pow() * MUL + 1);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
        SDL_RenderDrawPoint(renderer, WIDTH / 2 + x * MUL, HEIGHT / 2 - draw_first_pow(x) * MUL + 1);
    }
}

int main()
{
    SDL_Window   *window;
    SDL_Renderer *renderer;
    SDL_Event    event;
    Uint32       start;

    const int a = 0;
    const int b = 1;


    SDL_CreateWindowAndRenderer(1300, 1000, 0, &window, &renderer);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);


    while (true)
    {
        SDL_RenderClear(renderer);
        if (SDL_PollEvent(&event) && (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE))
            break;
        start = SDL_GetTicks();

        draw_plots(renderer);


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);

        if (1000 / FPS > SDL_GetTicks() - start)
        {
            SDL_Delay(1000 / FPS - (SDL_GetTicks() - start));
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return (0);
}