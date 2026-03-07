#include<stdio.h>
int checkscore(char std[]);
int countNo1Correct(char ans[][10], int stdSize);
int hardestQuestion(char ans[][10], int stdSize);

char keys[10]={'D','B','D','C','C','D','A','E','A','D'};

int main() {
    int i;
    char ans[8][10]={
        {'A','B','A','C','C','D','E','E','A','D'}, 
        {'D','B','A','B','C','A','E','E','A','D'}, 
        {'E','D','D','A','C','B','E','E','A','D'}, 
        {'C','B','A','E','D','C','E','E','A','D'}, 
        {'A','B','D','C','C','D','E','E','A','D'}, 
        {'B','B','E','C','C','D','E','E','A','D'}, 
        {'B','B','A','C','C','D','E','E','A','D'}, 
        {'E','B','E','C','C','D','E','E','A','D'}  
    };
    char s[10];
    for(i=0;i<8;i++){
        int j;
        for(j=0;j<10;j++)
            s[j]=ans[i][j];

        printf("std %d => %d\n",(i+1),checkscore(s));
    }
    printf("Number of student correct no.1 = %d\n",countNo1Correct(ans,8));

    printf("Hardest question is no.%d\n",hardestQuestion(ans,8));
    return 0;
}
int checkscore(char std[]){
    int i,score=0;
    for(i=0;i<10;i++){
        if(std[i]==keys[i])
            score++;
    }
    return score;
}
int countNo1Correct(char ans[][10], int stdSize){
    int i,count=0;
    for(i=0;i<stdSize;i++){
        if(ans[i][0]==keys[0])
            count++;
    }
    return count;
}
int hardestQuestion(char ans[][10], int stdSize){
    int i,j;
    int minCorrect=stdSize;
    int hardest=0;
    for(j=0;j<10;j++){
        int correct=0;
        for(i=0;i<stdSize;i++){
            if(ans[i][j]==keys[j])
                correct++;
        }
        if(correct < minCorrect){
            minCorrect = correct;
            hardest = j;
        }
    }
    return hardest+1;
}