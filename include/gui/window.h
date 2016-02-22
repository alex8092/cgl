#ifndef GAME_WINDOW_H
# define GAME_WINDOW_H

# include "gui/window_def.h"

t_cgl_window		*cgl_gui_window_create(const char *title, uint32_t width, uint32_t height);
void				cgl_gui_window_destroy(t_cgl_window *w);
// void				cgl_gui_window_swap(t_cgl_window *w);

#endif