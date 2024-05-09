//lastEdit=>2023.05.09-16:17
//lastEdit=>2023.05.30-10:58
//lastEdit=>2023.05.29-17:48
//lastEdit=>2023.01.02-17:20
/*
双链表实现字符串列表
功能:=>只有地址唯一;key,index,valu均可以重复
    //0.1)base->获取字符串长度
        int stringLen(char *list);
    //0.2)base->一维列表复制
        void *stringCopy(char *list);
    //0.3)base->两个字符串拼接
        void *stringAdd(char *strA,char *strB);
    //0.4)base->字符串截取,bug只能够截取英文字符串,左闭右开
        void *stringSplit(char *str,int start,int end);
    //0.5)base->判断两个字符串是否相同,相同返回true,否者返回false
        int stringCmp(char *strA,char *strB);
    //1)base->打印链表一个节点
        void printNode(const struct listNode *node);
    //1)base->链表全部打印
        void printList(struct listNode *list);
    //1)链表初始化,创建一个链表节点
        void *initNode(int *index,char *key,char *valu);
    //2.1)快速拼接->两个链表(不安全,节约内存)
        void *fappend(struct listNode *listA,struct listNode *listB);
    //2.2)复制拼接->两个链表(安全,浪费内存)
        void *append(struct listNode *listA,struct listNode *listB);
    //2.3)快速拼接->一个链表与一个节点(不安全)
        void *faddNode(struct listNode *list,struct listNode *node);
    //2.4)复制拼接->一个链表与一个节点(安全)
        void *addNode(struct listNode *list,struct listNode *node);
    //2.5)修改链表的索引
        void *sortIndex(struct listNode *list);
    //3.1)删节点->根据节点的地址
        void *delNode(struct listNode *list,struct listNode *node);
    //3.2)删节点->根据找到的第一个key
        void *delNodeKey(struct listNode *list,char *key);
    //3.2)删节点->根据找到的第一个key
        void *delNodeKey(struct listNode *list,char *key);
    //3.3)插,插入一个节点或列表;    mode:插入模式{0:在节点后插入, 1:在节点前插入, 其它:报错}
        void *insert(struct listNode *list,struct listNode *insertList,char *key,int mode);
    //4)改,从新修改某个节点
        void *changeNode(struct listNode *list,char *oldKey,char *newKey,char *newvalu);
    //5.1)查,找到链表的首节点
        void *findHead(struct listNode *list);
    //5.2)查,找到链表的尾节点
        void *findTail(struct listNode *list);
    //5.3)查,根据“节点”地址查找节点
        void *findPoint(struct listNode *list,struct listNode *node);
    //5.4)查,根据“key”查找节点
        void *findKey(struct listNode *list,char *key);
    //5.5)查,根据“valu”查找节点
        int findValu(struct listNode *list,char *valu);
    //6.1)复制链表->复制一个节点,只复制节点的key与value及index,其余无论有无全置为NULL
        void *copyNode(struct listNode *node);
    //6.2)复制链表->整个链表
        void *copyList(struct listNode *list);
    //7.1)释放空间,及指针
        void *freeList(struct listNode *list);
    //7.2)删除->节点中所有为NULL的key
        void *freeNULLKey(struct listNode *list);
    //7.3)删除->节点中所有为NULL的valu
        void *freeNULLValu(struct listNode *list);
*/
#include<stdio.h>
#include<malloc.h>

#define true 1
#define false 0
#define nil -1

//列表节点,既可以“索引查询”,又可以“键值对查询”
//列表初始化时全赋值为NULL,以免数据的溢出
struct listNode{
    int index;//索引
    char *key;          //键
    char *valu;         //内容
    struct listNode *front;     //指向前一个节点
    struct listNode *behind;    //指向后一个节点
    // struct listNode *head;      //指向整个链表的第一个节点,只有首节点有改属性
    // struct listNode *tail;      //指向整个链表的最后一个节点,只有首节点有改属性
};

