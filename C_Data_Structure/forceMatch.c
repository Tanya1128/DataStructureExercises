#include<stdio.h>
#include<stdlib.h>

typedef struct String{
    char* data;
    int len;
}String;

String* initString(){
    String* s=(String*)malloc(sizeof(String));
    s->data=NULL;
    s->len=0;
    return s;
}

void stringAssign(String* s,char* data){
    if(s->data){
        free(s->data);
    }
    int len=0;
    char* temp=data;
    while(*temp){
        len++;
        temp++;
    }
    if(len==0){
        s->data=NULL;
        s->len=0;
    }else{
        temp=data;
        s->len=len;
        //c语言中 字符串长度永远多一位就是\0
        s->data=(char*)malloc(sizeof(char)*(len+1));
        //temp++是 指向字符串的指针往后移
        //或者说这个temp指针就是指向字符数组首元素的指针，
        //使用++符号就相当于往后跳了一位了
        for(int i=0;i<=len;i++,temp++){
            s->data[i]=*temp;
        }
    }
}

void forceMatch(String* master,String* sub){
    int i=0,j=0;
    while(i<master->len&&j<sub->len){
        if(master->data[i]==sub->data[j]){
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if(j==sub->len){
            printf("force match success.\n");
        }else{
            printf("force match fail.\n");
        }
}
void printString(String* s){
    for(int i=0;i<=s->len;i++){
        printf(i==0 ? "%c ":"-> %c ",s->data[i]);
    }
    printf("\n");
}

int main()
{
    String* s1=initString();
    String* s2=initString();
    String* s3=initString();
    stringAssign(s1,"Hello,Tanya");
    stringAssign(s2,"Tan");
    stringAssign(s3,"ye");
    printString(s1);
    forceMatch(s1,s2);
    forceMatch(s1,s3);
    return 0;
}

//argc是argv的长度，argv[0]是文件名，
//argv[1],argv[2],argv[3]，...是传的参数
/*
int main(int argc,char* argv[])
{
    String* s1=initString();
    String* s2=initString();
    String* s3=initString();
    stringAssign(s1,argv[1]);
    stringAssign(s2,argv[2]);
    stringAssign(s3,argv[3]);
    printString(s1);
    forceMatch(s1,s2);
    forceMatch(s1,s3);
    return 0;
}
*/