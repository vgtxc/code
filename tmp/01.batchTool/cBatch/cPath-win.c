/*路径处理*/
/*
log:
    lastEdit=>2023.01.03
    bug     pathWalk无法读取某些长路径
    base->字符串截取    strSplit
    base->多个字符串拼接    strJoin
    base->判断是否为文件夹  judgeDir
    super->文件名拆分   pathTextSplit
    super->路径拆分     pathSplit
    super->路径拼接     pathJoin
    super->路径遍历     pathWalk

    #include<io.h>
    struct _finddata_t {  
        unsigned attrib;     //文件属性  
        time_t time_create;  //文件创建时间  
        time_t time_access;  //文件上一次访问时间  
        time_t time_write;   //文件上一次修改时间  
        _fsize_t size;  //文件字节数  
        char name[_MAX_FNAME]; //文件名  
    };
    attrib对应的宏
        #define _A_NORMAL 0x00  ->正常
        #define _A_RDONLY 0x01  ->只读
        #define _A_HIDDEN 0x02  ->隐藏
        #define _A_SYSTEM 0x04  ->系统
        #define _A_SUBDIR 0x10  ->文件夹
        #define _A_ARCH 0x20    ->存档
*/
#include<stdio.h>
// #include<dirent.h>
#include<malloc.h>
// #include <sys/types.h>

#include<io.h>
// #include<string.h>
#include<sys/stat.h>
// #include<unistd.h>
#include "cList.c"      //自编链表


#define true 1
#define false 0
#define nil -1
//base->判断一个路径是否为文件夹,是返回true,不是返回false
int judgeDir(char *path){
    struct _stat buf;
    int isDir = _stat(path,&buf);
    if(buf.st_mode & _S_IFDIR){return true;}
    return false;
}
//base->修改路径中的“\”为“/”
char *subRSlash(char *path){
    char *retvalu = (char *)malloc((stringLen(path)+1)*sizeof(char));
    for(long long int i=0;path[i];i++){
        retvalu[i] = path[i];
        if(path[i]=='\\'){retvalu[i]='/';}
        retvalu[i+1]='\0';
    }
    return retvalu;
}

//super->路径遍历,只读取获取一层
void *pathWalk(char *path){
    //返回的路径链表,包含所有的文件及文件夹
    struct listNode *pathList=NULL;
    // _findfirst()函数中的路径需要添加通配符
    // char *tpath = stringAdd(subRSlash(path),"/*");
    // 读取文件或文件夹的结果,-1不存在,0存在
    intptr_t handle;
    // 读取文件或文件夹的相关信息
    struct _finddata_t *buf = (void *)malloc(sizeof(struct _finddata_t));
    if(_findfirst(path,buf)==-1){printf("\t==>err:func pathWalk arg err\n");return NULL;}
    for(;_findnext(handle,buf)!=-1;){
        printf("%s\n",buf->name);
    }
    _findclose(handle);
    return NULL;
}

//super->路径遍历,递归遍历
void *pathWalkAll(char *path){
    // printf("\tinfo:func pathWalkAll->pt:%s\n",path);
    struct listNode *root = pathWalk(path);
    struct listNode *son = NULL;
    // 找到所有的文件夹,文件夹路径的节点释放掉
    for(struct listNode *ptNode=root;ptNode!=NULL;ptNode=ptNode->behind){
        // 判断路径"ptNode->valu"是否为文件夹
        if(judgeDir(ptNode->valu)==true){
            struct listNode *tNode = copyNode(ptNode);
            son = fappend(son,pathWalkAll(ptNode->valu));
            ptNode->valu = NULL;
        }
    }
    root = freeNULLValu(root);
    
    return fappend(root,son);
}
