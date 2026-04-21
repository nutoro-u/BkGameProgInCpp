#pragma once
#include "SDL3/SDL.h"

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

	Uint32 mTicksCount;
	bool mIsRunning;
};