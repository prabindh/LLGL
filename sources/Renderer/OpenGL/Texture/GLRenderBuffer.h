/*
 * GLRenderBuffer.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_GL_RENDER_BUFFER_H__
#define __LLGL_GL_RENDER_BUFFER_H__


#include "GLTexture.h"
#include <Gauss/Vector2.h>


namespace LLGL
{


class GLRenderBuffer
{

    public:

        GLRenderBuffer(const GLRenderBuffer&) = delete;
        GLRenderBuffer& operator = (const GLRenderBuffer&) = delete;

        GLRenderBuffer();
        ~GLRenderBuffer();

        void Bind() const;
        void Unbind() const;

        //! Recreates the internal renderbuffer object. This will invalidate the previous buffer ID.
        void Recreate();

        static void Storage(GLenum internalFormat, const Gs::Vector2i& size, GLsizei samples);

        //! Returns the hardware buffer ID.
        inline GLuint GetID() const
        {
            return id_;
        }

    private:

        GLuint id_ = 0;

};


} // /namespace LLGL


#endif



// ================================================================================
