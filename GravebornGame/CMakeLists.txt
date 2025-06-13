add_executable(${GRAVEBORN_GAME_TARGET_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp
)

target_include_directories(${GRAVEBORN_GAME_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${GRAVEBORN_GAME_TARGET_NAME} PUBLIC ${GRAVEBORN_ENGINE_TARGET_NAME})

function(CopyLibDirToTarget LIB_NAME TARGET_NAME)
    add_custom_command(
    TARGET ${TARGET_NAME}
    POST_BUILD
    COMMAND
    ${CMAKE_COMMAND} -E copy_directory
    $<TARGET_FILE_DIR:${LIB_NAME}>
    $<TARGET_FILE_DIR:${TARGET_NAME}>
    )
endfunction()

CopyLibDirToTarget(${GRAVEBORN_ENGINE_TARGET_NAME} ${GRAVEBORN_GAME_TARGET_NAME})