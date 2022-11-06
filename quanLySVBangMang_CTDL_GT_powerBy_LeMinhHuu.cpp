//POWER BY LE MINH HUU 9/2/2022 - CTDL&GT - QUAN LY DANH SACH SINH VIEN - @copyright
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N 100

//khai bao kieu du lieu item thuoc kieu int
typedef int item;
typedef char chuoi;  //phai khai bao kieu du lieu chuoi kieu char vi vd: hoten[n] => chi la 1 bien kieu char co do dai n phan tu
typedef float diemso;

//khai bao danh sach, input can nhap theo thu tu lan luot tu ho ten lop diem... 
typedef struct{
    char hoTen[N];
    char lop[N];
    diemso diemTB[N];
    int count;
}sinhVien;

//khoi tao danh sach rong, cho bien dem danh sach = 0
int init(sinhVien &sv){
    sv.count = 0;
}

//nhap gia tri cho danh sach
void inPut(sinhVien &sv){
    //nhap so sv trong ds
    printf("\nnhap vao tong so sinh vien trong danh sach: ");
    scanf("%d", &sv.count);
    //nhap thong tin sinh vien
    int i;
    for(i = 0; i < sv.count; i++){
        printf("sinh vien thu %d: ", i+1);
        printf("\nho ten: ");
        gets(sv.hoTen[i]);
        scanf("%s", &sv.hoTen[i]);
        printf("lop: ");
        gets(sv.lop[i]);
        scanf("%s", &sv.lop[i]);
        printf("diem tb: ");
        scanf("%f", &sv.diemTB[i]);
        printf("\n");
    }
}

//in ra danh sach vua nhap
void outPut(sinhVien &sv){
    printf("\ndanh sach sinh vien vua nhap la:");
    int i;
    for(i = 0; i < sv.count; i++){
        printf("\nsinh vien thu %d: ", i+1);
        printf("\nho ten: %s",sv.hoTen[i]);
        printf("\nlop: %s", sv.lop[i]);
        printf("\ndiem tb: %.3f", sv.diemTB[i]);
        printf("\n========================\n");
    }
}

//kiem tra danh sach day
int isFull(sinhVien sv){
    return (sv.count == N); //neu so sv = N thi se tra ve gia tri 1
}
//kiem tra danh sach rong
int isSempty(sinhVien sv){
    return (sv.count == 0); //neu so sv = 0 thi tra ve gia tri 1
}
//tim kiem va tra ve vi tri
int search(sinhVien sv, chuoi ht[N]){
    int i;
    for(i = 0; i < sv.count; i++){
        if(sv.hoTen[i] == ht[N]){
            return (i+1);   //tim duoc se tra ve gia tri i+1 la vi tri cua kq can tim
        }
    }
    return 0;   //neu chay den cuoi danh sach ma khong tim thay thi tra ve gia tri 0
}

