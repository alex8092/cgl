#include "engine/system.h"
#include "gui/window.h"
#include <memory.h>

t_cgl_engine	*cgl_engine_system_instance(void)
{
	static t_cgl_engine	instance;
	static int			init = 0;

	if (!init)
	{
		bzero((void *)&instance, sizeof(instance));
		init = 1;
	}
	return (&instance);
}

int				cgl_engine_system_init(const char *title, uint32_t width, uint32_t height)
{
	static t_cgl_engine	*engine = 0;

	if (!engine)
		engine = cgl_engine_system_instance();
	if (!engine->init)
	{
		engine->win = cgl_gui_window_create(title, width, height);
		if (!engine->win)
			return (-1);
		engine->init = 1;
	}
	return (0);
}

int				cgl_engine_system_run(int (*run_func)(t_cgl_engine *))
{
	static t_cgl_engine *engine = 0;

	if (!engine)
		engine = cgl_engine_system_instance();
	if (!run_func || !engine->win)
		return (-1);
	while (1)
	{
		SDL_WaitEvent(&engine->win->ev);

		if (engine->win->ev.type == SDL_QUIT)
			return (0);
		else if (run_func(engine) == 1)
			return (0);
		SDL_GL_SwapWindow(engine->win->handle);
	}
}

void			cgl_engine_system_deinit(void)
{
	t_cgl_engine * const engine = cgl_engine_system_instance();

	if (engine->win)
	{
		cgl_gui_window_destroy(engine->win);
		engine->win = 0;
		engine->init = 0;
	}
}