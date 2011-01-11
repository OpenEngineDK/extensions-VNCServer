#include "VNCEnvironment.h"
#include "VNCFrame.h"

namespace OpenEngine {
namespace Display {

    using namespace Devices;
    
    VNCEnvironment::VNCEnvironment(int w, int h) 
        : width(w)
        , height(h) {
        server = new VNCServer();
        input = new VNCInput(this);
        frame = new OffscreenFrame(w,h);
    }

    IFrame& VNCEnvironment::CreateFrame() {
        return *frame;
    }
    IMouse* VNCEnvironment::GetMouse() {
        return input;
    }

    IKeyboard* VNCEnvironment::GetKeyboard() {
        return input;
    }
    IJoystick* VNCEnvironment::GetJoystick() {
        return 0;
    }
    void VNCEnvironment::Handle(Core::InitializeEventArg arg) {
        server->StartServer(width,height);
        frame->Handle(arg);
        //input->Handle(arg);
    }
    void VNCEnvironment::Handle(Core::DeinitializeEventArg arg) {
        frame->Handle(arg);
        //input->Handle(arg);
    }
    void VNCEnvironment::Handle(Core::ProcessEventArg arg) {
        
        frame->Handle(arg);

        char* buffer = server->GetBuffer();    
        glReadPixels(0,0,width,height,GL_RGBA,GL_BYTE,buffer);    
        server->MarkDirty(0,0,width,height);
        //input->Handle(arg);
    }

    VNCServer* VNCEnvironment::GetServer() {
        return server;
    }
}
}