//tim kiem theo ten sinh vien: dua ra vi tri, lop, diem so
int search_hoTen(sinhVien sv, chuoi ht[N]){
    //kiem tra tu dau den cuoi danh sach, neu kq trung thi tra ve vi tri 
    int i;
    for(i = 0; i < sv.count; i++){
        //neu tim duoc sinh vien can tim
        if(sv.hoTen[i] == ht[N]){
            printf("\nvi tri cua sv %s la: %d", sv.hoTen[i], i+1);
            printf("\n========================\n");
            printf("\nsinh vien thu %d: ", i+1);
            printf("\nho ten: %s",sv.hoTen[i]);
            printf("\nlop: %s", sv.lop[i]);
            printf("\ndiem tb: %.3f", sv.diemTB[i]);
            printf("\n========================\n");
        }
        //neu khong tim duoc sinh vien
        else{
            printf("\nNOT FOUND - ERORR 404");
            printf("\nkhong co sinh vien %s trong danh sach", ht[N]);
        }
    }
}
//them mot gia tri x vao trong danh sach tai vi tri k
int insert_viTri_k(sinhVien *sv, item k){   //sao lai phai co dau * nhi
    //kiem tra danh sach day
    if(isFull(*sv)){
        printf("\ndanh sach sinh vien da day");
        return 0;
    }
    //nhap vao vi tri muon chen
    printf("\nnhap vao vi tri can chen: ");
    scanf("%d", &k);
    //kiem tra vi tri chen hop le
    if(k < 1 || k > (*sv).count){
        printf("\nvi tri chen khong hop le!");
        return 0;
    }
    //di chuyen cac gia tri tu vi tri k den cuoi danh sach sang ben phai 1 don vi
    int i;
    for(i = (*sv).count+1; i >= k; i--){
        (*sv).hoTen[i] = (*sv).hoTen[i-1];
        (*sv).lop[i] = (*sv).lop[i-1];
        (*sv).diemTB[i] = (*sv).diemTB[i-1];
    }
    //tang so sinh vien trong danh sach
    (*sv).count++;
    //nhap gia tri can chen
    printf("\nho ten: ");
    scanf("%s", &sv.hoTen[k-1]);
    printf("lop: ");
    scanf("%s", &sv.lop[k-1]);
    printf("diem tb: ");
    scanf("%f", &sv.diemTB[k-1]);
    printf("\n");    
    return 1;
}
//xoa sinh vien co diem tb < 5
int xoaSV_diemTBNho5(sinhVien *sv){
    //kiem tra danh sach rong
    if(isSempty((*sv))){
        printf("\ndanh sach sinh vien rong!");
        return 0;
    }
    //kiem tra sv co diem nho hon 5 lan luot tu dau den cuoi danh sach
    int i;
    for(i = 0; i < (*sv).count; i++){
        //ktra sv co diem nho hon 5
        if(sv.diemTB[i] < 5){
            //thuc hien chuyen cac phan tu tu vi tri sv.diemTB[i] < 5 den cuoi danh sach sang ben trai 1 don vi
            int j;
            for(j = i; j <= sv.count-1; j++){
                (*sv).hoTen[j] = (*sv).hoTen[j+1];
                (*sv).lop[j] = (*sv).lop[j + 1];
                (*sv).diemTB[j] = (*sv).diemTB[j + 1];
                //giam di 1 don vi trong danh sach
                (*sv).count--;
            }
        }
    }
}

//dem so sinh vien co diem tb >5
int soSV_diemLon5(sinhVien sv){
    //kiem tra danh sach rong
    if(isSempty(sv)){
        printf("\ndanh sach sinh vien rong!");
        return 0;
    }
    //dem so sv co diem lon hon 5 lan luot tu dau den cuoi danh sach
    int i, demDiemLonHon5 = 0;
    for(i = 0; i < sv.count; i++){
        //ktra sv co diem lon hon 5
        if(sv.diemTB[i] > 5){
            demDiemLonHon5++;
        }
    }
    //in ra man hinh ket qua
    if(demDiemLonHon5 > 0){
        printf("\nso sinh vien co diem tb lon hon 5 la: %d", demDiemLonHon5);
    }else{
        printf("\nkhong co sinh vien nao co diem tb lon hon 5");
    }
}

//POWER BY LE MINH HUU 9/2/2022 - CTDL&GT - QUAN LY DANH SACH SINH VIEN - @copyright
int main(){
    sinhVien ds_SV;
    item x;
    chuoi ten[N];
    init(ds_SV);
    inPut(ds_SV);
    outPut(ds_SV);
    printf("\nnhap hoten de tim kiem thong tin: ");
    scanf("%s", &ten[N]);
    search_hoTen(ds_SV, ten);
    insert_viTri_k(&ds_SV, x);
    outPut(ds_SV);
    xoaSV_diemTBNho5(&ds_SV);
    outPut(ds_SV);
    soSV_diemLon5(ds_SV);
    outPut(ds_SV);
    return 0;
}
