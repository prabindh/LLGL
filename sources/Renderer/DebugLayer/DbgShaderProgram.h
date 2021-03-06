/*
 * DbgShaderProgram.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_DBG_SHADER_PROGRAM_H__
#define __LLGL_DBG_SHADER_PROGRAM_H__


#include <LLGL/ShaderProgram.h>
#include <LLGL/RenderingDebugger.h>
#include <vector>


namespace LLGL
{


class DbgShader;

class DbgShaderProgram : public ShaderProgram
{

    public:

        struct VertexLayout
        {
            std::vector<VertexAttribute>    attributes;
            bool                            bound       = false;
        };

        DbgShaderProgram(ShaderProgram& instance, RenderingDebugger* debugger);

        void AttachShader(Shader& shader) override;
        void DetachAll() override;

        bool LinkShaders() override;

        std::string QueryInfoLog() override;
        std::vector<VertexAttribute> QueryVertexAttributes() const override;
        std::vector<StreamOutputAttribute> QueryStreamOutputAttributes() const override;
        std::vector<ConstantBufferViewDescriptor> QueryConstantBuffers() const override;
        std::vector<StorageBufferViewDescriptor> QueryStorageBuffers() const override;
        std::vector<UniformDescriptor> QueryUniforms() const override;

        void BuildInputLayout(const VertexFormat& vertexFormat) override;
        void BindConstantBuffer(const std::string& name, unsigned int bindingIndex) override;
        void BindStorageBuffer(const std::string& name, unsigned int bindingIndex) override;

        ShaderUniform* LockShaderUniform() override;
        void UnlockShaderUniform() override;

        inline const VertexLayout& GetVertexLayout() const
        {
            return vertexLayout_;
        }

        ShaderProgram& instance;

    private:

        void DebugShaderAttachment(DbgShader& shaderDbg);
        void DebugShaderComposition();

        RenderingDebugger*      debugger_               = nullptr;
        bool                    linked_                 = false;
        int                     shaderAttachmentMask_   = 0;

        std::vector<ShaderType> shaderTypes_;
        VertexLayout            vertexLayout_;

};


} // /namespace LLGL


#endif



// ================================================================================
