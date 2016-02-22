#ifndef CGL_GUI_WINDOW_DEF_H
# define CGL_GUI_WINDOW_DEF_H

# include <stdint.h>
# include <SDL2/SDL.h>

typedef struct 		s_cgl_window
{
	SDL_Window		*handle;
	SDL_Event		ev;
	SDL_GLContext	gl;
	uint32_t		width;
	uint32_t		height;
	uint8_t			gl_major;
	uint8_t			gl_minor;
	const char		*title;
}					t_cgl_window;

#endif