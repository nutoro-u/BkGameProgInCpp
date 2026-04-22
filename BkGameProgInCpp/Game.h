#pragma once
#include "SDL3/SDL.h"

typedef struct
{
	Uint64 last_time;
	double delta_time; // Frame duration in seconds
	double fps;
} AppState;

class Game
{
public:
	Game();

	bool Initialize();

	SDL_AppResult ProcessInput(SDL_Event* event);
	void UpdateGame(AppState* appState);
	void GenerateOutput(AppState* appState);

	void Shutdown();

private:
#if _DEBUG
	void ShowFps(AppState* appState);

	double showFpsTimer{ showFpsDuration };
	const double showFpsDuration{ 1.0 };
	double fpsOld{ 0.0 };
#endif

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
};