#pragma once    // Compile this header file only once

#ifndef NOTE_H
#define NOTE_H

#include <string.h>

#define C_NOTE   0
//#define C#_NOTE  1
#define Db_NOTE  1
#define D_NOTE   2
//#define D#_NOTE  3
#define Eb_NOTE  3
#define E_NOTE   4
#define F_NOTE   5
//#define F#_NOTE  6
#define Gb_NOTE  6
#define G_NOTE   7
//#define G#_NOTE  8
#define Ab_NOTE  8
#define A_NOTE   9
//#define A#_NOTE  10
#define Bb_NOTE  10
#define B_NOTE   11


static const char *note_names[12] = {"C", "Db", "D", "Eb", "E", "F",
                                     "Gb", "G", "Ab", "A", "Bb", "B"};
//extern const char *note_names[12];

class Note {
    friend class Ukulele;   // Allow Ukulele class to define notes

    private:
        char    index;      // 0-11, corresponding to note names defined above
        char    octave;     // 3-6
        char    name[3];    // name of note, defined in note_names
//        file*   midifile;
    public:
        Note() {}
        Note(const char* _name, char _index, char _octave);
        void defineNote(const char* _name, char _index, char _octave);
//        void playNote(file* midifile);
};

#endif
