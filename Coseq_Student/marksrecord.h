#ifndef MARKSRECORD_H
#define MARKSRECORD_H

#include "fstream"

class MarksRecord
{
    char usn[15];
public:
    MarksRecord();
    friend class BufferMarks;
    MarksRecord(std::string);
};

class BufferMarks
{
    char buff[500];
public:
    BufferMarks();
    void pack(MarksRecord &);
    void unpack(MarksRecord &);
    void read(std::fstream &);
    int write(std::string);
    int add(MarksRecord &);
};

#endif // MARKSRECORD_H
