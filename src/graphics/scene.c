#include "graphics/scene.h"
#include "graphics/cgprogram.h"

void	cgl_tmp_draw(t_cgl_cgprogram *p)
{
	static float vertices[] = {-0.5, -0.5,   0.0, 0.5,   0.5, -0.5};
	static float couleurs[] = {1.0, 0.0, 0.0,  0.0, 1.0, 0.0,  0.0, 0.0, 1.0};

	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(cgl_graphics_cgprogram_get_id(p));

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glEnableVertexAttribArray(0);


    // Envoi des couleurs

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, couleurs);
    glEnableVertexAttribArray(1);


    // Affichage du triangle

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);

	
	glUseProgram(0);
}