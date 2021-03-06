/*
 * Exception.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_EXCEPTION_H__
#define __LLGL_EXCEPTION_H__


#include <LLGL/Export.h>
#include <string>


namespace LLGL
{


// Throws an std::runtime_error exception with the message, that the specified feature is not supported by the renderer.
[[noreturn]]
LLGL_EXPORT void ThrowNotSupported(const std::string& featureName);

// Throws an std::runtime_error exception with the message, that the specified interface function is not implemented yet.
[[noreturn]]
LLGL_EXPORT void ThrowNotImplemented(const std::string& functionName);


} // /namespace LLGL


#endif



// ================================================================================
