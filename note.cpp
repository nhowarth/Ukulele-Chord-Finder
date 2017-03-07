#include "note.h"
/* 
const char *note_names[12] = {"C", "Db", "D", "Eb", "E", "F",
                              "Gb", "G", "Ab", "A", "Bb", "B"};
*/

/*
  Constructor - used to initialize note properties at instantiation
*/
Note::Note(const char* _name, char _index, char _octave){
    strcpy(name, _name);
    index = _index;
    octave = _octave;
}

/*
  defineNote - used to set note properties after instantiation
*/
void Note::defineNote(const char* _name, char _index, char _octave){
    strcpy(name, _name);
    index = _index;
    octave = _octave;
}
