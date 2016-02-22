#ifndef CGL_GUI_EVENT_DEF_H
# define CGL_GUI_EVENT_DEF_H

typedef struct s_cgl_event	t_cgl_event;

enum						e_cgl_event
{
	CGL_EVENT_NO_ONE		= 0,
	CGL_EVENT_CLOSE_WINDOW 	= 1
};

struct						s_cgl_event
{
	enum e_cgl_event		type;
};

#endif