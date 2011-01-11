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


// #include <arpa/inet.h>
#include <rfb/rfb.h>

namespace OpenEngine {
namespace Display {

    using namespace Core;
    using namespace std;

class VNCServer {
    char *buffer;
    rfbScreenInfoPtr server;
    long usec;
public:
    VNCServer();
    void StartServer(int w, int h);
    void Post();
    char* GetBuffer();
    void MarkDirty(int x, int y, int w, int h);
};


} // NS Display
} // NS OpenEngine

#endif // _OE_V_N_C_SERVER_H_
