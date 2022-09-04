#ifndef MARKS_H
#define MARKS_H

#include "iostream"

class Marks
{
    char usn[20], subcode[20], subname[20], internalInd[1], marks[2];
public:
    Marks();
    Marks(std::string, std::string, std::string, std::string, std::string);
};

#endif // MARKS_H
