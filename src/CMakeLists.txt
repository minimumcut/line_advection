project(app)

file(GLOB_RECURSE PROJECT_SOURCES 
    app/*.cpp 
    core/*.cpp)
    
file(GLOB_RECURSE PROJECT_HEADERS 
    app/*.h 
    core/*.h)

include_directories("./")

add_executable(app ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_link_libraries(app Qt5::Widgets)
target_link_libraries(app Qt5::Core)