//0.1)base->获取字符串长度
int stringLen(char *list);
//0.2)base->一维列表复制
void *stringCopy(char *list);
//0.3)base->两个字符串拼接
void *stringAdd(char *strA,char *strB);
//0.4)base->字符串截取,bug只能够截取英文字符串,左闭右开
void *stringSplit(char *str,int start,int end);
//0.5)base->判断两个字符串是否相同,相同返回true,否者返回false
int stringCmp(char *strA,char *strB);
//1)base->打印链表一个节点
void printNode(const struct listNode *node);
//1)base->链表全部打印
void printList(struct listNode *list);
//1)链表初始化,创建一个链表节点
void *initNode(int *index,char *key,char *valu);
//2.1)快速拼接->两个链表(不安全,节约内存)
void *fappend(struct listNode *listA,struct listNode *listB);
//2.2)复制拼接->两个链表(安全,浪费内存)
void *append(struct listNode *listA,struct listNode *listB);
//2.3)快速拼接->一个链表与一个节点(不安全)
void *faddNode(struct listNode *list,struct listNode *node);
//2.4)复制拼接->一个链表与一个节点(安全)
void *addNode(struct listNode *list,struct listNode *node);
//2.5)修改链表的索引
void *sortIndex(struct listNode *list);
//3.1)删节点->根据节点的地址
void *delNode(struct listNode *list,struct listNode *node);
//3.2)删节点->根据找到的第一个key
void *delNodeKey(struct listNode *list,char *key);
//3.2)删节点->根据找到的第一个key
void *delNodeKey(struct listNode *list,char *key);
//3.3)插,插入一个节点或列表;    mode:插入模式{0:在节点后插入, 1:在节点前插入, 其它:报错}
void *insert(struct listNode *list,struct listNode *insertList,char *key,int mode);
//4)改,从新修改某个节点
void *changeNode(struct listNode *list,char *oldKey,char *newKey,char *newvalu);
//5.1)查,找到链表的首节点
void *findHead(struct listNode *list);
//5.2)查,找到链表的尾节点
void *findTail(struct listNode *list);
//5.3)查,根据“节点”地址查找节点
void *findPoint(struct listNode *list,struct listNode *node);
//5.4)查,根据“key”查找节点
void *findKey(struct listNode *list,char *key);
//5.5)查,根据“valu”查找节点
int findValu(struct listNode *list,char *valu);
//6.1)复制链表->复制一个节点,只复制节点的key与value及index,其余无论有无全置为NULL
void *copyNode(struct listNode *node);
//6.2)复制链表->整个链表
void *copyList(struct listNode *list);
//7.1)释放空间,及指针
void *freeList(struct listNode *list);
//7.2)删除->节点中所有为NULL的key
void *freeNULLKey(struct listNode *list);
//7.3)删除->节点中所有为NULL的valu
void *freeNULLValu(struct listNode *list);


//0.1)base->获取字符串长度
int stringLen(char *list){
    int listlen = 0;
    if(list==NULL){return listlen;}
    while(list[listlen]){listlen++;}
    return listlen;
}

//0.2)base->一维列表复制
void *stringCopy(char *list){
    if(list==NULL){return NULL;}
    char *retvalu = (char *)malloc(stringLen(list)*sizeof(char));
    int index = 0;
    while(list[index]){retvalu[index]=list[index],retvalu[index+1]='\0';index++;}
    return retvalu;
}

//0.3)base->两个字符串拼接
void *stringAdd(char *strA,char *strB){
    if(strA==NULL){return stringCopy(strB);}
    if(strB==NULL){return stringCopy(strA);}
    if(strA==NULL && strB==NULL){return NULL;}
    int strlen = stringLen(strA)+stringLen(strB);
    char *retvalu = (char *)malloc((strlen+1)*sizeof(char));
    int index=0;
    for(int i=0;strA[i];i++){retvalu[index++]=strA[i];retvalu[index]='\0';}
    for(int i=0;strB[i];i++){retvalu[index++]=strB[i];retvalu[index]='\0';}
    return retvalu;
}

