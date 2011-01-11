#include "VNCServer.h"

namespace OpenEngine {
namespace Display {

    VNCServer::VNCServer() {}

    void VNCServer::StartServer(int w, int h) {

        buffer = (char*)malloc(sizeof(char)*w*h*4);

        server = rfbGetScreen(0,NULL,w,h,8,3,4);
        server->frameBuffer=buffer;

        rfbInitServer(server);
    }

    char* VNCServer::GetBuffer() {
        return buffer;
    }
    
    void VNCServer::MarkDirty(int x, int y, int w, int h) {
        if (rfbIsActive(server)) {
            rfbMarkRectAsModified(server,x,y,w,h);
            usec = server->deferUpdateTime*1000;
            rfbProcessEvents(server,usec);
        }

    }

    void VNCServer::Post() {
        if (rfbIsActive(server)) {
            //ITexture2DPtr tex = canvas->GetTexture();
            //glReadPixels(0,0,tex->GetWidth(),tex->GetHeight(),GL_RGBA,GL_BYTE,buffer);

            // rfbMarkRectAsModified(server,0,0,tex->GetWidth(),tex->GetHeight());
            // usec = server->deferUpdateTime*1000;
            // rfbProcessEvents(server,usec);
        }
    }


}
}
