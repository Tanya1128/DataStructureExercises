//数据结构：顺序表
#include<stdio.h>
#include<stdlib.h>

//下面是每一个节点的组成
typedef struct TreeNode
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}TreeNode;

//下面用一个顺序表来储存每个节点
typedef struct HFTree{
    TreeNode* data; //存储节点的数组
    int length;//记录当前数组有多少个节点
}HFTree;

HFTree* intiTree(int* weight, int length){
    HFTree* T=(HFTree*)malloc(sizeof(HFTree));
    T->data=(TreeNode*)malloc(sizeof(TreeNode)*(2*length-1));//扩容
    //开辟数组的空间，这里如果有n个节点，那它们构成的哈夫曼树就有2n-1个节点
    T->length=length;
    for(int i=0;i<length;i++){
        T->data[i].weight=weight[i];
        T->data[i].parent=0;
        T->data[i].lchild=-1;
        T->data[i].rchild=-1;
    }
    return T;
}

//选择第一小和第二小的节点
int* selectionMin(HFTree* T){
    int min=10000;
    int secondMin=10000;
    int minIndex;
    int secondIndex;
    for(int i=0;i<T->length;i++){
        if(T->data[i].parent==0){
            if(T->data[i].weight<min){
                min=T->data[i].weight;
                minIndex=i;
            }
        }
    }
    for(int i=0;i<T->length;i++){
        if(T->data[i].parent==0&&i!=minIndex){
            if(T->data[i].weight<secondMin){
                secondMin=T->data[i].weight;
                secondIndex=i;
            }
        }
    }

    int* res =(int*)malloc(sizeof(int)*2);
    res[0]=minIndex;
    res[1]=secondIndex;
    return res;
}

void createHFTree(HFTree* T){
    int* res;
    int min;
    int secondMin;
    int length=T->length*2-1;
    for(int i=T->length;i<length;i++){
        res=selectionMin(T);
        min=res[0];
        secondMin=res[1];
        T->data[i].weight=T->data[min].weight+T->data[secondMin].weight;
        T->data[i].lchild=min;
        T->data[i].rchild=secondMin;
        T->data[min].parent=i;
        T->data[secondMin].parent=i;
        T->length++;
    }
}

void preOreder(HFTree* T,int index){
    if(index!=-1){
        printf("%d ",T->data[index].weight);
        preOreder(T,T->data[index].lchild);
        preOreder(T,T->data[index].rchild);
    }
}
int main(){
    int weight[4]={1,2,3,4};  //输出：10 4 6 3 3 1 2
    HFTree* T=intiTree(weight,4);
    createHFTree(T);
    preOreder(T,T->length-1);
    printf("\n");
    return 0;
}