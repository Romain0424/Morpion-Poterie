cmake_minimum_required(VERSION 3.21)
project(ProjetCmakeMorpion C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetCmakeMorpion ../Dev/board.c
        ../Dev/board_view_text.c
        ../Dev/game.c
        ../Dev/main.c
        ../Dev/player_manager_mock.c
        ../Dev/tictactoe_erros.c
        )
set_target_properties(ProjetCmakeMorpion PROPERTIES COMPILE_OPTIONS "-DCONFIG_TEXTUI;-DCONFIG_PLAYER_MANAGER_MOCK")
