#pragma once    // Compile this header file only once

#ifndef CHORD_H
#define CHORD_H

#include "note.h"

#define CHORD_M         0
#define CHORD_m         1
#define CHORD_7         2
#define CHORD_m7        3
#define CHORD_sus4      4
#define CHORD_7sus4     5
#define CHORD_dim       6
#define CHORD_dim7      7
#define CHORD_M7        8
#define CHORD_m7M       9
#define CHORD_7b5       10
#define CHORD_m7b5      11
#define CHORD_aug       12
#define CHORD_aug7      13
#define CHORD_add9      14
#define CHORD_madd9     15
#define CHORD_sus2      16
#define CHORD_7sus2     17
#define CHORD_M7aug5    18
#define CHORD_5         19
#define CHORD_6         20
#define CHORD_m6        21
#define CHORD_9         22
#define CHORD_M9        23
#define CHORD_m9        24
#define CHORD_69        25
#define CHORD_7b9       26
#define CHORD_7aug9     27
#define CHORD_11        28
#define CHORD_13        29

// Chord "modifier" names - correspond to index values defined above
static const char *chord_mods[30] = {"", "m", "7", "m7", "sus4", "7sus4",
                    "dim", "dim7", "M7", "m7M", "7b5", "m7b5", "aug", "aug7",
                    "add9", "madd9", "sus2", "7sus2", "M7aug5", "5", "6", "m6",
                    "9", "M9", "m9", "69", "7b9", "7aug9", "11", "13"};

class Chord {
    friend class Ukulele;

    private:
        char  notes[4];         // note index values that make up chord
        short hash_value;       // unique value that corresponds to set of notes
        char  root[3];          // chord root name (e.g., C, A#, Bb, ...)
        char  modifier[7];      // chord modifier (e.g., m7, dim, sus4, ...)
        Note *pNotes[4];        // pointer to Note objects in Ukulele class
        short variant;          // keeps track of chord variants
        
    public:
        Chord();
        Chord(const char* _root, const char* _mod, const char* _notes);
        void defineChord(const char* _root, const char* _mod, const char* _notes);
        const short hashChord(const char* notes);
};

#endif
