#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int random1to100();
void printAr(int numAr[],int numArSize);
int checkNum(int numAr[],int numArSize);
int searchNum(int numAr[],int numArSize,int target);
void sortDesc(int A[], int n);

int main(){
    int i;
    int A[4];

    srand(time(NULL));

    for(i=0;i<4;i++)
        A[i] = checkNum(A,i);

    printf("\nAll scores : ");
    printAr(A,4);

    sortDesc(A,4);

    printf("\nBest 3 scores : ");
    for(i=0;i<3;i++)
        printf("%d ",A[i]);

    return 0;
}

void printAr(int numAr[],int numArSize){
    int i;
    for(i=0;i<numArSize;i++)
        printf("%d ",numAr[i]);
}

int checkNum(int numAr[],int numArSize){
    int rnum;
    rnum = random1to100();

    while(searchNum(numAr,numArSize,rnum)){
        rnum = random1to100();
    }
    return rnum;
}

int searchNum(int numAr[],int numArSize,int target){
    int i;
    for(i=0;i<numArSize;i++){
        if(numAr[i]==target)
            return 1;
    }
    return 0;
}

int random1to100(){
    return (rand()%100)+1;
}

void sortDesc(int A[], int n){
    int i,j,temp;

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(A[i] < A[j]){
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}