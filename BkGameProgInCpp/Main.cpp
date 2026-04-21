#define SDL_MAIN_USE_CALLBACKS 1
#include "Game.h"
#include <SDL3/SDL_main.h>

static Game* game;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	
	game = new Game();
	bool success = game->Initialize();

	return success ? SDL_APP_CONTINUE : SDL_APP_FAILURE;
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
	return game->ProcessInput(event);
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
	game->UpdateGame();
	game->GenerateOutput();

	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}

//int main(int argc, char** argv)
//{
//	Game game;
//	bool success = game.Initialize();
//	if (success)
//	{
//		game.RunLoop();
//	}
//	game.Shutdown();
//	return 0;
//}