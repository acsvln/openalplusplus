cmake_minimum_required(VERSION 3.5.1)

project(openalpp)

if(UNIX)
  set(HEADERDIRS /usr/include /usr/local/include)
# else(UNIX)
#   set(HEADERDIRS C:\\)
endif(UNIX)

set(INCLUDEDIRS ./include)

if(UNIX)
  find_program(CCGNU_CONFIG ccgnu2-config)
  if(CCGNU_CONFIG)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-I`${CCGNU_CONFIG} --includes`")
    set(CCGNU_FOUND 1)
  endif(CCGNU_CONFIG)
else(UNIX)
  set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
endif(UNIX)

if(CCGNU_FOUND)
  find_path(PORTAUDIO_INCLUDE portaudio.h ${HEADERDIRS})
  if(PORTAUDIO_INCLUDE)
    set(INCLUDEDIRS ${INCLUDEDIRS} ${PORTAUDIO_INCLUDE})
    set(PORTAUDIO_FOUND 1)
  endif(PORTAUDIO_INCLUDE)

  find_path(VORBIS_INCLUDE vorbis/vorbisfile.h ${HEADERDIRS})
  if(VORBIS_INCLUDE)
    set(INCLUDEDIRS ${INCLUDEDIRS} ${VORBIS_INCLUDE})
    set(VORBIS_FOUND 1)
  endif(VORBIS_INCLUDE)
endif(CCGNU_FOUND)

include_directories(${INCLUDEDIRS})

if(UNIX)
  set(LIBDIRS /usr/lib /usr/local/lib)
# else(UNIX)
#   set(LIBDIRS C:\)
endif(UNIX)
link_directories(${LIBDIRS})

# subdirs(src tests)
subdirs(src)
