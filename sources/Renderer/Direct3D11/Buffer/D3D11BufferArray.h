/*
 * D3D11BufferArray.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_D3D11_BUFFER_ARRAY_H__
#define __LLGL_D3D11_BUFFER_ARRAY_H__


#include <LLGL/BufferArray.h>
#include <d3d11.h>
#include <vector>


namespace LLGL
{


class Buffer;

class D3D11BufferArray : public BufferArray
{

    public:

        D3D11BufferArray(const BufferType type, unsigned int numBuffers, Buffer* const * bufferArray);

        //! Returns the array of buffer objects.
        inline const std::vector<ID3D11Buffer*>& GetBuffers() const
        {
            return buffers_;
        }

    private:

        std::vector<ID3D11Buffer*> buffers_;

};


} // /namespace LLGL


#endif



// ================================================================================
