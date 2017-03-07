#ifndef UKULELE_H
#define UKULELE_H

#include "note.h"
#include "chord.h"

#define MAX_FRET 15

class Ukulele {
    private:
        struct UkeString {
            char    name;
            Note    notes[MAX_FRET+1];
        } strings[4];
//        Chord *current_chord;

    public:
        Ukulele();
        void drawFretBoard();
//        void setChord(short base_chord);
        Chord *current_chord;
};

//void    buildChords();

#endif
