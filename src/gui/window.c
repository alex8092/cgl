#include "gui/window.h"
#include <stdlib.h>
#include <stdio.h>

t_cgl_window	*cgl_gui_window_create(const char *title, uint32_t width, uint32_t height)
{
	t_cgl_window	*w;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Unable to start SDL: %s\n", SDL_GetError());
		SDL_Quit();
		return (0);
	}
	w = malloc(sizeof(*w));
	w->title = title;
	w->width = width;
	w->height = height;
	w->gl_major = 3;
	w->gl_minor = 2;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, w->gl_major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, w->gl_minor);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	w->handle = SDL_CreateWindow(w->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w->width, w->height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (!w->handle)
	{
		printf("Unable to create the window: %s\n", SDL_GetError());
		SDL_Quit();
		free(w);
		return (0);
	}
	w->gl = SDL_GL_CreateContext(w->handle);
	if (!w->gl)
	{
		printf("Cannot open an openGL context: %s\n", SDL_GetError());
		SDL_DestroyWindow(w->handle);
		SDL_Quit();
		free(w);
		return (0);
	}
	return (w);
}

void		cgl_gui_window_destroy(t_cgl_window *w)
{
	SDL_GL_DeleteContext(w->gl);
	SDL_DestroyWindow(w->handle);
	SDL_Quit();
	free(w);
}