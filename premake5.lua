workspace "Tic Tac Toe"
    configurations { "Debug", "Release" }

project "tictactoe"
    kind "WindowedApp"
    language "C++"

    files { "src/*.cpp", "src/*.hpp" }
    links { "SDL2" }
    removefiles { "src/Texture.cpp", "src/Texture.hpp"}

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
