add_custom_target(Messaging_HEADERS SOURCES
    IMessage.hpp
    Message.hpp
    Scheduler.hpp
)

add_library(Messaging INTERFACE)
add_dependencies(Messaging ${LIBRARY_NAME}_HEADERS)
target_include_directories(Messaging INTERFACE .)
