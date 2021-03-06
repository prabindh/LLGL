/*
 * D3D11Texture.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_D3D11_TEXTURE_H__
#define __LLGL_D3D11_TEXTURE_H__


#include <LLGL/Texture.h>
#include <d3d11.h>
#include "../../ComPtr.h"


namespace LLGL
{


union D3D11HardwareTexture
{
    D3D11HardwareTexture() :
        resource( nullptr )
    {
    }
    ~D3D11HardwareTexture()
    {
    }

    ComPtr<ID3D11Resource>  resource;
    ComPtr<ID3D11Texture1D> tex1D;
    ComPtr<ID3D11Texture2D> tex2D;
    ComPtr<ID3D11Texture3D> tex3D;
};


class D3D11Texture : public Texture
{

    public:

        D3D11Texture(const TextureType type);

        Gs::Vector3ui QueryMipLevelSize(unsigned int mipLevel) const override;

        /* ----- Extended internal functions ---- */

        void CreateTexture1D(
            ID3D11Device* device,
            const D3D11_TEXTURE1D_DESC& desc,
            const D3D11_SUBRESOURCE_DATA* initialData = nullptr,
            const D3D11_SHADER_RESOURCE_VIEW_DESC* srvDesc = nullptr
        );

        void CreateTexture2D(
            ID3D11Device* device,
            const D3D11_TEXTURE2D_DESC& desc,
            const D3D11_SUBRESOURCE_DATA* initialData = nullptr,
            const D3D11_SHADER_RESOURCE_VIEW_DESC* srvDesc = nullptr
        );

        void CreateTexture3D(
            ID3D11Device* device,
            const D3D11_TEXTURE3D_DESC& desc,
            const D3D11_SUBRESOURCE_DATA* initialData = nullptr,
            const D3D11_SHADER_RESOURCE_VIEW_DESC* srvDesc = nullptr
        );

        void UpdateSubresource(
            ID3D11DeviceContext* context,
            UINT mipSlice, UINT arraySlice, const D3D11_BOX& dstBox,
            const ImageDescriptor& imageDesc,
            std::size_t threadCount
        );

        // Creates a copy of the specified subresource of the hardware texture with CPU read access.
        void CreateSubresourceCopyWithCPUAccess(
            ID3D11Device* device, ID3D11DeviceContext* context,
            D3D11HardwareTexture& textureCopy,
            UINT cpuAccessFlags,
            unsigned int mipLevel
        ) const;

        inline const D3D11HardwareTexture& GetHardwareTexture() const
        {
            return hardwareTexture_;
        }

        // Returns the shader-resource-view (SRV) of the hardware texture object.
        inline ID3D11ShaderResourceView* GetSRV() const
        {
            return srv_.Get();
        }

        // Returns the hardware resource format.
        inline DXGI_FORMAT GetFormat() const
        {
            return format_;
        }

        // Returns the number of MIP-map levels.
        inline UINT GetNumMipLevels() const
        {
            return numMipLevels_;
        }

    private:

        void CreateSRV(ID3D11Device* device, const D3D11_SHADER_RESOURCE_VIEW_DESC* srvDesc = nullptr);

        void CreateSRVAndStoreSettings(
            ID3D11Device* device, DXGI_FORMAT format, const Gs::Vector3ui& size,
            const D3D11_SHADER_RESOURCE_VIEW_DESC* srvDesc = nullptr
        );

        D3D11HardwareTexture                hardwareTexture_;//hwTexture_
        ComPtr<ID3D11ShaderResourceView>    srv_;

        DXGI_FORMAT                         format_             = DXGI_FORMAT_UNKNOWN;
        UINT                                numMipLevels_       = 0;

};


} // /namespace LLGL


#endif



// ================================================================================
