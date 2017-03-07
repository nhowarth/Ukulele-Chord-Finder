#include <iostream>
#include "ukulele.h"

/*
  Constructor - initialize notes on fretboard
*/
Ukulele::Ukulele(){
    current_chord = NULL;

    // Set ukulele string names
    strings[0].name = 'G';
    strings[1].name = 'C';
    strings[2].name = 'E';
    strings[3].name = 'A';

    char    initNote[4] = {G_NOTE, C_NOTE, E_NOTE, A_NOTE};
    char    initOctave[4] = {3, 3, 4, 4};
    char    thisString;
    char    thisFret;
    char    thisNote;
    char    thisOctave;

    // Cycle through strings and define notes on each
    for (thisString = 0, thisNote = initNote[thisString], 
            thisOctave = initOctave[thisString]; thisString < 4; 
            thisString++, thisNote = initNote[thisString], 
            thisOctave = initOctave[thisString]){
        for (thisFret = 0; thisFret <= MAX_FRET; 
                thisFret++, thisNote = (thisNote + 1) % 12){
            // Increment octave when C note is seen
            if (thisNote == C_NOTE){
                thisOctave++;
            }
            // Assign note to fret
            strings[thisString].notes[thisFret].defineNote(note_names[thisNote], thisNote, thisOctave);
        }
    }

/*
    // Define notes on G string
    {
        char thisFret = 0;
        char thisNote = G_NOTE;
        char thisOctave = 3;
        for (thisFret, thisNote; thisFret <= MAX_FRET; 
            thisFret++, thisNote = (thisNote + 1) % 12){
            // Increment octave when C note is seen
            if (thisNote == C_NOTE){
                thisOctave++;
            }
            // Assign note to fret
            strings[0].notes[thisFret].defineNote(note_names[thisNote], thisNote, thisOctave);
        }
    }
*/
}

/*
  drawFretBoard - used to print representation of ukulele fretboard on console
  This function will eventually take arguments to print one of the following: 
        1)  Chord diagram for current_chord (member of Ukulele class)
        2)  Notes on fretboard
        3)  Notes in specified scale
*/
void Ukulele::drawFretBoard(){
    // Draw each "string" from A down to G
    // Use 'X' to signify which fret should be pressed
    for (char string_num = 3; string_num >= 0; string_num--){
        std::cout << "[" << strings[string_num].name << "]|";
        for (char fret = 1; fret <= MAX_FRET; fret++){
/*            
            if (*chord_notes[string_num] == fret){
                std::cout << "-X-|";
            }
            else {
                std::cout << "---|";
            }
*/
            // Print name of note on each fret
            // Keep number of characters between each "|" consistent
            if (strlen(strings[string_num].notes[fret].name) == 1){
                std::cout << "-";
            }
            std::cout << "-" << strings[string_num].notes[fret].name << "-|";
        }
        std::cout << "--///" << std::endl;
    }

    // Mark fret numbers below strings
    for (unsigned int marker = 0; marker <= MAX_FRET; marker++){
        std::cout << " " << marker;
        if (marker >= 9){
            std::cout << "  ";
        }
        else {
            std::cout << "   ";
        }
    }
    std::cout << std::endl;
}

