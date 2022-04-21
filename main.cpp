// Script for cheating in the game 'The one who pulls out the sword will be crowned king'
// Start the script, you'll have three seconds to line up your cursor in the game
// Press Left Shift to stop the script at any time (this will let of of left mouse)

#include <iostream>
#include <windows.h>
#include <Windows.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int SMOOTHING = 100;
    int X_MOVEMENT = 1;

    // Nice little message to know when it starts
    cout << "Cheating begins in..." << endl;
    for (int i = 3; i > 0; i--) {
        cout << i << "!" << endl;
        Sleep(1);
    }
    cout << "GO!" << endl;

    // Get the state of Left Shift
    int lshift = GetKeyState(VK_LSHIFT);

    // Hold down left mouse
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

    // Init variables
    int count = 0;
    int s_count = 0;
    int p_count = 0;

    while (true){
        // If Left Shift pressed, break the loop
        if (lshift != GetKeyState(VK_LSHIFT)){
            break;
        }
        mouse_event(MOUSEEVENTF_MOVE, 0, -1 - p_count, 0, 0);

        // Allow smooth left/right movement
        if (s_count == SMOOTHING){
            mouse_event(MOUSEEVENTF_MOVE, X_MOVEMENT, -1 - p_count, 0, 0);
            // Pull count, increment by 1
            p_count += 1;
            s_count = 0;
            count += X_MOVEMENT;
            // Invert x-axis
            if (count <= 0 || count >= 10)
                X_MOVEMENT *= -1;
        }

        // Increment our s_count
        s_count += 1;
    }
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    return 0;
}
