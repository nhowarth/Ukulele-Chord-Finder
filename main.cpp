#include <iostream>
#include "ukulele.h"

int main(){
    Ukulele uke;
    char notes[4] = {G_NOTE, C_NOTE, E_NOTE, A_NOTE};
    Chord C_major("C", "maj", notes);
    uke.current_chord = &C_major;
    uke.drawFretBoard();

    return 0;
}
