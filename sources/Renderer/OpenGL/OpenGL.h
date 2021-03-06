/*
 * OpenGL.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_OPENGL_H__
#define __LLGL_OPENGL_H__


#if defined(WIN32)
#   include <Windows.h>
#   include <gl/GL.h>
#   include <GL/glext.h>
#   include <GL/wglext.h>
#elif defined(__linux__)
#   include <GL/gl.h>
#   include <GL/glext.h>
#   include <GL/glx.h>
#elif defined(__APPLE__)
#   include <OpenGL/gl3.h>
#   include <OpenGL/glext.h>
#   include "Platform/MacOS/MacOSGLExt.h"
#endif


#endif



// ================================================================================
