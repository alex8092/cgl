#include "math/mat4.h"
#include <memory.h>

t_cgl_mat4		*cgl_math_mat4_create(int ident)
{
	t_cgl_mat4	*m = 0;

	m = malloc(sizeof(*m));
	if (!m)
	{
		dprintf(2, "Cannot allocate memory\n");
		return (0);
	}
	return (m);
}

t_cgl_mat4		*cgl_math_mat4_identity(t_cgl_mat4 *m)
{
	int			i;

	if (m)
	{
		for (i = 0;i < 16; ++i)
			m->values[i] = 0;
		m->values[0] = 1;
		m->values[5] = 1;
		m->values[10] = 1;
		m->values[15] = 1;
	}
	return (m);
}

void			cgl_math_mat4_destroy(t_cgl_mat4 *m)
{
	t_cgl_mat4	*tmp;

	tmp = m;
	while (tmp)
	{
		m = tmp->prev_state;
		free(tmp);
		tmp = m;
	}
}