//0.4)base->字符串截取,bug只能够截取英文字符串,左闭右开
void *stringSplit(char *str,int start,int end){
    if(str==NULL){return NULL;}
    if(start==end){return NULL;}
    int srclen = stringLen(str);
    int tsta = start,tend = end;
    if(tsta<0){tsta=tsta+srclen;}
    if(tend<0){tend=tend+srclen+1;}
    if(tsta<0 || tend<0 || tend>srclen){printf("\twarn->func:void *stringSplit\t->out of index\n");return NULL;}
    if(tsta>tend){printf("\twarn->func:void *stringSplit\t->arg start and end error\n");return NULL;}
    char *retvalu = (char *)malloc((tend-tsta+1)*sizeof(char));
    for(int idx=0;idx<(tend-tsta);idx+=1){retvalu[idx]=str[idx+tsta];retvalu[idx+1]='\0';}
    return retvalu;
}

//0.5)base->判断两个字符串是否相同,相同返回true,否者返回false
int stringCmp(char *strA,char *strB){
    if(strA==NULL || strB==NULL){return nil;}
    if(stringLen(strA)!=stringLen(strB)){return false;}
    for(int i=0;strA[i];i++){if(strA[i]!=strB[i]){return false;}}
    return true;
}

//1)base->打印链表一个节点
void printNode(const struct listNode *node){
    if(node==NULL){printf("->pAddr:%p is empty!!!\n",node);}
    if(node!=NULL){printf("->pAddr:%p\tidx:%d\tkey:%s\tvalu:%s\n",node,node->index,node->key,node->valu);}
}

//1)base->链表全部打印
void printList(struct listNode *list){
    if(list==NULL){printf("->%p is empty!!!\n",list);}
    for(struct listNode *cursor = list;cursor!=NULL;cursor=cursor->behind){printNode(cursor);}
}

//1)base->获取链表的长度
int listLen(struct listNode *list){
    int index=0;
    for(struct listNode *cur=list;cur!=NULL;cur=cur->behind,index++){}
    return index;
}

//1)链表初始化,创建一个链表节点
void *initNode(int *index,char *key,char *valu){
    struct listNode *retvalu = (struct listNode *)malloc(sizeof(struct listNode));
    retvalu->index = 0;
    retvalu->key = NULL;
    retvalu->valu = NULL;
    retvalu->front = NULL;
    retvalu->behind = NULL;
    if(index){retvalu->index=*index;}
    if(key){retvalu->key = stringCopy(key);}
    if(valu){retvalu->valu = stringCopy(valu);}
    return retvalu;
}

//2.1)快速拼接->两个链表(不安全,节约内存)
void *fappend(struct listNode *listA,struct listNode *listB){
    if(listA==NULL){return listB;}
    if(listB==NULL){return listA;}
    // 拼接
    // struct listNode *listAhead=NULL;//listA首节点
    struct listNode *listAtail=NULL;//listA尾节点
    struct listNode *listBhead=NULL;//listB首节点
    // struct listNode *listBtail=NULL;//listB尾节点
    // for(listAhead=listA;listAhead->front!=NULL;listAhead=listAhead->front){}     // listA的头节点
    for(listAtail=listA;listAtail->behind!=NULL;listAtail=listAtail->behind){}    // listA的尾节点
    // for(listBhead=listB;listBhead->front!=NULL;listBhead=listBhead->front){}     // listB的头节点
    // for(listBtail=listB;listBtail->behind!=NULL;listBtail=listBtail->behind){}   // listB的尾节点
    listBhead = listB;
    listAtail->behind = listBhead;
    listBhead->front = listAtail;
    return listA;
}

//2.2)复制拼接->两个链表(安全,浪费内存)
void *append(struct listNode *listA,struct listNode *listB){
    struct listNode *clistA = copyList(listA);
    struct listNode *clistB = copyList(listB);
    if(clistA==NULL){return clistB;}
    if(clistB==NULL){return clistA;}
    return fappend(clistA,clistB);
}

//2.3)快速拼接->一个链表与一个节点(不安全)
void *faddNode(struct listNode *list,struct listNode *node){
    if(node==NULL){return list;}
    if(list==NULL){return node;}
    struct listNode *listTail = findTail(list);
    listTail->behind = node;
    node->front = listTail;
    node->behind = NULL;
    return list;
}

