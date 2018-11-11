file(GLOB_RECURSE SQUIRREL_SOURCES "src/*.cpp" "include/*.h")

add_library(squirrel STATIC ${SQUIRREL_SOURCES})

include_directories(SYSTEM "${CMAKE_CURRENT_SOURCE_DIR}/../include" "${CMAKE_CURRENT_SOURCE_DIR}/include")


target_include_directories(squirrel SYSTEM PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../include")

install(TARGETS squirrel RUNTIME DESTINATION "${CMAKE_SOURCE_DIR}/bin"
                         LIBRARY DESTINATION "${CMAKE_SOURCE_DIR}/lib"
                         ARCHIVE DESTINATION "${CMAKE_SOURCE_DIR}/lib")
						 