file(GLOB_RECURSE SQUIRREL_STDLIB_SOURCES "src/*.cpp")

add_library(sqstdlib STATIC ${SQUIRREL_STDLIB_SOURCES})

include_directories(SYSTEM "${CMAKE_CURRENT_SOURCE_DIR}/../include" "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(sqstdlib squirrel)

install(TARGETS sqstdlib RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/bin"
                         LIBRARY DESTINATION "${CMAKE_SOURCE_DIR}/lib"
                         ARCHIVE DESTINATION "${CMAKE_SOURCE_DIR}/lib")
						 
