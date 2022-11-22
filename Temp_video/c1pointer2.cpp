/*
power by le minh huu 22/12/2022 @LeHuu02 @copyright
yeu cau:    - dung con tro nhap xuat mang 2 chieu
            - tong cheo chinh, tong so nguyen to

        NOTE: * la gia tri, & la dia chi
                cap phat dong
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, i, j;
    printf("\nnhap vao n x m: ");
    scanf("%d%d", &n, &m);
    int *arr;
    arr = (int*)malloc(n*m*sizeof(int));
    //nhap phan tu mang
    printf("\nnhap phan tu mang: ");
    for(i = 0; i <  n; i++){
        for(j = 0; j < m; j++){
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", (arr + n*i +j));
        }
    }
    //in phan tu:
    printf("\nin mang vua nhap: \n");
    for(i = 0; i <  n; i++){
        for(j = 0; j < m; j++){
            printf("%d\t ", *(arr + n*i +j));            
        }
        printf("\n");
    }
    //tong cheo chinh: i == j
    int tong = 0;
    for(i = 0; i <  n; i++){
        for(j = 0; j < m; j++){
            if( i == j){
                tong += *(arr + n*i +j);
            }
        }
    }
    printf("\ntong cheo chinh: %d", tong);
    //tong so nguyen to: 
    int dem;
    //duyet mang tu dau den cuoi
    tong = 0;
    for(i = 0; i <  n; i++){
        for(j = 0; j < m; j++){
            //kiem tra xem *(arr + n*i +j) co phai snt k
            dem = 0;
            for(int x = 1; x <= *(arr + n*i +j); x++ ){
                if(*(arr + n*i +j) % x == 0){
                    dem++;
                }
            }
            if(dem == 2){
                tong +=*(arr + n*i +j);
            }
        }
    }
    printf("\ntong so nguyen to la: %d", tong);
    return 0;
}