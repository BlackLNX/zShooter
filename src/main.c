#include "main.h"

// MAIN LOOP
int main() {
    srand(time(NULL));
    clear();
    setup();
    //resize();
    welcome_screen();           // FIRST SCREEN THEME
    while (!quit) {
        //user_prompt();          // USER ACTION (INPUT)
        //resize();               // UPDATE CONSOLE SIZE
        //do_events();            // ENEMY ACTION (COMPUTE)
        //clear();                // CLEAR BUFFER
        //print_screen();         // CURRENT SCREEN (OUTPUT)
    }
    return 0;
}
