#include <iostream>
#include <raylib.h>

using namespace std;
const int screenWidth = 850;
const int screenHeight = 800;
const int TUBE_WIDTH = 105;
const int TUBE_HEIGHT = 200;
const int TUBE_SPACING = 20;
const int TUBE_COLUMNS = 6;
const int TUBE_ROWS = 2;
void generate(){
    int tubes_number = 8;
    cout << tubes_number ;

     int row = 2 / TUBE_COLUMNS;
    int col = 1 % TUBE_COLUMNS;
    int x = col * (TUBE_WIDTH + TUBE_SPACING);
     int y = row * (TUBE_HEIGHT + TUBE_SPACING);
    DrawRectangle(x, y + 5 * (TUBE_HEIGHT / 4), TUBE_WIDTH, TUBE_HEIGHT/4,WHITE);
   
}

int main () {
    // int ball_x = 100;
    // int ball_y = 100;
    // int ball_speed_x = 5;
    // int ball_speed_y = 5;
    // int ball_radius = 15;

    cout << "Hello World" << endl;

    InitWindow(screenWidth, screenHeight, "WATER COLOUR SORT");
    SetTargetFPS(60);

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);
        for (int i = 0; i < 5;i++)
        {
    int row = i / TUBE_COLUMNS;
    int col = (i+1) % TUBE_COLUMNS;
    int x = col * (TUBE_WIDTH + TUBE_SPACING);
     int y = row * (TUBE_HEIGHT + TUBE_SPACING);
   //  for (int j = 5; j < 30; j=j+5)
   //  {
         DrawRectangle(x, y + 4 * (TUBE_HEIGHT / 4), TUBE_WIDTH, TUBE_HEIGHT / 4,WHITE);
    // }
    
        }
        
       // generate();

           
        
      
        // ball_x += ball_speed_x;
        // ball_y += ball_speed_y;

        // if(ball_x + ball_radius >= screenWidth  || ball_x - ball_radius <= 0)
        // {
        //     ball_speed_x *= -1;
        // }

        // if(ball_y + ball_radius >= screenHeight  || ball_y - ball_radius <= 0)
        // {
        //     ball_speed_y *= -1;
        // }

      //  DrawCircle(ball_x,ball_y,ball_radius, WHITE);
        EndDrawing();
 }

    CloseWindow();
    return 0;
}
// #include <raylib.h>
// #include <vector>
// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// const int WIDTH = 500;
// const int HEIGHT = 550;
// const int TUBE_WIDTH = 65;
// const int TUBE_HEIGHT = 200;
// const int TUBE_SPACING = 10;
// const int TUBE_COLUMNS = 5;
// const int TUBE_ROWS = 2;
// Color SELECTED_COLOR = GREEN;

// struct Tube {
//     std::vector<Color*> colors;
// };


// std::vector<Tube> tubes;
// Color GetRandomColor() {
//     return Color{ static_cast<unsigned char>(rand() % 256),
//                   static_cast<unsigned char>(rand() % 256),
//                   static_cast<unsigned char>(rand() % 256), 255 };
// }
// void GenerateStart() {
//     std::vector<Color> availableColors;

//     for (int i = 0; i < TUBE_COLUMNS * TUBE_ROWS; ++i) {
//         Tube tube;
//         tubes.push_back(tube);

//         if (i < TUBE_COLUMNS * (TUBE_ROWS - 1)) {
//             for (int j = 0; j < 4; ++j) {
//                 availableColors.push_back(GetRandomColor());
//             }
//         }
//     }

//     for (auto& tube : tubes) {
//         for (int j = 0; j < 4; ++j) {
//             int index = -1;
// if (!availableColors.empty()) {
//     index = rand() % availableColors.size();
// }
//             tube.colors.push_back(&availableColors[index]);
//             availableColors.erase(availableColors.begin() + index);
//         }
//     }
// }

// void DrawTubes(int selectedTube) {
//     for (int i = 0; i < tubes.size(); ++i) {
//         int row = i / TUBE_COLUMNS;
//         int col = i % TUBE_COLUMNS;
//         int x = col * (TUBE_WIDTH + TUBE_SPACING);
//         int y = row * (TUBE_HEIGHT + TUBE_SPACING);

