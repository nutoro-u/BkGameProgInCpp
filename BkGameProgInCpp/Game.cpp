#include "Game.h"
#include <string>
#include <iostream>
#include <iomanip> // For std::setprecision and std::fixed
#include <sstream>

Game::Game() :
	mWindow(nullptr)
	, mRenderer(nullptr)
{
}

bool Game::Initialize()
{
	if (!SDL_CreateWindowAndRenderer(
		"Hello World", 1024, 576, SDL_WINDOW_OPENGL, &mWindow, &mRenderer))
	{
		SDL_Log("Couldn't create window and renderer: %s", SDL_GetError());
		return false;
	}

	return true;
}

SDL_AppResult Game::ProcessInput(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_EVENT_KEY_DOWN:
		if (event->key.key == SDLK_ESCAPE)
			return SDL_APP_SUCCESS;
		break;
	case SDL_EVENT_QUIT:
		return SDL_APP_SUCCESS;
	}

	// Get state of keyboard
	/*const bool* state = SDL_GetKeyboardState(NULL);

	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}*/

	return SDL_APP_CONTINUE;
}

void Game::UpdateGame(AppState* appState)
{
}

void Game::GenerateOutput(AppState* appState)
{
	SDL_SetRenderDrawColor(mRenderer, 32, 32, 64, 255);
	SDL_RenderClear(mRenderer);

#if _DEBUG
	ShowFps(appState);
#endif

	SDL_RenderPresent(mRenderer);
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

#if _DEBUG
void Game::ShowFps(AppState * appState)
{
	std::ostringstream strFps;
	strFps << std::fixed << std::setprecision(0) << fpsOld;
	
	showFpsTimer -= appState->delta_time;
	if (showFpsTimer < 0.0)
	{
		fpsOld = appState->fps;
		strFps << std::fixed << std::setprecision(0) << appState->fps;
		
		showFpsTimer = showFpsDuration;
	}
	std::string message = std::string("Fps: ") + strFps.str();

	int w = 0, h = 0;
	float x, y;
	const float scale = 2.0f;

	SDL_GetRenderOutputSize(mRenderer, &w, &h);
	SDL_SetRenderScale(mRenderer, scale, scale);
	x = ((w / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * SDL_strlen(message.c_str())) / 2;
	y = ((h / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE);

	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderDebugText(mRenderer, x, y, message.c_str());
}
#endif

//void Game::RunLoop()
//{
//	const int FPS = 60;
//	const int FRAME_DELAY = 1000 / FPS; // 16.66ms per frame
//
//	Uint32 frameStart;
//	int frameTime;
//
//	while (mIsRunning)
//	{
//		frameStart = SDL_GetTicks();
//
//     // 1. Handle Events (input)
    // 2. Update Game Logic
    // 3. Render Graphics
// 
//		// Calculate time taken for this frame
//		frameTime = SDL_GetTicks() - frameStart;
//
//		// 4. Delay to maintain FPS
//		if (FRAME_DELAY > frameTime)
//			SDL_Delay(FRAME_DELAY - frameTime);
//
//		SDL_Log("frame delay: %d", FRAME_DELAY - frameTime);
//	}
//}
