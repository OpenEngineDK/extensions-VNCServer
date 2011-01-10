// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------


#ifndef _OE_V_N_C_SERVER_H_
#define _OE_V_N_C_SERVER_H_

#include <Core/IListener.h>
#include <Core/EngineEvents.h>
#include <Display/ICanvas.h>
#include <Meta/OpenGL.h>
#include <Logging/Logger.h>


#include <arpa/inet.h>
#include <rfb/rfb.h>
#include <fstream>

namespace OpenEngine {
namespace Display {

    using namespace Core;
    using namespace std;

class VNCServer : public IListener<Core::ProcessEventArg>
                , public IListener<Core::InitializeEventArg> {
    ICanvas* canvas;
    char *buffer;
    rfbScreenInfoPtr server;
    long usec;
public:
    VNCServer(ICanvas* c) : canvas(c) {}
    void Handle(Core::InitializeEventArg arg) {
        ITexture2DPtr tex = canvas->GetTexture();

        buffer = (char*)malloc(sizeof(char)*tex->GetWidth()*tex->GetHeight()*4);
        
        server = rfbGetScreen(0,NULL,tex->GetWidth(),tex->GetHeight(),8,3,4);
        server->frameBuffer=buffer;
        
        rfbInitServer(server);           
                

    }
    void Handle(Core::ProcessEventArg arg) {
        if (rfbIsActive(server)) {
            ITexture2DPtr tex = canvas->GetTexture();
            glReadPixels(0,0,tex->GetWidth(),tex->GetHeight(),GL_RGBA,GL_BYTE,buffer);
            
            // rfbMarkRectAsModified(server,0,0,tex->GetWidth(),tex->GetHeight());
            // usec = server->deferUpdateTime*1000;    
            // rfbProcessEvents(server,usec);
        }  
    }
};


} // NS Display
} // NS OpenEngine

#endif // _OE_V_N_C_SERVER_H_
