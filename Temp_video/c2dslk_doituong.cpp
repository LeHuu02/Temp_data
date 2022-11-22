/*
power by le minh huu 22/12/2022 @LeHuu02 @copyright
yeu cau:    - nhap xuat dslk doi tuong sinh vien: masv, ten, diem
            - in thong tin sv tai Ha Noi
            - them / xoa sinh vien thu k
            - xoa sv co diem < 5
            - dem sinh vien co ten la thanh

        NOTE: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sinhvien{
    char masv[100];
    char ten[100];
    float diem;
};
struct NODE{
    sinhvien data;
    NODE *next;
};
struct list{
    NODE *phead;
    NODE *ptall;
};
NODE *makeNode(sinhvien sv){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p->data = sv;
    p->next = NULL;
    return p;
}
void khoitao(list &l){
    l.phead = l.ptall = NULL;
}
void themcuoi(list &l, sinhvien sv){
    NODE *p = makeNode(sv);
    if(l.phead == NULL){
        l.phead = l.ptall = p;
    }else{
        l.ptall->next = p;
        l.ptall = p;
    }
}
void nhap(list &l){
    int n;
    sinhvien sv;
    printf("\nnhap vao so luong sinh vien: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("\nnhap sv thu %d: ", i+1);
        fflush(stdin);
        printf("\nnhap ma sv: ");
        gets(sv.masv);
        printf("nhap ten sv: ");
        gets(sv.ten);
        printf("nhap diem: ");
        fflush(stdin);
        scanf("%f", &sv.diem);
        themcuoi(l,sv);
    }
}
void xuat(list l){
    printf("\nin ra ds sv: ");
    for(NODE *p = l.phead; p != NULL; p=p->next){
        printf("\nma sv: %s\tten: %s\tdiem: %.2f", p->data.masv, p->data.ten,  p->data.diem);
    }
}
void xoadau(list &l){
    l.phead = l.phead->next;
}
void xoak(list &l){
    int dem = 0, k;
    printf("\nnhap vao vi tri can xoa: ");
    scanf("%d",&k);
    for(NODE *p = l.phead; p != NULL; p=p->next){
        dem++;
        if(dem == k-1){
            p->next = p->next->next;
        }
    }
}
void themsvk(list &l){
    int dem = 0, k;
    sinhvien sv;
    printf("\nnhap vao vi tri can them: ");
    scanf("%d",&k);
    fflush(stdin);
    printf("\nnhap ma sv: ");
    gets(sv.masv);
    printf("nhap ten sv: ");
    gets(sv.ten);
    printf("nhap diem: ");
    fflush(stdin);
    scanf("%f", &sv.diem);
    for(NODE *p = l.phead; p != NULL; p=p->next){
        dem++;
        if(dem == k-1){
            NODE *a = makeNode(sv);
            a->next = p->next;
            p->next = a;
        }
    } 
}
void xoa5(list &l){
    chonay:
    int dem = 0, t;
    NODE *p;
    for(p = l.phead; p != NULL; p=p->next){
        dem++;
        if(p->data.diem < 5){
            if(dem == 1){
                xoadau(l);
            }
            t = 0;
            for(NODE *k = l.phead; k != NULL; k=k->next){
                t++;
                //di chuyen den vi tri truoc vi tri k
                if(t == dem -1){
                    k->next = k->next->next;
                    // p = l.phead;
                    goto chonay;
                }
            }
        }
    }   
}
void dem(list l){
    int dem = 0;    
    for(NODE *p = l.phead; p != NULL; p = p->next){
        if(strcmp(p->data.ten, "Le Thanh") == 0){
            dem++;
        }
    }
    printf("\nso sinh vien co ten la le thanh: %d", dem);
}
int main(){
    list l;
    khoitao(l);
    nhap(l);
    xuat(l);
    // xoak(l);
    xoa5(l);
    // themsvk(l);
    printf("\nds sv sau khi xoa sv duoi 5 thu k: ");
    xuat(l);
    dem(l);
    return 0;
}