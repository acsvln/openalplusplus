set(SOURCEFILES audiobase audioconvert audioenvironment error groupsource listener sample sounddata source sourcebase referenced)

if(CCGNU_FOUND)
  
  set(SOURCEFILES ${SOURCEFILES} stream netstream streamupdater netupdater)

  if(PORTAUDIO_FOUND)
    set(SOURCEFILES ${SOURCEFILES} inputdevice deviceupdater)
  else(PORTAUDIO_FOUND)
    set(SOURCEFILES ${SOURCEFILES} noinputdevice)
  endif(PORTAUDIO_FOUND)

  if(VORBIS_FOUND)
    set(SOURCEFILES ${SOURCEFILES} filestream filestreamupdater)
  else(VORBIS_FOUND)
    set(SOURCEFILES ${SOURCEFILES} nofilestream)
  endif(VORBIS_FOUND)

else(CCGNU_FOUND)
  set(SOURCEFILES ${SOURCEFILES} nostreaming noinputdevice nofilestream)
endif(CCGNU_FOUND)

add_library(openalpp ${SOURCEFILES})