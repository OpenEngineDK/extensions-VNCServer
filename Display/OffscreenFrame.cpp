#include "OffscreenFrame.h"

#include <Logging/Logger.h>

#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/Xlib.h>

#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glu.h>


namespace OpenEngine {
namespace Display {

OffscreenFrame::OffscreenFrame(int w, int h)
    : width(w)
    , height(h)
    , canvas(NULL)
    , fc(*this) {
}

bool OffscreenFrame::IsFocused() const {
    return 0;
}

unsigned int OffscreenFrame::GetWidth() const {
    return width;
}
unsigned int OffscreenFrame::GetHeight() const {
    return height;
}
unsigned int OffscreenFrame::GetDepth() const {
    return 32;
}
FrameOption OffscreenFrame::GetOptions() const {
    return options;
}
bool OffscreenFrame::GetOption(const FrameOption option) const {
    return (option & GetOptions()) == option;

}

void OffscreenFrame::SetWidth(const unsigned int width){}
void OffscreenFrame::SetHeight(const unsigned int height){}
void OffscreenFrame::SetDepth(const unsigned int depth){}
void OffscreenFrame::SetOptions(const FrameOption options){}
void OffscreenFrame::ToggleOption(const FrameOption option){}


void OffscreenFrame::Handle(Core::InitializeEventArg arg) {
    ::Display* g_pDisplay = XOpenDisplay(NULL);

    
    int scrnum = DefaultScreen( g_pDisplay );
    int nitems;

    int attrib[] = 
    {
        GLX_DOUBLEBUFFER,  False,
        GLX_RED_SIZE,      1,
        GLX_GREEN_SIZE,    1,
        GLX_BLUE_SIZE,     1,
        GLX_DEPTH_SIZE,    1,
        GLX_RENDER_TYPE,   GLX_RGBA_BIT,
        GLX_DRAWABLE_TYPE, GLX_PBUFFER_BIT | GLX_WINDOW_BIT,
        None
    };

    int pbufAttrib[] = 
    {
        GLX_PBUFFER_WIDTH,   width,
        GLX_PBUFFER_HEIGHT,  height,
        GLX_LARGEST_PBUFFER, False,
        None
    };


    GLXFBConfig* fbconfig = glXChooseFBConfig( g_pDisplay,
                                  scrnum,
                                  attrib,
                                  &nitems );


    // Create pb
    GLXPbuffer g_pbuffer = glXCreatePbuffer(g_pDisplay, fbconfig[0], pbufAttrib);

    XVisualInfo *visinfo = glXGetVisualFromFBConfig( g_pDisplay, fbconfig[0] );
;


    GLXContext g_pbufferContext = 
        glXCreateContext( g_pDisplay,
                          visinfo,
                          NULL,
                          GL_TRUE );


    glXMakeCurrent( g_pDisplay, g_pbuffer, g_pbufferContext );


    ((IListener<Display::InitializeEventArg>*)canvas)->
        Handle(Display::InitializeEventArg(fc));
}
void OffscreenFrame::Handle(Core::ProcessEventArg arg) {
    ((IListener<Display::ProcessEventArg>*)canvas)->
        Handle(ProcessEventArg(fc, arg.start, arg.approx));


    
}
void OffscreenFrame::Handle(Core::DeinitializeEventArg arg) {}

void OffscreenFrame::SetCanvas(ICanvas* c) {
    canvas = c;
}
ICanvas* OffscreenFrame::GetCanvas() {
    return canvas;
}


}
}
