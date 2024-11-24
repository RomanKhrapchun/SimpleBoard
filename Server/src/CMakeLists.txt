add_subdirectory(resource)
add_subdirectory(util)
add_subdirectory(print)
add_subdirectory(test)
add_subdirectory(service)
add_subdirectory(main)

include_directories(
    ${CMAKE_SOURCE_DIR}/Server/include/main
    ${CMAKE_SOURCE_DIR}/Server/include/resource
    ${CMAKE_SOURCE_DIR}/Server/include/util
    # Інші шляхи до заголовків, якщо необхідно
)
