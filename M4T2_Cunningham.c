/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;
    int tileWidth = 80;
    int tileHeight = 80;

    InitWindow(screenWidth, screenHeight, "M4T2 - ChessBoard");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKBLUE);
            //test: Draw one tile
            //DrawRectangle(0, 0, tileWidth, tileHeight, RAYWHITE);
            
            
            int line_num = 0;
            Color first, second;
            for(int h=0; h < screenHeight; h += tileHeight){
                //alternate odd and even lines
                if (line_num % 2 == 0){
                      first = RAYWHITE;
                      second = DARKBLUE; 
                }
                else {
                    first = DARKBLUE;
                    second = RAYWHITE;
                }
                //DRAW ROW
                for (int w = 0; w < screenWidth; w += 2*tileWidth){
                        DrawRectangle(w, h, tileWidth, tileHeight, first);             //first color
                        DrawRectangle(w + tileWidth, h, tileWidth, tileHeight, second); //second goes in between
                } //END ROW
                line_num++;
            } // end of screen

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}