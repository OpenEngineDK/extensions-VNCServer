// 
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS)
//
// This program is free software; It is covered by the GNU General
// Public License version 2 or any later version.
// See the GNU General Public License for more details (see LICENSE).
//--------------------------------------------------------------------
#ifndef _OE_VNC_INPUT_H_
#define _OE_VNC_INPUT_H_

#include <Devices/IKeyboard.h>
#include <Devices/IMouse.h>
#include <Core/Event.h>

namespace OpenEngine {
namespace Display {
    class VNCEnvironment;
}
namespace Devices {

using namespace Core;

/**
 * Short description.
 *
 * @class VNCInput VNCInput.h ons/VNCServer/Display/VNCInput.h
 */
class VNCInput 
    : public Devices::IKeyboard
    , public Devices::IMouse {
private:

    Core::Event<KeyboardEventArg>       keyEvent;
    Core::Event<MouseMovedEventArg>     mouseMovedEvent;
    Core::Event<MouseButtonEventArg>    mouseButtonEvent;

    MouseState state;

public:
    VNCInput(Display::VNCEnvironment*);

    IEvent<KeyboardEventArg>& KeyEvent() ;

    IEvent<MouseButtonEventArg>& MouseButtonEvent() ;
    IEvent<MouseMovedEventArg>& MouseMovedEvent() ;
    void HideCursor() ;

    void ShowCursor() ;

    void SetCursor(int x, int y) ;

    MouseState GetState() ;


};
} // NS Devices
} // NS OpenEngine

#endif
