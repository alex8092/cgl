#ifndef CGL_GRAPHICS_CGPROGRAM_H
# define CGL_GRAPHICS_CGPROGRAM_H

# include "graphics/cgprogram_def.h"

t_cgl_cgprogram	*cgl_graphics_cgprogram_create(t_cgl_shader *vertex, t_cgl_shader *fragment);
void			cgl_graphics_cgprogram_destroy(t_cgl_cgprogram *p);
int				cgl_graphics_cgprogram_load(t_cgl_cgprogram *p);
int				cgl_graphics_cgprogram_bind_location(t_cgl_cgprogram *p, GLuint n, const char *value);
GLuint			cgl_graphics_cgprogram_get_id(t_cgl_cgprogram *p);

#endif