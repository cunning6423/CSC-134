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
#include <stdlib.h>

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
    typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    GameScreen currentScreen = LOGO;

    // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0;          // Useful to count frames

    SetTargetFPS(60);               // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------
                        
    int player_x = 50;
    int player_y = 50;
    int speed_x  = 0;
    int speed_y  = 0;
    int base_speed = 5;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!

                framesCounter++;    // Count frames

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    currentScreen = TITLE;
                }
            } break;
            case TITLE:
            {
                // TODO: Update TITLE screen variables here!

                // Press enter to change to GAMEPLAY screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;
            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = ENDING;
                }
            } break;
            case ENDING:
            {
                // TODO: Update ENDING screen variables here!

                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = TITLE;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            switch(currentScreen)
            {
                case LOGO:
                {
                    // TODO: Draw LOGO screen here!
                    DrawText("SNAKE TITLE SCREEN", 20, 20, 40, GOLD);
                    DrawText("WAIT for 2 SECONDS...", 290, 220, 20, DARKGRAY);

                } break;
                case TITLE:
                {
                    // TODO: Draw TITLE screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLACK);
                    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                    DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);

                } break;
                case GAMEPLAY:
                {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, SKYBLUE);
                    DrawText("SNAKE GAMEPLAY SCREEN", 20, 20, 40, MAROON);
                    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
                    
                    //Draw player here
 5;
                    
                    if (IsKeyDown(KEY_LEFT)){
                        speed_x = -base_speed;
                        speed_y = 0;
                        
                    }
                    if (IsKeyDown(KEY_UP)){
                        speed_y = -base_speed;
                        speed_x = 0;
                    }
                    if (IsKeyDown(KEY_RIGHT)){
                        speed_x = base_speed;
                        speed_y = 0;
                    }
                    if (IsKeyDown(KEY_DOWN)){
                        speed_y = base_speed;
                        speed_x = 0;
                    }
                    // inertia
                    player_x = player_x + speed_x;
                    player_y = player_y + speed_y;
                    //Wrap around
                    if (player_x > screenWidth){
                        player_x = 0;    
                    }
                    if (player_x < 0){
                        player_x = screenWidth;    
                    }
                    if (player_y > screenHeight){
                        player_y = 0;    
                    }
                    if (player_y < 0 ){
                        player_y = screenHeight;    
                    }
                    // The Fruit
                    int fruit_x = 300;
                    int fruit_y = 300;
                    DrawCircleGradient(fruit_x, fruit_y, 25, PINK, MAROON);
                    DrawCircle(fruit_x - 10, fruit_y-10, 6, GREEN);
                    DrawCircle(fruit_x - 10, fruit_y-10, 2, DARKGREEN);
                    
                    // The Snake we control
                    DrawCircle(player_x,player_y,24, BLUE);
                    DrawCircle(player_x - 10, player_y, 2, BLACK);
                    DrawCircle(player_x + 10, player_y, 2, BLACK);
                    DrawRectangle(player_x - 10, player_y + 10, 20,2, BLACK);
                    // Did we get the fruit? within 10 pixels
                    if(abs(player_x - fruit_x)< 10) {
                        if(abs(player_y - fruit_y)< 10) {
                            player_x = 10;
                            player_y = 10;
                            currentScreen = ENDING;
                        }
                    }

                } break;
                case ENDING:
                {
                    // TODO: Draw ENDING screen here!
                    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                    DrawText("YOU LOST", 20, 20, 40, DARKBLUE);
                    DrawText("Score: 0", 20, 60, 40, DARKBLUE);
                    DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                } break;
                default: break;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}