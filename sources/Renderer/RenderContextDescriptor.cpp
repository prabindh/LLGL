/*
 * RenderContextDescriptor.cpp
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include <LLGL/RenderContextDescriptor.h>
#include "../Core/HelperMacros.h"


namespace LLGL
{


LLGL_EXPORT bool operator == (const VsyncDescriptor& lhs, const VsyncDescriptor& rhs)
{
    return
    (
        LLGL_COMPARE_MEMBER_EQ( enabled     ) &&
        LLGL_COMPARE_MEMBER_EQ( refreshRate ) &&
        LLGL_COMPARE_MEMBER_EQ( interval    )
    );
}

LLGL_EXPORT bool operator != (const VsyncDescriptor& lhs, const VsyncDescriptor& rhs)
{
    return !(lhs == rhs);
}

LLGL_EXPORT bool operator == (const VideoModeDescriptor& lhs, const VideoModeDescriptor& rhs)
{
    return
    (
        LLGL_COMPARE_MEMBER_EQ( resolution    ) &&
        LLGL_COMPARE_MEMBER_EQ( colorDepth    ) &&
        LLGL_COMPARE_MEMBER_EQ( fullscreen    ) &&
        LLGL_COMPARE_MEMBER_EQ( swapChainMode )
    );
}

LLGL_EXPORT bool operator != (const VideoModeDescriptor& lhs, const VideoModeDescriptor& rhs)
{
    return !(lhs == rhs);
}


} // /namespace LLGL



// ================================================================================
