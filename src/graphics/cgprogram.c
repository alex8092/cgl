#include "graphics/cgprogram.h"
#include "graphics/shader.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

static void			cgl_graphics_cgprogram_bind_locations(t_cgl_cgprogram *p)
{
	int				index;

	for (index = 0; index < CGL_CGPROGRAM_N_BINDS; ++index)
	{
		if (p->binds[index])
			glBindAttribLocation(p->id, (GLuint)index, p->binds[index]);
	}
}

static int			cgl_graphics_cgprogram_link(t_cgl_cgprogram *p)
{
	GLint			isok = 0;
	GLint			errsize = 0;
	char			*error = 0;

	glLinkProgram(p->id);
	glGetProgramiv(p->id, GL_LINK_STATUS, &isok);

	if (isok == GL_FALSE)
	{
		glGetProgramiv(p->id, GL_INFO_LOG_LENGTH, &errsize);
		error = malloc(sizeof(char) * (errsize + 1));
		if (!error)
		{
			dprintf(2, "Allocation failure\n");
			return (-1);
		}
		glGetShaderInfoLog(p->id, errsize, &errsize, error);
		error[errsize] = 0;
		dprintf(2, "Cannot link cg program : %p\n", error);
		free(error);
		return (-1);
	}
	return (0);
}

t_cgl_cgprogram		*cgl_graphics_cgprogram_create(t_cgl_shader *vertex, t_cgl_shader *fragment)
{
	t_cgl_cgprogram	*p = 0;

	if (!vertex || !fragment)
		return (0);
	p = malloc(sizeof(*p));
	if (!p)
	{
		dprintf(2, "Cannot allocate\n");
		return (0);
	}
	bzero((void *)p, sizeof(*p));
	p->id = glCreateProgram();
	if (p->id == 0)
	{
		dprintf(2, "Cannot create an cg program\n");
		free(p);
		return (0);
	}
	if (cgl_graphics_shader_load(vertex) == -1 || cgl_graphics_shader_load(fragment) == -1)
	{
		dprintf(2, "Cannot load shaders for program\n");
		glDeleteProgram(p->id);
		free(p);
		return (0);
	}
	glAttachShader(p->id, cgl_graphics_shader_get_id(vertex));
	glAttachShader(p->id, cgl_graphics_shader_get_id(fragment));
	return (p);
}

int					cgl_graphics_cgprogram_load(t_cgl_cgprogram *p)
{
	if (!p)
		return (-1);
	if (p->load == 0)
	{
		cgl_graphics_cgprogram_bind_locations(p);
		if (cgl_graphics_cgprogram_link(p) == -1)
			return (-1);
		p->load = 1;
	}
	return (p->load == 0 ? -1 : 0);
}

int					cgl_graphics_cgprogram_bind_location(t_cgl_cgprogram *p, GLuint n, const char *value)
{
	if (!p || !value || n >= CGL_CGPROGRAM_N_BINDS)
		return (-1);
	p->binds[n] = strdup(value);
	if (!p->binds[n])
	{
		dprintf(2, "Allocation failure (strdup)\n");
		return (-1);
	}
	return (0);
}

GLuint				cgl_graphics_cgprogram_get_id(t_cgl_cgprogram *p)
{
	return (p ? p->id : 0);
}