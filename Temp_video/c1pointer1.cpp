/*
power by le minh huu 22/12/2022 @LeHuu02 @copyright
yeu cau:    - su dung con tro thao tac voi mang 1 chieu
            - nhap xuat mang dung pointer
            - sap xep tang dan va tim min
            - so chinh phuong   
        
        NOTE: * gia tri
                & dia chi
                cap phat bo nho dong: malloc
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tang(int *arr, int n){
      //sap xep tang
    int temp, j, i;
    for(i = 0; i < n-1; i++){
        for( j = i+1; j < n; j++){
            if(*(arr+i) > *(arr+j)){    //tuong tu nhu arr[i] > arr[j]
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
                // printf("\t%d\t", temp);
            }
        }
    }
      printf("\nin mang sau khi sap xep tang: ");
    for(i = 0; i < n; i++){
        printf("%d\t", *(arr+i));
    }  
}

int main(){
    int n, i;
    printf("\nnhap so phan tu mang: ");
    scanf("%d", &n);
    int *arr;
    arr = (int*)malloc(n*sizeof(int));
    //nhap vao gia tri mang
    printf("\nnhap phan tu mang: \n");
    for(i = 0; i < n; i++){
        printf("phan tu %d: ", i+1);
        scanf("%d", (arr+i));
    }
    //in mang
    printf("\nin mang vua nhap: ");
    for(i = 0; i < n; i++){
        printf("%d\t", *(arr+i));
    }
    //sap xep tang
    // int temp, j;
    // for(i = 0; i < n-1; i++){
    //     for( j = i+1; j < n; j++){
    //         if(*(arr+i) < *(arr+j)){    //tuong tu nhu arr[i] > arr[j]
    //             temp = *(arr+i);
    //             *(arr+i) = *(arr+j);
    //             *(arr+j) = temp;
    //             printf("\t%d\t", temp);
    //         }
    //     }
    // }
    //in mang
    // printf("\nin mang sau khi sap xep tang: ");
    // for(i = 0; i < n; i++){
    //     printf("%d\t", *(arr+i));
    // }
    // tang(arr, n);
    
    //tim min
    int min = *(arr+0);
    for(i = 1; i < n; i++){
        if(min > *(arr+i)){
            min = *(arr+i);
        }
    }
    printf("\n gia tri min la: %d", min);

    //in so chinh phuong   : 
    printf("\nso chinh phuong trong mang la: ");
    for(i = 0; i < n; i++){
        if((float)sqrt(*(arr+i)) - (int)sqrt(*(arr+i)) == 0){   //vd 5
            printf("%d\t", *(arr+i));
        }
    }
    return 0;
}