
# Create the extension library
ADD_LIBRARY(Extensions_VNCServer
  Display/VNCServer.h
  Display/VNCServer.cpp
)

TARGET_LINK_LIBRARIES(Extensions_VNCServer
  ${LIBVNCSERVER_LIBRARIES}
)