#include "coseq.h"
#include "fstream"
#include "iostream"
#include "string.h"
#include "student.h"

char l1[100][15],l2[100][15],l3[200][15], offset[100][5], offsetM[100][5];

coseq::coseq()
{
    ;
}

void coseq::match(){
    int count=0;
    Buffer b;
    Student stud;

    std::fstream f1("index.txt", std::ios::in);
    while(!f1.eof())
    {
        f1.getline(l1[count],15,'|');
        f1.getline(offset[count],5, '|');
        count++;
    }
    count--;
    norS = count;
    printf("\n\nNumber of Stud Rec : %d", norS);

    for(int i=0; i<norS; i++)
        printf("\nStudentRecord %d : %s",i,l1[i]);

    count=0;

    std::fstream f2("marksIndex.txt", std::ios::in);
    while(!f2.eof())
    {
        f2.getline(l2[count],15,'|');
        f2.getline(offsetM[count], 5, '|');
        count++;
    }
    count--;
    norM = count;
    printf("\n\nNumber of marks Rec : %d", norM);
    for(int i=0; i<norM; i++)
        printf("\nStudentRecord %d : %s",i,l2[i]);

    f1.close();
    f2.close();

    int m=norS, n=norM;
    int i=0,j=0,k=0;
    std::fstream f3("eligible.txt", std::ios::out);
    std::fstream is("record.txt", std::ios::in);


    while(i<m&&j<n)
    {
        if(strcmp(l1[i],l2[j])==0)
        {
            int off = atoi(offset[i]);
            is.seekg((int)off, std::ios::beg);
            b.unpack(stud, off);
            if(strcmp(b.getstatus(stud),"t")==0){
                strcpy(l3[k],l1[i]);
                f3<<b.getusn(stud)<<"|"<<b.getname(stud)<<"|"<<b.getbranch(stud)<<"\n";
                k++;
            }
            else{
                printf("\nFalse error");
            }
            i++;
            j++;
        }
        else if(strcmp(l1[i],l2[j])<0)
            i++;
        else
            j++;
    }
}
