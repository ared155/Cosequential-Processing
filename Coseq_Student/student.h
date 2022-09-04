#ifndef STUDENT_H
#define STUDENT_H
#include "iostream"
#include "fstream"

class Student
{
    char usn[15], name[50], branch[50], status[1];
public:
    friend class Buffer;
    Student();
    Student(std::string, std::string, std::string, std::string);
};

class Buffer
{
    char buff[500];
public:
    Buffer();
    void pack(Student &);
    void unpack(Student &, int);
//    void unpack(int);
    void read(std::fstream &);
    int write(std::string);
    int add(Student &);
    char* getusn(Student &);
    char* getname(Student &);
    char* getbranch(Student &);
    char* getstatus(Student &);
};

#endif // STUDENT_H
