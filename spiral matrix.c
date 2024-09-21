#include <stdio.h>

void spiral(int matrix[5][5]){
    int j;
    int rowBegin=0, rowEnd=4, colBegin=0, colEnd=4;

    while(rowBegin <= rowEnd && colBegin <= colEnd){
        for(j = colBegin; j <= colEnd; j++){
            printf("%d ", matrix[rowBegin][j]);
        }
        rowBegin++;

        for(j = rowBegin; j <= rowEnd; j++){
            printf("%d ", matrix[j][colEnd]);
        }
        colEnd--;

        if(rowBegin <= rowEnd){
            for(j = colEnd; j >= colBegin; j--){
                printf("%d ", matrix[rowEnd][j]);
            }
            rowEnd--;
        }

        if(colBegin <= colEnd){
            for(j = rowEnd; j >= rowBegin; j--){
                printf("%d ", matrix[j][colBegin]);
            }
            colBegin++;
        }
    }
}

int main(){
    int A[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    spiral(A);
    return 0;
}
