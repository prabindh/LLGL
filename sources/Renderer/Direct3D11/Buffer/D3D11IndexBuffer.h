/*
 * D3D11IndexBuffer.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_D3D11_INDEX_BUFFER_H__
#define __LLGL_D3D11_INDEX_BUFFER_H__


#include "D3D11Buffer.h"
#include <dxgiformat.h>


namespace LLGL
{


class D3D11IndexBuffer : public D3D11Buffer
{

    public:

        D3D11IndexBuffer(ID3D11Device* device, const BufferDescriptor& desc, const void* initialData = nullptr);

        inline DXGI_FORMAT GetFormat() const
        {
            return format_;
        }

    private:

        DXGI_FORMAT format_ = DXGI_FORMAT_UNKNOWN;

};


} // /namespace LLGL


#endif



// ================================================================================
