#define MICHAEL 67
#define SDL_MAIN_USE_CALLBACKS 1

#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include "SDL3/SDL_main.h"
#include "SDL3/SDL_init.h"
#include "SDL3_net/SDL_net.h"
#include "John/Universe.h"
#include "John/Entity.h"

// Frame Time Calculation Variables
float DeltaTime;
int LastTime = 0;
int CurrentTime = 0;

// Handle to main window
SDL_Window* WndMain;

// John Stuff
Universe* JohnUniverse = new Universe();
Entity* JohnEntity = new Entity(16, 16, 32, JohnUniverse);

// Runs once at startup
SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {

	// Initialize SDL Video Features, handle errors
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error!", "Couldn't initialize network features.\nPlease ensure sdl3.dll exists and is in the correct directory.", WndMain);
		return SDL_APP_FAILURE;
	}

	// Initialize SDL Network Features, handle errors
	if (!NET_Init()) {
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal Error!", "Couldn't initialize network features.\nPlease ensure sdl3_net.dll exists and is in the correct directory.", WndMain);
		return SDL_APP_FAILURE;
	}
	
	// Create the main window
	WndMain = SDL_CreateWindow("Scrimblo Jingus", 800, 600, SDL_WINDOW_RESIZABLE);
	
	// Testing John Stuff
	printf("Universe created with a width of %d, and a height of %d\n", JohnUniverse->GetWidth(), JohnUniverse->GetHeight());
	printf("Entity spawned at %f,%f with a size of %d\n", JohnEntity->GetXPosition(), JohnEntity->GetYPosition(), JohnEntity->GetScale());
	JohnEntity->SetPosition(1077.f, 44.9f);
	printf("Entity moved to %f, %f\n", JohnEntity->GetXPosition(), JohnEntity->GetYPosition());
	return SDL_APP_CONTINUE;


}

// Runs repeatedly until instructed to quit
SDL_AppResult SDL_AppIterate(void* appstate) {
	// Calculate Frame Time
	LastTime = CurrentTime;
	CurrentTime = SDL_GetTicks();

	DeltaTime = (float)(CurrentTime - LastTime) / 1000.f;
	//printf("%f\n", DeltaTime);
	return SDL_APP_CONTINUE;
}

// Handles incoming events
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {

	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}

	return SDL_APP_CONTINUE;
}


// Runs once before program closes
void SDL_AppQuit(void* appstate, SDL_AppResult result) {
	// Free memory of John objects
	delete JohnUniverse;
	delete JohnEntity;
	// Shut down network features
	NET_Quit();
	// Shut down main SDL features
	SDL_Quit();
}
