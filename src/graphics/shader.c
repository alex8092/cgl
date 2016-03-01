#include "graphics/shader.h"
#include "fs/file.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

t_cgl_shader		*cgl_graphics_shader_create(const char *file, enum e_cgl_shader_type type)
{
	t_cgl_shader	*s = 0;

	s = malloc(sizeof(*s));
	if (!s)
	{
		dprintf(2, "Cannot allocate memory for shader\n");
		return (0);
	}
	bzero((void *)s, sizeof(*s));
	s->type = type;
	s->src = cgl_fs_read_file(file, &s->size);
	if (!s->src)
	{
		cgl_graphics_shader_destroy(s);
		return (0);
	}
	return (s);
}

static int			cgl_graphics_shader_test(t_cgl_shader *s)
{
	GLint			isok = 0;
	GLint			errsize = 0;
	char			*error = 0;

	glGetShaderiv(s->id, GL_COMPILE_STATUS, &isok);
	if (isok != GL_TRUE)
	{
		glGetShaderiv(s->id, GL_INFO_LOG_LENGTH, &errsize);
		error = malloc(sizeof(char) * (errsize + 1));
		if (!error)
		{
			dprintf(2, "Allocation failure\n");
			return (-1);
		}
		glGetShaderInfoLog(s->id, errsize, &errsize, error);
		error[errsize] = 0;
		dprintf(2, "Compilation shader error: %s\n", error);
		free(error);
		return (-1);
	}
	return (0);
}


int					cgl_graphics_shader_load(t_cgl_shader *s)
{
	const GLchar	*tmp = 0;

	if (!s)
		return (-1);
	if (s->id == 0)
	{
		s->id = glCreateShader((GLenum)s->type);
		if (s->id == 0)
		{
			dprintf(2, "Cannot create shader\n");
			return (-1);
		}
		tmp = (const GLchar *)s->src;
		glShaderSource(s->id, 1, &tmp, 0);
		glCompileShader(s->id);
		if (cgl_graphics_shader_test(s) == -1)
		{
			glDeleteShader(s->id);
			s->id = 0;
			return (-1);
		}
	}
	return (0);
}

void				cgl_graphics_shader_destroy(t_cgl_shader *s)
{
	if (s->src)
		free(s->src);
	free(s);
}

GLuint				cgl_graphics_shader_get_id(t_cgl_shader *s)
{
	return (s ? s->id : 0);
}