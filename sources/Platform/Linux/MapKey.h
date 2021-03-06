/*
 * MapKey.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_MAP_KEY_H__
#define __LLGL_MAP_KEY_H__


#include <LLGL/Key.h>
#include <X11/Xlib.h>


namespace LLGL
{


Key MapKey(XKeyEvent& keyEvent);


} // /namespace LLGL


#endif



// ================================================================================
