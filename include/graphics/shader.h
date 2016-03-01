#ifndef CGL_GRAPHICS_SHADERS_H
# define CGL_GRAPHICS_SHADERS_H

# include "graphics/shader_def.h"

t_cgl_shader	*cgl_graphics_shader_create(const char *file, enum e_cgl_shader_type type);
int				cgl_graphics_shader_load(t_cgl_shader *s);
void			cgl_graphics_shader_destroy(t_cgl_shader *s);
GLuint			cgl_graphics_shader_get_id(t_cgl_shader *s);

#endif