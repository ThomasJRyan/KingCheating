# Script for cheating in the game 'The one who pulls out the sword will be crowned king'
# Start the script, you'll have three seconds to line up your cursor in the game
# Press Left Shift to stop the script at any time (this will let of of left mouse)

import time

import win32api
import win32con

SMOOTHING = 100
X_MOVEMENT = 1

if __name__ == '__main__':

    # Nice little message to know when it starts
    print('Cheating begins in...')
    for i in range(3):
        print(f'{3 - i}!')
        time.sleep(1)
    print('GO!')

    # Get the state of Left Shift
    lshift = win32api.GetKeyState(win32con.VK_LSHIFT )

    # Hold down left mouse
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN, 0, 0)

    # Init variables
    count = 0
    s_count = 0

    while True:
        # If Left Shift pressed, break the loop
        if lshift != win32api.GetKeyState(win32con.VK_LSHIFT ):
            break
        win32api.mouse_event(win32con.MOUSEEVENTF_MOVE, 0, -1, 0, 0)

        # Allow smooth left/right movement
        if s_count == SMOOTHING:
            win32api.mouse_event(win32con.MOUSEEVENTF_MOVE, X_MOVEMENT, -1, 0, 0)
            s_count = 0
            count += X_MOVEMENT
            # Invert x-axis
            X_MOVEMENT *= -1 if (count <= 0 or count >= 50) else 1

        # Increment our count and s_count
        s_count += 1

    # Release left mouse   
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP, 0, 0)
