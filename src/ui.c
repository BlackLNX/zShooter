#define MAX_OPTIONS 24

struct {
    char* command;
    char* name;
    int moveto;
} user_options[MAX_OPTIONS] = {0};


//CLEAR SCREEN:
void clear() {
    system(_CLEAR);
}


// SHOW TEXT SLOWLY:
void prints(char* text) {
    printf(text);
}


// SHOWING USER-ACTIONS AND HANDLE:
void user_prompt() {
    
}


// ADDING A USER-OPTION:
int user_option(char** command, char** name, int* moveto) {
    for (int i=0; i<MAX_OPTIONS; i++) {
        if (user_options[i].command == 0) {                         //FOUND UNSET OPTION:
            user_options[i].command = *command;                     //SET OPTION
            user_options[i].name = *name;
            user_options[i].moveto = *moveto;
            if (++i < MAX_OPTIONS) user_options[i].command = 0;     //UNSET NEXT OPTION
            return TRUE;                                            //RETURN SUCCESS
        }
    }
    return FALSE;                                                   //RETURN FAILURE
}
