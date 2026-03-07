#include <stdio.h>
int findMax(int num[]);
void addone(int number[], int add[], int sizeNum);
void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos);
void addthree(int number[], int pos[][2], int sizePos);
int main() {
    int number[5] = {20,50,100,99,9};
    int add[5] = {1,2,3,4,5};
    int pos1[3] = {0,2,4};
    int pos2[2][2] = {{1,10},{3,20}};
    int max,i;
    printf("Original Array\n");
    for(i=0;i<5;i++)
        printf("number[%d] : %d\n",i,number[i]);

    addone(number,add,5);

    printf("\nAfter addone\n");
    for(i=0;i<5;i++)
        printf("number[%d] : %d\n",i,number[i]);
    addtwo(number,pos1,5,5,3);

    printf("\nAfter addtwo\n");
    for(i=0;i<5;i++)
        printf("number[%d] : %d\n",i,number[i]);

    addthree(number,pos2,2);

    printf("\nAfter addthree\n");
    for(i=0;i<5;i++)
        printf("number[%d] : %d\n",i,number[i]);

    max = findMax(number);
    printf("\nMaximum of these number is %d\n",max);
}
void addone(int number[], int add[], int sizeNum){
    int i;
    for(i=0;i<sizeNum;i++)
        number[i] = number[i] + add[i];
}
void addtwo(int number[], int pos[], int x, int sizeNum, int sizePos){
    int i;
    for(i=0;i<sizePos;i++){
        if(pos[i] < sizeNum)
            number[pos[i]] = number[pos[i]] + x;
    }
}
void addthree(int number[], int pos[][2], int sizePos){
    int i;
    for(i=0;i<sizePos;i++){
        number[pos[i][0]] = number[pos[i][0]] + pos[i][1];
    }
}
int findMax(int num[]){
    int maximum,i;
    maximum = num[0];

    for(i=0;i<5;i++){
        if(num[i] > maximum)
            maximum = num[i];
    }
    return maximum;
}