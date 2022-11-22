/*
power by le minh huu 22/12/2022 @LeHuu02 @copyright
yeu cau:    - nhap / xuat  danh sach mang sinh vien: masv, hoten, diem
            - in sinh vien co diem >5

    NOTE: struct, 
*/
#include <stdio.h>
#include <stdlib.h>

struct sinhvien{
    char masv[100];
    char ten[100];
    float diem;
};

void nhap(sinhvien sv[], int n){
    printf("\nnhap vao thong tin sv: ");
    for(int i = 0; i < n; i++){
        printf("\nsinh vien thu %d: ", i+1);
        fflush(stdin);
        printf("\nnhap ma sv: ");
        gets(sv[i].masv);
        printf("nhap ten: ");
        gets(sv[i].ten);
        fflush(stdin);
        printf("nhap diem: ");
        scanf("%f", &sv[i].diem);
    }
}
void xuat(sinhvien sv[], int n){
    printf("\nthong tin sinh vien: ");
    printf("\n=======================");
    for(int i = 0; i < n; i++){
        printf("\nma sv: %s\tten: %s\tdiem: %.2f\t", sv[i].masv, sv[i].ten, sv[i].diem);
    }
}
void insv(sinhvien sv[], int n){
    printf("\nin sinh vien co diem lon hon 5: ");
    for(int i = 0; i < n; i++){
        if(sv[i].diem >= 5){
            printf("\nma sv: %s\tten: %s\tdiem: %.2f\t", sv[i].masv, sv[i].ten, sv[i].diem);
        }
    }
}
int main(){
    int n;
    printf("nhap vao so luong sinh vien: ");
    scanf("%d", &n);
    sinhvien sv[n];
    nhap(sv, n);
    xuat(sv, n);
    insv(sv, n);
    return 0;
}