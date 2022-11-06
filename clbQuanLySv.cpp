//power by Nguyen The Truong make by le minh huu - 15/2/2022
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hoTen[20], lop[10];
    float diemtk;
}item;  //kieu du lieu item gom 3 truong: ho ten, lop, diem tk

struct danhsach{
    item sv[100];
    int count;
}ds;    //kieu du lieu danh sach gom 2 truong la: mang sv kieu du lieu item, bien dem count

//ham nhap vao thong tin hoc sinh
void nhap(){
    //thuc hien nhap so sinh vien neu < 0 hoac > 100 thi nhap lai
    do{
        printf("\nnhap vao so sinh vien: ");
        scanf("%d", &ds.count);
    }while(ds.count < 0 || ds.count > 100);
    //nhap lan luot thong tin sinh vien tu 0 den count
    for(int i = 0; i < ds.count; i++){
        printf("Ho ten: ");
        fflush(stdin);
        gets(ds.sv[i].hoTen);
        printf("Lop: ");
        fflush(stdin);
        gets(ds.sv[i].lop);
        printf("diem tk: ");
        scanf("%f", &ds.sv[i].diemtk);
    }
}

//xuat ra thong tin sinh vien
void xuat(){
    printf("\ndanh sach sinh vien vua nhap la: ");
    for(int i = 0; i < ds.count; i++){
        printf("\n%s\t%s\t%.2f",ds.sv[i].hoTen,ds.sv[i].lop,ds.sv[i].diemtk);
    }
}

//dem so sinh vien co diem lon hon 5
int demSinhVien(){
    //kiem tra lan luot tu dau den cuoi mang danh sach sinh vien, neu co diemtk > 5 thi tang bien dem len 1
    int dem = 0;
    for( int i = 0; i < ds.count; i++){
        if(ds.sv[i].diemtk > 5){
            dem++;
        }
    }
    //sau khi dem xong thi in ra ket qua
    if(dem > 0){
        printf("\nso sinh vien co diem lon hon 5 la: %d", dem);
    }else{
        printf("\nkhong co sinh vien nao lon hon 5");
    }
}

//tim kiem ten sinh vien su dung ham so sanh chuoi strcmp trong thu vien string.h
void timKiemTenSV(){
    char x[20]; //khai bao chuoi x
    fflush(stdin);
    printf("\nnhap ten sinh vien can tim: ");
    gets(x);    //nhap chuoi x
    // thuc hien kiem tra lan luot tu dau den cuoi danh sach sinh vien, neu phat hien ten sv trung thi se in ra thong tin cua sinh vien
    for( int i = 0; i < ds.count; i++){
        if(strcmp(x,ds.sv[i].hoTen) == 0){
            printf("\n%s\t%s\t%.2f",ds.sv[i].hoTen,ds.sv[i].lop,ds.sv[i].diemtk);
        }
    }
}

//xoa sinh vien tai vi tri k
int xoa(int k){
    //kiem tra dieu kien vi tri k
    if(k > 0 && k <= ds.count ){
        //neu vi tri k thoa man dk thi se dich chuyen mang ds sv tu vi tri k den cuoi ds sang ben trai 1 don vi
        for(int i = k; i < ds.count; i++){
            ds.sv[i-1] = ds.sv[i];
        }
        //sau khi dich sang trai 1 don vi thi giam bien dem count 1 don vi va tra ve
            ds.count--;
            return 1;   
    }else{
        printf("\n gia tri xoa khong hop le!");
        return -1;
    }
}

//them 1 sinh vien tai vi tri k
int themSV(int k,item x){
    //kiem tra dk vi tri k
    if(k > 0 && k <= ds.count ){
        //dich ds mang tu vi tri k den cuoi ds sang ben phai 1 don vi
        for(int i = ds.count + 1; i >= k; i--){
            ds.sv[i] = ds.sv[i-1];
        }
        ds.count++; //tang so phan tu trong ds
        ds.sv[k] = x;   //luu gia tri can them vao vi tri k
        return 1;
    }
    printf("\nkhong them sinh vien ");
     return 0;
}

int main(){
    item ds;
    int k;
    nhap();
    xuat();
    //dem so sinh vien diem > 5
    demSinhVien();
    //tim kiem theo ten sinh vien
    timKiemTenSV();
    //xoa sinh vien tai vi tri k
    printf("\nvi tri can xoa: ");
    scanf("%d", &k);
    xoa(k);
    xuat();
    fflush(stdin);
    //nhap vao sinh vien can them    
    printf("\n ho ten sinh vien: ");
    fflush(stdin);
    gets(ds.hoTen);
    printf("lop cua sinh vien: ");
    fflush(stdin);
    gets(ds.lop);
    printf("diem tong ket: ");
    scanf("%f", &ds.diemtk); 
    printf(" vi tri can them: ");
    scanf("%d", &k);
    themSV(k, ds);
    xuat();
}