//2.4)复制拼接->一个链表与一个节点(安全)
void *addNode(struct listNode *list,struct listNode *node){
    if(node==NULL){return copyList(list);}
    if(list==NULL){return copyNode(node);}
    struct listNode *retvalu = copyList(list);
    struct listNode *retnode = copyNode(node);
    return faddNode(list,retnode);
}

//2.5)修改链表的索引
void *sortIndex(struct listNode *list){
    int index = 0;
    for(struct listNode *cur=list;cur!=NULL;cur=cur->behind){cur->index = index++;}
    return list;
}

//3.1)删节点->根据节点的地址
void *delNode(struct listNode *list,struct listNode *node){
    if(findPoint(list,node)==false){printf("==>err:func delNode node node:{%p} not exist\n",node);return list;}
    struct listNode *aimNode = node;
    struct listNode *head = findHead(list);
    struct listNode *tail = findTail(list);
    if(aimNode!=NULL){
        if(aimNode->behind==NULL && aimNode->front==NULL){return NULL;}
        if(aimNode==head){
            head = head->behind;
            head->front = NULL;
            return head;
        }//是头节点
        if(aimNode==tail){
            tail = tail->front;
            tail->behind = NULL;
            return head;
        }//是尾节点
        aimNode->front->behind = aimNode->behind;
        aimNode->behind->front = aimNode->front;
    }
    return list;
}

//3.2)删节点->根据找到的第一个key
void *delNodeKey(struct listNode *list,char *key){
    struct listNode *aimNode = findKey(list,key);
    if(aimNode==NULL){printf("==>err:func delNodeKey node key:{%s} not exist\n",key);return list;}
    struct listNode *head = findHead(list);
    struct listNode *tail = findTail(list);
    if(aimNode!=NULL){
        if(aimNode->behind==NULL && aimNode->front==NULL){return NULL;}
        if(aimNode==head){
            head = head->behind;
            head->front = NULL;
            return head;
        }//是头节点
        if(aimNode==tail){
            tail = tail->front;
            tail->behind = NULL;
            return head;
        }//是尾节点
        aimNode->front->behind = aimNode->behind;
        aimNode->behind->front = aimNode->front;
    }
    return list;
}

//3.3)插,插入一个节点或列表;    mode:插入模式{0:在节点后插入, 1:在节点前插入, 其它:报错}
void *insert(struct listNode *list,struct listNode *insertList,char *key,int mode){
    if(insertList==NULL){return list;}  // insertList被插入的列表
    struct listNode *aimNode = findKey(list,key);    // aimNode目标节点
    if(aimNode==NULL){printf("==>err:func insert node key:{%s} not exist\n",key);return list;}
    struct listNode *iListHead = findHead(insertList);
    struct listNode *iListTail = findTail(insertList);
    if(mode==0){    // 在节点前插入
        //在头节点前插入
        if(aimNode==findHead(list)){
            iListTail->behind = aimNode;
            aimNode->front = iListTail;
            return iListHead;
        }
        //不是头节点
        struct listNode *aimFront = aimNode->front;
        aimFront->behind = iListHead;
        iListHead->front = aimFront;
        iListTail->behind = aimNode;
        aimNode->front = iListTail;
        return list;
    }
    if(mode==1){// 在节点后插入
        // 在尾节点后插入
        if(aimNode==findTail(list)){   
            aimNode->behind = iListHead;
            iListHead->front = aimNode;
            return list;
        }
        // 不是尾节点
        struct listNode *aimBehind = aimNode->behind;
        aimNode->behind = iListHead;
        iListHead->front = aimNode;
        iListTail->behind = aimBehind;
        aimBehind->front = iListTail;
        return list;
    }
    printf("==>err: func insert mode error!!!\n");
    return NULL;
}

//4)改,重新修改某个节点
void *changeNode(struct listNode *list,char *oldKey,char *newKey,char *newvalu){
    struct listNode *aimNode = findKey(list,oldKey);
    if(aimNode==NULL){printf("==>err:func changeNode node key:{%s} not exist\n",oldKey);return list;}
    aimNode->key = stringCopy(newKey);
    aimNode->valu = stringCopy(newvalu);
    return list;
}

