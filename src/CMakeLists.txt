project(app)

file(GLOB_RECURSE PROJECT_SOURCES 
    app/*.cpp 
    core/*.cpp)
    
file(GLOB_RECURSE PROJECT_HEADERS 
    app/*.h 
    core/*.h)

add_executable(app ${PROJECT_SOURCES} ${PROJECT_HEADERS})
