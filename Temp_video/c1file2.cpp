/*
power by le minh huu 22/12/2022 @LeHuu02 @copyright
thao tac file:
yeu cau:- doc mang du lieu trong file.txt
        - tinh tong, tim so nguyen to
        - ghi tong va so nguyen to vao filekq.txt

    NOTE:   FILE *f
            f = fopen("c1file.txt","rt/wt");
            fclose(f);
            fscanf(f, "%d", &n);
            fprintf(f, "noi dung");
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    //doc mang tu file.txt
    FILE *f;
    f = fopen("c1file2.txt", "rt");
    int n, m, arr[10][10];
    fscanf(f,"%d", &n);
    fscanf(f,"%d", &m);
    //doc du lieu tu file
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fscanf(f,"%d", &arr[i][j]);
        }        
    }
    fclose(f);

    //thu hien phep tinh
    //tinh tong mang
    int tong = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tong += arr[i][j];        
        }
    }
    printf("\ntong: %d", tong);

    //ghi vao filekq.txt
    f = fopen("c1filekq2.txt","wt");
    fprintf(f, "\ntong gia tri cua mang: %d",tong);
    fclose(f);

    return 0;
}