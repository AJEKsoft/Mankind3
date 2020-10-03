#pragma once

#include <GL/glew.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

#include "math_3d.h"
#include "program.h"

#include "map.h"
#include "texture.h"
#include "camera.h"

typedef struct ChunkGenQueue ChunkGenQueue;
struct ChunkGenQueue{
  Chunk *chunk;
  ChunkGenQueue* next;
};

typedef struct {
	SDL_Window *window;
	SDL_GLContext gl_context;

	program_t main_program;
	Texture tilemap;
	Camera camera;
	ChunkGenQueue* first_gen_chunk;
	ChunkGenQueue* last_gen_chunk;
	int queue_size;
} GFXContext;

void init_GFX(GFXContext * gfx_context, int window_width, int window_height);

void draw_Map(GFXContext * gfx_context, Map * map);

void draw_Chunk(Chunk * chunk, void *gfx_context);

void draw_Mesh(GFXContext * gfx_context, mesh_t * mesh, vec3_t position);

void quit_GFX(GFXContext * gfx_context);

void begin_draw(GFXContext * gfx_context);

void end_draw(GFXContext * gfx_context);

void push_Chunk_to_queue(GFXContext* gfx_context, Chunk* chunk);

void gen_Chunks_in_queue(GFXContext* gfx_context, Map* map, int max_gens);

