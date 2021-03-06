/*
 * GLContext.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_GL_CONTEXT_H__
#define __LLGL_GL_CONTEXT_H__


#include <LLGL/Window.h>
#include <LLGL/RenderContextDescriptor.h>
#include <memory>
#include "../RenderState/GLStateManager.h"


namespace LLGL
{


class GLContext
{

    public:

        virtual ~GLContext();

        // Creates a platform specific GLContext instance.
        static std::unique_ptr<GLContext> Create(RenderContextDescriptor& desc, Window& window, GLContext* sharedContext);

        // Makes the specified GLContext current. If null, the current context will be deactivated.
        static bool MakeCurrent(GLContext* context);

        // Returns the active GLContext instance.
        static GLContext* Active();

        // Sets the swap interval for vsync (Win32: wglSwapIntervalEXT, X11: glXSwapIntervalSGI).
        virtual bool SetSwapInterval(int interval) = 0;

        // Swaps the back buffer with the front buffer (Win32: ::SwapBuffers, X11: glXSwapBuffers).
        virtual bool SwapBuffers() = 0;

        inline const std::shared_ptr<GLStateManager>& GetStateManager() const
        {
            return stateMngr_;
        }

    protected:

        GLContext(GLContext* sharedContext);

        // Activates or deactivates this GLContext (Win32: wglMakeCurrent, X11: glXMakeCurrent).
        virtual bool Activate(bool activate) = 0;

    private:

        std::shared_ptr<GLStateManager> stateMngr_;

};


} // /namespace LLGL


#endif



// ================================================================================
