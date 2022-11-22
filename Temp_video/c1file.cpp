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
    f = fopen("c1file.txt", "rt");
    int n, arr[10];
    fscanf(f,"%d", &n);
    //doc du lieu tu file
    for(int i = 0; i < n; i++){
        fscanf(f,"%d", &arr[i]);
    }
    fclose(f);

    //thu hien phep tinh
    //tinh tong mang
    int tong = 0;
    for(int i = 0; i < n; i++){
        tong += arr[i];        
    }
    printf("\ntong: %d", tong);
    //tim so nguyen to: 
    printf("\nin ra so nguyen to: ");
    int temp[10], dem = 0, tang = 0;
    for(int i = 0; i < n; i++){
        dem = 0;
        for(int j = 1; j <= arr[i]; j++){
            if(arr[i] % j == 0){
                dem++;
            }
        }
        if(dem == 2){   // day la so nguyen to
            temp[tang] = arr[i];
            tang++;
            printf("%d\t", arr[i]);
        }
    }

    //ghi vao filekq.txt
    f = fopen("c1filekq.txt","wt");
    fprintf(f, "\ntong gia tri cua mang: %d",tong);
    fprintf(f,"\nso nguyen to la: ");
    for(int i = 0; i < tang; i++){
        fprintf(f,"%d\t", temp[i]);
    }
    fclose(f);

    return 0;
}