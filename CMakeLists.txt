# fundemetal set of project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(G4BasicFrame)

#Set Option for ui vis on or off
option(WITH_GEANT4_UIVIS "Build project with UI and VIS drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

# include setup
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

# set location of include and source file
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# add executable
add_executable(G4BasicFrame main.cc ${sources} ${headers})
target_link_libraries(G4BasicFrame ${Geant4_LIBRARIES})

# copy the macro command to executable dir
set(G4TRY_SCRIPTS
  init.mac
  gps.mac
  )

foreach(_script ${G4TRY_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()
# with no vis and mac, this file can stop here.
