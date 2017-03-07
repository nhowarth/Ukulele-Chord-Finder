#include "chord.h"

/*
  Constructor - no parameters
*/
Chord::Chord(){
    hash_value = 0;
}

/*
  Constructor - with parameters
*/
Chord::Chord(const char* _root, const char* _mod, const char _notes[]){
    strcpy(root, _root);
    strcpy(modifier, _mod);

    notes[0] = _notes[0];
    notes[1] = _notes[1];
    notes[2] = _notes[2];
    notes[3] = _notes[3];

    hash_value = hashChord(notes);

    pNotes[0] = NULL;
    pNotes[1] = NULL;
    pNotes[2] = NULL;
    pNotes[3] = NULL;

    variant = 0;
}

/*
  defineChord - used to set chord properties after instantiation
*/
void Chord::defineChord(const char* _root, const char* _mod, const char _notes[]){
    strcpy(root, _root);
    strcpy(modifier, _mod);

    notes[0] = _notes[0];
    notes[1] = _notes[1];
    notes[2] = _notes[2];
    notes[3] = _notes[3];

    hash_value = hashChord(notes);

    pNotes[0] = NULL;
    pNotes[1] = NULL;
    pNotes[2] = NULL;
    pNotes[3] = NULL;

    variant = 0;
}

/*
  hashChord - returns const short that uniquely identifies a set of notes
  Bits 0 through 11 correspond to the presence of a note in the chord
  (1 = note present in chord): 
        15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0
         x  x  x  x  B Bb  A  Ab G  Gb F  E  Eb D  Db C
  Maximum hash value is 3840; 3840 * 34B (size of Chord) = 127kB
*/
const short Chord::hashChord(const char* _notes){
    short hash = 0;
    for (int i = 0; i < 4; i++){
        hash |= (1 << _notes[i]);
    }
    return hash;
}

