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
configure_file(
    ${PROJECT_SOURCE_DIR}/init.mac 
    ${PROJECT_BINARY_DIR}/init.mac 
    COPYONLY
)

configure_file(
    ${PROJECT_SOURCE_DIR}/gps.mac 
    ${PROJECT_BINARY_DIR}/gps.mac 
    COPYONLY
)
# with no vis and mac, this file can stop here.
