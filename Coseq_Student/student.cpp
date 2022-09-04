#include "student.h"
#include "cstring"

char index[100][50],indexadd[100][50];
int nor=0;

Student::Student()
{
;
}

Student::Student(std::string usn ,std::string name, std::string branch, std::string status){
    //c_str() converts std::string to char *
    strcpy(this->usn, usn.c_str());
    strcpy(this->name, name.c_str());
    strcpy(this->branch, branch.c_str());
    strcpy(this->status, status.c_str());
}

Buffer::Buffer(){
    for(int i=0;i<500;i++)
        buff[i]='\0';
}

void Buffer::pack(Student &obj)
{
    strcpy(buff,obj.usn);
    strcat(buff,"|");
    strcat(buff,obj.name);
    strcat(buff,"|");
    strcat(buff,obj.branch);
    strcat(buff,"|");
    strcat(buff,obj.status);
    strcat(buff,"|");
}

void Buffer::unpack(Student &s, int off){
    std::fstream is("record.txt", std::ios::in);
    is.seekg(off, std::ios::beg);

    is.getline(s.usn,15,'|');
    is.getline(s.name,50,'|');
    is.getline(s.branch,50,'|');
    is.getline(s.status,5,'|');

    is.close();
}

void Buffer::read(std::fstream &fs)
{
    fs.read(buff,sizeof(buff));
}

int Buffer::write(std::string fname)
{
    int len=0;
    std::fstream os(fname,std::ios::app);

    os.seekp(0,std::ios::end);
    int offset = os.tellp();

    //finding length of the buffer
    while(buff[len] != '\0'){
        len++;
    }
    //could have used strlen(buffer)
    printf("Entry of \n%s", buff);
    os.write(buff,len);
    os.close();

    return offset;
}

void sortByIndex()
{
    char temp[100],temp1[100];
    for(int i=0;i<nor;i++)
    {
        for(int j=i+1;j<nor;j++)
        {
            if(strcmp(index[i],index[j])>0)
            {
                strcpy(temp,index[i]);
                strcpy(index[i],index[j]);
                strcpy(index[j],temp);
                strcpy(temp1,indexadd[i]);
                strcpy(indexadd[i],indexadd[j]);
                strcpy(indexadd[j],temp1);
            }
        }
    }
}

int Buffer::add(Student &obj){
    char sadd[50];

    //checking for duplicate entry of usn
    for(int i=0;i<nor;i++)
    {
        if(strcmp(obj.usn,index[i])==0)
        {
            printf("\nduplicate entry\n");
            return 0;
        }
    }

    Buffer buff;
    buff.pack(obj);
    int off = buff.write("record.txt");
    itoa(off, sadd, 10);
    strcpy(indexadd[nor],sadd);
    strcpy(index[nor],obj.usn);
    nor++;
    sortByIndex();

    //writing to index.txt
    std::fstream indexStream("index.txt",std::ios::out);
    for(int i=0; i<nor; i++)
        indexStream<<index[i]<<'|'<<indexadd[i]<<'|';

    indexStream.close();
    return 1;
}

char* Buffer::getstatus(Student &obj){
    return obj.status;
}

char* Buffer::getname(Student &obj){
    return obj.name;
}

char* Buffer::getusn(Student &obj){
    return obj.usn;
}

char* Buffer::getbranch(Student &obj){
    return obj.branch;
}

