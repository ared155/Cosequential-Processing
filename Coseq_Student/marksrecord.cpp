#include "marksrecord.h"
#include "string.h"

MarksRecord::MarksRecord()
{
;
}

char indexM[100][50],indexaddM[100][50];
int norM=0;

MarksRecord::MarksRecord(std::string usn){
    strcpy(this->usn, usn.c_str());
}

BufferMarks::BufferMarks(){
    for(int i=0;i<500;i++)
        buff[i]='\0';
}

void BufferMarks::pack(MarksRecord &obj)
{
    strcpy(buff,obj.usn);
    strcat(buff,"|");
}

void BufferMarks::unpack(MarksRecord &obj)
{
    char *ptr=buff;
    while(*ptr)
    {
        if(*ptr=='|')
            *ptr='\0';
        ptr++;
    }
    ptr=buff;
    strcpy(obj.usn,ptr);
}

void BufferMarks::read(std::fstream &fs)
{
    fs.read(buff,sizeof(buff));
}

int BufferMarks::write(std::string fname)
{
    int len=0;
    std::fstream os(fname,std::ios::app);

    os.seekp(0,std::ios::end);
    int offset = os.tellp();

    while(buff[len] != '\0'){
        len++;
    }

    os.write(buff,len);
    os.close();

    return offset;
}

void sortByIndexM()
{
    char temp[100],temp1[100];
    for(int i=0;i<norM;i++)
    {
        for(int j=i+1;j<norM;j++)
        {
            if(strcmp(indexM[i],indexM[j])>0)
            {
                strcpy(temp,indexM[i]);
                strcpy(indexM[i],indexM[j]);
                strcpy(indexM[j],temp);
                strcpy(temp1,indexaddM[i]);
                strcpy(indexaddM[i],indexaddM[j]);
                strcpy(indexaddM[j],temp1);
            }
        }
    }
    for(int i=0; i<norM; i++){
        printf("\n\tRecord %d Index[] %s\n", i, indexM[i]);
    }
}

int BufferMarks::add(MarksRecord &obj){
    char sadd[50];
    //checking for duplicate entry of usn
    for(int i=0;i<norM;i++)
    {
        if(strcmp(obj.usn,indexM[i])==0)
        {
            printf("\nduplicate entry\n");
            return 0;
        }
    }
    BufferMarks buff;
    buff.pack(obj);
    int off = buff.write("marksRecord.txt");

    itoa(off, sadd, 10);
    strcpy(indexaddM[norM],sadd);
    strcpy(indexM[norM],obj.usn);
    norM++;

    sortByIndexM();
    //writing to index.txt
    std::fstream indexStream("marksIndex.txt",std::ios::out);

    for(int i=0; i<norM; i++){
        indexStream<<indexM[i]<<'|'<<indexaddM[i]<<'|';
    }

    indexStream.close();
    return 1;
}
