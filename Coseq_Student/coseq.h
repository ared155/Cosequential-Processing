#ifndef COSEQ_H
#define COSEQ_H
#include "student.h"

class coseq
{
    char usn[15], name[50], branch[50];
    int norS, norM;
public:
    coseq();
    void match();
    void returnObj(Student[]);
};

#endif // COSEQ_H
