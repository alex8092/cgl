#ifndef CGL_GRAPHICS_SHADER_DEF_H
# define CGL_GRAPHICS_SHADER_DEF_H

# include "graphics/gl_def.h"

typedef struct s_cgl_shader	t_cgl_shader;

enum						e_cgl_shader_type
{
	CGL_SHADER_VERTEX 		= GL_VERTEX_SHADER,
	CGL_SHADER_FRAGMENT 	= GL_FRAGMENT_SHADER
};

struct						s_cgl_shader
{
	enum e_cgl_shader_type	type;
	char					*src;
	size_t					size;
	GLuint					id;
};

#endif