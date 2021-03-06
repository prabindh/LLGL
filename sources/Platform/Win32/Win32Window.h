/*
 * Win32Window.h
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_WIN32_WINDOW_H__
#define __LLGL_WIN32_WINDOW_H__


#include <LLGL/Window.h>
#include <Windows.h>


namespace LLGL
{


class Win32Window : public Window
{

    public:

        Win32Window(const WindowDescriptor& desc);
        ~Win32Window();

        void SetPosition(const Point& position) override;
        Point GetPosition() const override;

        void SetSize(const Size& size, bool useClientArea = true) override;
        Size GetSize(bool useClientArea = true) const override;

        void SetTitle(const std::wstring& title) override;
        std::wstring GetTitle() const override;

        void Show(bool show = true) override;
        bool IsShown() const override;

        WindowDescriptor QueryDesc() const override;

        void SetDesc(const WindowDescriptor& desc) override;

        void Recreate(const WindowDescriptor& desc) override;

        void GetNativeHandle(void* nativeHandle) const override;

    private:
        
        void ProcessSystemEvents() override;

        HWND CreateWindowHandle(const WindowDescriptor& desc);

        WindowDescriptor    desc_;

        HWND                wnd_    = nullptr;

};


} // /namespace LLGL


#endif



// ================================================================================
