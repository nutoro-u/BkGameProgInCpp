#pragma once
#include "SDL3/SDL.h"

typedef struct
{
	Uint64 last_time;
	double delta_time; // Frame duration in seconds
} AppState;

struct Vector2
{
	float x;
	float y;
};

class Game
{
public:
	Game();

	bool Initialize();
	
	//void RunLoop();
	
	SDL_AppResult ProcessInput(SDL_Event* event);
	
	void UpdateGame();
	void GenerateOutput();

	void Shutdown();

private:
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
};