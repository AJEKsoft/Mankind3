#pragma once

#include <stdbool.h>

#include <SDL2/SDL.h>

#include "mesh.h"
#include "utilities.h"
#include "map.h"
#include "program.h"

typedef struct engine_t {
	SDL_Window *window;
	SDL_GLContext context;

	program_t program;
	mesh_t mesh;
	Map map;

	bool running;
} engine_t;

engine_t engine_new();
void engine_handle_event(engine_t * engine, SDL_Event * event);
void engine_update(engine_t * engine);
void engine_render(engine_t * engine);
void engine_terminate(engine_t * engine);