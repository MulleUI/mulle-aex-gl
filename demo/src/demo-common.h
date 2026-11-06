#ifndef DEMO_COMMON_H
#define DEMO_COMMON_H

#include <SDL3/SDL.h>

#include "gl_es2_impl.h"


int   demo_check_shader( gl_es2_uint shader);
int   demo_check_program( gl_es2_uint program);
int   demo_present( SDL_Window *window, unsigned char *pixels);
void  demo_gradient_background( int width, int height);

#endif
