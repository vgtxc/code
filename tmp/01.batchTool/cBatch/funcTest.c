#include "cPath-win.c"

int main(){
    // struct listNode *node01=listInit(NULL,"k01","v01");
    // struct listNode *node02=listInit(NULL,"k02","v02");
    // struct listNode *node03=listInit(NULL,"k03","v03");
    // struct listNode *node04=listInit(NULL,"k04","v04");
    // struct listNode *node05=listInit(NULL,"k05","v05");
    // struct listNode *node06=listInit(NULL,"k06","v06");
    // struct listNode *node07=listInit(NULL,"k07","v07");
    // struct listNode *node08=listInit(NULL,"k08","v08");
    // struct listNode *node09=listInit(NULL,"k09","v09");
    // struct listNode *listA=NULL;
    // struct listNode *listB=NULL;
    // struct listNode *listC=NULL;
    // listA = fappend(listA,node01);
    // listA = fappend(listA,node02);
    // listA = fappend(listA,node03);
    // listA = fappend(listA,node04);

    // listB = append(listB,node05);
    // listB = append(listB,node06);
    // listB = append(listB,node07);
    // listB = append(listB,node08);

    // listC = changeNode(listA,"k01",123,"aaa","valuvalu");
    // node01->valu = stringCopy(NULL);
    // node04->key = stringCopy(NULL);
    // node01->key = stringCopy(NULL);
    // node04->key = stringCopy(NULL);
    // printList(listA);
    // listA = delNode(listA,node01);
    // printNode(node01);
    // printf("\n\n");
    // printList(listA);
    
    // printNode(node03);
    // printNode(node03);

    // listA = delNode(listA,"k01",-1);
    // listA = delNode(listA,"k02",-1);
    // listA = delNode(listA,"k03",-1);
    // listA = delNode(listA,"k04",-1);
    // listA = sortIndex(listA);
    // int result = findIndex(listA,-5);
    // switch (result){
    //     case true:{printf("exist?=>    true\n");break;}
    //     case false:{printf("exist?=>    false\n");break;}
    //     case nil:{printf("exist?=>    arg err!!!\n");break;}
    //     default:{printf("exist?=>    func err!!!\n");break;}
    // }
    // freeList(listA);
    // printList(listA);


    char *path = "D:/entertain/img/*";
    // char *path = "D:/sw/aDrive";
    // char *path = "D:/entertain/game";
    struct listNode *list = pathWalk(path);
    // printNode(list);
    // printList(list);
    return 0;
}