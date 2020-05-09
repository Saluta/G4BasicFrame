# fundemetal set of project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(G4Try)

#NEED NO VI AND UI UTILIZE
find_package(Geant4 REQUIRED)

# include setup
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

# set location of include and source file
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# add executable
add_executable(G4Try main.cc ${sources} ${headers})
target_link_libraries(G4Try ${Geant4_LIBRARIES})

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