//         for (int j = 0; j < tubes[i].colors.size(); ++j) {
//             if (tubes[i].colors[j] != nullptr) {
//                 DrawRectangle(x, y + j * (TUBE_HEIGHT / 4), TUBE_WIDTH, TUBE_HEIGHT / 4, *tubes[i].colors[j]);
//             } else {
//                 // Handle the case where the pointer is nullptr
//                 // You might want to draw an empty rectangle or handle it differently
//                 DrawRectangle(x, y + j * (TUBE_HEIGHT / 4), TUBE_WIDTH, TUBE_HEIGHT / 4, BLACK);
//             }
//         }

//         DrawRectangleLines(x, y, TUBE_WIDTH, TUBE_HEIGHT, (i == selectedTube) ? SELECTED_COLOR : BLACK);
//     }
// }



// // bool CheckVictory() {
// //     for (const auto& tube : tubes) {
// //         if (tube.colors.size() != 4) {
// //             return false;
// //         }

// //         Color mainColor = *tube.colors[3];
// //         for (const auto& color : tube.colors) {
// //             if (*color != mainColor) {
// //                 return false;
// //             }
// //         }
// //     }

// //     return true;
// // }
// bool CheckVictory() {
//     for (const auto& tube : tubes) {
//         if (tube.colors.size() != 4) {
//             return false;
//         }

//         Color* mainColor = tube.colors[3];
//         for (const auto& color : tube.colors) {
//             if (color != mainColor) {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// // void MoveColors(int sourceTube, int destTube) {
// //     if (sourceTube == destTube || tubes[sourceTube].colors.empty()) {
// //         return;
// //     }

// //     Color* sourceColor = tubes[sourceTube].colors.back();
// //     Color* destColor = (tubes[destTube].colors.empty()) ? nullptr : tubes[destTube].colors.back();

// //     if (sourceColor == destColor || tubes[destTube].colors.size() < 4) {
// //         tubes[sourceTube].colors.pop_back();
// //         tubes[destTube].colors.push_back(sourceColor);
// //     }
// // }
// void MoveColors(int sourceTube, int destTube) {
//     if (sourceTube == destTube || tubes[sourceTube].colors.empty()) {
//         return;
//     }

//     Color* sourceColor = tubes[sourceTube].colors.back();
//     Color* destColor = (tubes[destTube].colors.empty()) ? nullptr : tubes[destTube].colors.back();

//     if (sourceColor == destColor || tubes[destTube].colors.size() < 4) {
//         tubes[sourceTube].colors.pop_back();
//         tubes[destTube].colors.push_back(sourceColor);
//     }
// }

// int main() {
//     int selectedTube = -1;
//     bool newGame = true;
//     bool victory = false;
//       srand(static_cast<unsigned>(time(nullptr)));

//     InitWindow(WIDTH, HEIGHT, "Water Sort Raylib");
//     SetTargetFPS(60);

//     while (!WindowShouldClose()) {
//         if (newGame) {
//             tubes.clear();
//             GenerateStart();
//             newGame = false;
//             victory = false;
//         }

//         BeginDrawing();
//         ClearBackground(RAYWHITE);

//         if (!victory) {
//             DrawTubes(selectedTube);
//         } else {
//             DrawText("You Won! Press Enter for a new board!", 30, 265, 24, BLACK);
//         }

//         DrawText("Stuck? Space-Restart, Enter-New Board!", 10, 10, 24, BLACK);

//         EndDrawing();

//         if (IsKeyPressed(KEY_SPACE)) {
//             newGame = true;
//         }

//         if (IsKeyPressed(KEY_ENTER)) {
//             newGame = true;
//         }

//         if (!victory && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//             int mouseX = GetMouseX();
//             int mouseY = GetMouseY();

//             for (int i = 0; i < tubes.size(); ++i) {
//                 int row = i / TUBE_COLUMNS;
//                 int col = i % TUBE_COLUMNS;
//                 int x = col * (TUBE_WIDTH + TUBE_SPACING);
//                 int y = row * (TUBE_HEIGHT + TUBE_SPACING);

//                 Rectangle tubeRect = { static_cast<float>(x), static_cast<float>(y), static_cast<float>(TUBE_WIDTH), static_cast<float>(TUBE_HEIGHT) };
//                 if (CheckCollisionPointRec({ static_cast<float>(mouseX), static_cast<float>(mouseY) }, tubeRect)) {
//                     if (selectedTube == -1) {
//                         selectedTube = i;
//                     } else {
//                         MoveColors(selectedTube, i);
//                         selectedTube = -1;
//                     }
//                 }
//             }

//             victory = CheckVictory();
//         }
//     }

//     CloseWindow();

//     return 0;
// }



