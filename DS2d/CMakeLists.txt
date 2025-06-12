add_executable(${DS2D_GAME_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
)

target_include_directories(${DS2D_GAME_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${DS2D_GAME_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${DS2D_GAME_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${DS2D_GAME_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${DS2D_GAME_TARGET_NAME} PUBLIC sfml-audio)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
    add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:${LIB_NAME}>
    $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibToTarget(sfml-graphics ${DS2D_GAME_TARGET_NAME})
CopyLibToTarget(sfml-window ${DS2D_GAME_TARGET_NAME})
CopyLibToTarget(sfml-system ${DS2D_GAME_TARGET_NAME})
CopyLibToTarget(sfml-audio ${DS2D_GAME_TARGET_NAME})