//5.1)查,找到链表的首节点
void *findHead(struct listNode *list){
    if(list==NULL){return list;}
    struct listNode *head = NULL;
    for(head=list;head->front!=NULL;head=head->front){}
    return head;
}

//5.2)查,找到链表的尾节点
void *findTail(struct listNode *list){
    if(list==NULL){return list;}
    struct listNode *tail=NULL;
    for(tail=list;tail->behind!=NULL;tail=tail->behind){}
    return tail;
}

//5.3)查,根据“节点”地址查找节点
void *findPoint(struct listNode *list,struct listNode *node){
    if(list==NULL || node==NULL){return NULL;}//列表或目标节点为空
    struct listNode *aimNode = findHead(list);
    while(aimNode!=NULL){
        if(aimNode==node){return aimNode;break;}
        aimNode = aimNode->behind;
    }
    return NULL;
}

//5.4)查,根据“key”查找节点
void *findKey(struct listNode *list,char *key){
    if(list==NULL || key==NULL){return NULL;}//列表或目标节点为空
    struct listNode *aimNode = findHead(list);
    while(aimNode!=NULL){
        if(stringCmp(aimNode->key,key)==true){return aimNode;break;}
        aimNode = aimNode->behind;
    }
    return aimNode;
}

//5.5)查,根据“valu”查找节点
int findValu(struct listNode *list,char *valu){
    if(list==NULL || valu==NULL){return nil;}//列表或目标节点为空
    struct listNode *tmpList = findHead(list);
    while(tmpList!=NULL){
        if(stringCmp(tmpList->valu,valu)==true){return true;break;}
        tmpList=tmpList->behind;
    }
    return false;
}

//5.6)查,根据“index”查找节点
void *findIndex(struct listNode *list,int index){
    if(list==NULL){return NULL;}//列表或目标节点为空
    int tindex = index;
    if(index<0){tindex = index+listLen(list);}
    if(tindex<0){return NULL;}
    struct listNode *aimNode = findHead(list);
    while(aimNode!=NULL){
        if(aimNode->index==tindex){return aimNode;break;}
        aimNode=aimNode->behind;
    }
    return NULL;
}

//6.1)复制链表->复制一个节点,只复制节点的key与value及index,其余无论有无全置为NULL
void *copyNode(struct listNode *node){
    if(node==NULL){return NULL;}
    return initNode(&node->index,node->key,node->valu);
}

//6.2)复制链表->整个链表
void *copyList(struct listNode *list){
    if(list==NULL){return NULL;}
    struct listNode *newlist=NULL;
    struct listNode *retvalu=NULL;
    for(struct listNode *cur=list;cur!=NULL;cur=cur->behind){
        struct listNode *newnode = initNode(0,cur->key,cur->valu);
        if(newlist==NULL){newlist=newnode,retvalu=newlist;continue;}
        newlist->behind = newnode;
        newnode->front = newlist;
        newlist=newlist->behind;
    }
    return retvalu;
}

//7.1)释放空间,及指针
void *freeList(struct listNode *list){
    struct listNode *cur = list;
    for(;cur->behind!=NULL;cur=cur->behind){} // 找到尾部节点
    for(;cur!=NULL;cur=cur->front){// 从尾部向前清除数据
        if(cur->behind!=NULL){cur->behind->front=NULL;free(cur->behind);}
        cur->index = 0;
        cur->key = NULL;
        cur->valu = NULL;
        cur->behind = NULL;
    }
    return list;
}

//7.2)删除->节点中所有为NULL的key
void *freeNULLKey(struct listNode *list){
    if(list==NULL){return NULL;}
    for(struct listNode *tNode=list;tNode!=NULL;tNode=tNode->behind){
        if(tNode->key==NULL){list = delNode(list,tNode);free(tNode);}
    }
    return list;
}

//7.3)删除->节点中所有为NULL的valu
void *freeNULLValu(struct listNode *list){
    if(list==NULL){return NULL;}
    for(struct listNode *tNode=list;tNode!=NULL;tNode=tNode->behind){
        if(tNode->valu==NULL){list = delNode(list,tNode);free(tNode);}
    }
    return list;
}


