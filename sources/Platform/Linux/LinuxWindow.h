/*
 * LinuxWindow.h
 *
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#ifndef __LLGL_LINUX_WINDOW_H__
#define __LLGL_LINUX_WINDOW_H__


#include <LLGL/Window.h>
#include <X11/Xlib.h>


namespace LLGL
{


class LinuxWindow : public Window
{

    public:

        LinuxWindow(const WindowDescriptor& desc);
        ~LinuxWindow();

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

        void OpenWindow();

        void ProcessKeyEvent(XKeyEvent& event, bool down);
        void ProcessMouseKeyEvent(XButtonEvent& event, bool down);
        void ProcessResizeRequestEvent(XResizeRequestEvent& event);

        void PostMouseKeyEvent(Key key, bool down);
        
        WindowDescriptor    desc_;

        ::Display*          display_    = nullptr;
        //::Colormap          colorMap_;
        ::Window            wnd_;
        //::Cursor            cursor_;
        XVisualInfo*        visual_     = nullptr;

};


} // /namespace LLGL


#endif



// ================================================================================
