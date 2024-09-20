#include <stdio.h>
#include <stdlib.h>

#if 0
int main(void){
    int **m;
    m = (int **)malloc(sizeof(int *)*3);
    m[0] = (int *)malloc(sizeof(int)*5);
    m[1]= (int*)malloc(sizeof(int)*5);
    m[2] = (int*)malloc(sizeof(int)*5);

    for(int i=0; i<3; i++){
        for(int j=0; j<5 ; j++){
            m[i][j] = i*j*10;
        }
    }

    printf("%d, %d\n",m[1][2],m[2][1]);
}
#endif

int main(void){
    int **m;
    //주소 공간 3개를 만든다.
    m = (int**)malloc(sizeof(int*)*3);
    //5개의 공간을 만든다.
    m[0] = (int *)malloc(sizeof(int)*5);
    m[1] = (int *)malloc(sizeof(int)*5);
    m[2] = (int *)malloc(sizeof(int)*5);

    for(int i=0; i<3; i++){
        for(int j=0; j<5;j++){
            m[i][j] = i*j*10;
        }
    }
    printf("%d %d\n", m[1][2],m[2][3]);
}

