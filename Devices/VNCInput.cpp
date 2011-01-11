#include "VNCInput.h"

#include <Display/VNCEnvironment.h>

namespace OpenEngine {
namespace Devices {

VNCInput::VNCInput(Display::VNCEnvironment *env) {

}

IEvent<KeyboardEventArg>& VNCInput::KeyEvent() {
    return keyEvent;
}

IEvent<MouseButtonEventArg>& VNCInput::MouseButtonEvent() {
    return mouseButtonEvent;
}
IEvent<MouseMovedEventArg>& VNCInput::MouseMovedEvent() {
    return mouseMovedEvent;
}
void VNCInput::HideCursor() {}
    
void VNCInput::ShowCursor() {}

void VNCInput::SetCursor(int x, int y) {}

MouseState VNCInput::GetState() {
    return state;
}


}
}

