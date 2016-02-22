#ifndef CGL_ENGINE_SYSTEM_DEF_H
# define CGL_ENGINE_SYSTEM_DEF_H

# include <stdint.h>
# include "gui/window_def.h"

typedef struct s_cgl_engine	t_cgl_engine;

struct				s_cgl_engine
{
	t_cgl_window	*win;
	int				init;
};

#endif