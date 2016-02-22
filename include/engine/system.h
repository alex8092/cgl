#ifndef CGL_ENGINE_SYSTEM_H
# define CGL_ENGINE_SYSTEM_H

# include "engine/system_def.h"

t_cgl_engine	*cgl_engine_system_instance(void);
int				cgl_engine_system_init(const char *title, uint32_t width, uint32_t height);	
int				cgl_engine_system_run(int (*run_func)(t_cgl_engine *));
void			cgl_engine_system_deinit(void);

#endif