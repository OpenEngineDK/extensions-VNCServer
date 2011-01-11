// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------

#ifndef _OE_VNC_ENVIRONMENT_H_
#define _OE_VNC_ENVIRONMENT_H_

#include <Display/IEnvironment.h>

#include <Display/OffscreenFrame.h>
#include <Display/VNCServer.h>
#include <Devices/VNCInput.h>

namespace OpenEngine {
namespace Display {

/**
 * Short description.
 *
 * @class VNCEnvironment VNCEnvironment.h ons/VNCServer/Display/VNCEnvironment.h
 */
class VNCEnvironment : public IEnvironment {
private:
    int width;
    int height;
    VNCServer* server;
    Devices::VNCInput* input;
    OffscreenFrame* frame;
public:
    VNCEnvironment(int w, int h);
    IFrame& CreateFrame();
    Devices::IMouse* GetMouse();
    Devices::IKeyboard* GetKeyboard();
    Devices::IJoystick* GetJoystick();
    void Handle(Core::InitializeEventArg arg);
    void Handle(Core::DeinitializeEventArg arg);
    void Handle(Core::ProcessEventArg arg);

    VNCServer* GetServer();
};
} // NS Display
} // NS OpenEngine

#endif
