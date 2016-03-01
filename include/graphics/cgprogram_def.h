#ifndef CGL_GRAPHICS_CGPROGRAM_DEF_H
# define CGL_GRAPHICS_CGPROGRAM_DEF_H

# include "graphics/gl_def.h"
# include "graphics/shader_def.h"

# define CGL_CGPROGRAM_N_BINDS	16

typedef struct s_cgl_cgprogram	t_cgl_cgprogram;

struct				s_cgl_cgprogram
{
	GLuint			id;
	char			*binds[CGL_CGPROGRAM_N_BINDS];
	t_cgl_shader	*vertex;
	t_cgl_shader	*fragment;
	int				load;
};

#endif