#ifndef CGL_MATH_MAT4_DEF_H
# define CGL_MATH_MAT4_DEF_H

typedef struct s_cgl_mat4	t_cgl_mat4;

struct			s_cgl_mat4
{
	double		values[16];
	t_cgl_mat4	*prev_state;
};

#endif