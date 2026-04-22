#pragma once
#include "SDL3/SDL.h"

typedef struct
{
	Uint64 last_time;
	float delta_time; // Frame duration in seconds
	float fps;
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

	float showFpsTimer{ showFpsDuration };
	const float showFpsDuration{ 1.0f };
	float fpsOld{ 0.0f };
#endif

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
};