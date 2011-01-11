
# Create the extension library
ADD_LIBRARY(Extensions_VNCServer
  Display/OffscreenFrame.h
  Display/OffscreenFrame.cpp
#  Display/VNCFrame.cpp
  Display/VNCServer.h
  Display/VNCServer.cpp
  Devices/VNCInput.h
  Devices/VNCInput.cpp
  Display/VNCEnvironment.h
  Display/VNCEnvironment.cpp
)

TARGET_LINK_LIBRARIES(Extensions_VNCServer
  ${LIBVNCSERVER_LIBRARIES}
)