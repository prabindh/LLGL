/*
 * ModuleInterface.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_MODULE_INTERFACE_H__
#define __LLGL_MODULE_INTERFACE_H__


#include "BuildID.h"
#include <LLGL/Export.h>


extern "C"
{

/*
Returns the build ID number of the render system.
This depends on the type and version of the used compiler, the debug/release mode, and an internal build version.
The returned value must be equal to the value of the LLGL_BUILD_ID macro.
Otherwise the render system might not be loaded correctly.
*/
LLGL_EXPORT int LLGL_RenderSystem_BuildID();

// Returns a raw pointer to the allocated render system (allocated with "new" keyword)
LLGL_EXPORT void* LLGL_RenderSystem_Alloc();

// Returns the name of this audio system module.
LLGL_EXPORT const char* LLGL_RenderSystem_Name();

}


#endif



// ================================================================================
