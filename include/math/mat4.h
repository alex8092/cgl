#ifndef CGL_MATH_MAT4_H
# define CGL_MATH_MAT4_H

# include "math/mat4_def.h"

/*
** Call to create an 4*4 matrix
** ident: Set to 1 to automatic set up of identity matrix
*/
t_cgl_mat4	*cgl_math_mat4_create(int ident);

t_cgl_mat4	*cgl_math_mat4_identity(t_cgl_mat4 *m);
void		cgl_math_mat4_destroy(t_cgl_mat4 *m);

#endif