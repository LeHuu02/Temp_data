/*
power by le minh huu 22/12/2022 @LeHuu02 @copyright
yeu cau:    - tao 1 danh sach lien ket so nguyen
            - them phan tu vao / xoa phan tu di. vi tri k
            - tinh tong phan tu trong ds

        NOTE: tao node, cap phat bo nho, khoi tao them dau them cuoi,...
*/
#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    NODE *next;
};
struct list{
    NODE *phead;
    NODE *ptall;
};
NODE *makeNode(int x){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p->data = x;
    p->next = NULL;
    return p;
}
void khoitao(list &l){
    l.phead = l.ptall = NULL;
}
void themcuoi(list &l, int x){
    NODE *p = makeNode(x);
    if(l.phead == NULL){
        l.phead = l.ptall = p;
    }else{
        l.ptall->next = p;
        l.ptall = p;
    }
}
void nhap(list &l){
    int n, x;
    printf("\nnhap vao so phan tu ds: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("\nnhap phan tu thu %d: ", i+1);
        scanf("%d", &x);
        themcuoi(l,x);
    }
}
void xuat(list l){
    printf("\nds sinh vien: ");
    for(NODE *p = l.phead; p != NULL; p=p->next){
        printf("%d\t", p->data);
    }
}
void xoadau(list &l){
    l.phead = l.phead->next;
}
void xoak(list &l){
    int k;
    printf("\nnhap vao vi tri can xoa: ");
    scanf("%d", &k);
    int dem = 0;    
    for(NODE *p = l.phead; p != NULL; p=p->next){
        dem++;
        if(dem == k-1){
            p->next = p->next->next;
        }
    }
}
void themk(list &l){
    int x, k, dem = 0;
    printf("\n nhap vao vi tri can them: ");
    scanf("%d", &k);
    printf("\n nhap vao gia tri can them: ");
    scanf("%d", &x);
    for(NODE *p = l.phead; p != NULL; p=p->next){
        dem++;
        if(dem == k-1){
            NODE *a = makeNode(x);
            a->next = p->next;
            p->next = a;
        }
    }
}
void tong(list l){
    int tong = 0;
    for(NODE *p = l.phead; p != NULL; p = p->next){
        tong += p->data;
    }
    printf("\ntong cac phan tu trong ds la: %d", tong);
}
int main(){
    list l;
    khoitao(l);
    nhap(l);
    xuat(l);
    // xoadau(l);
    // xoak(l);
    themk(l);
    printf("\nds sau khi them vi tri k: ");
    xuat(l);
    tong(l);
    return 0;
}