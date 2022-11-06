//POWER BY LE MINH HUU 7/2/2022 - DANH SACH CAI DAT BANG MANG - CAU TRUC DU LIEU VA GIAI THUAT
#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef int item;   //khai bao kieu du lieu item thuoc kieu int

//* la gia tri con & la dia chi
//tao danh sach list gom 2 truong elems (mang elems) va count (dem)
typedef struct {
    item elems[N];  //mang elems thuoc kieu du lieu item
    int count;
}list;

//khoi tao danh sach rong
void init(list &l){ 
    l.count = 0; //kieu con tro de co the thay doi gia tri cua bien trong ham main
}

//nhap mang nhu binh thuong
void inPut(list &l){
    printf("\nnhap vao so phan tu danh sach: ");
    scanf("%d", & l.count);
    int i;
    for(i = 0; i < l.count; i++){
        printf("\nphan tu thu %d: ", i +1);
        scanf("%d",& l.elems[i]);
    }
}

//xuat mang nhu binh thuong
void outPut(list &l){
    printf("\ndanh sach list vua nhap la: ");
    int i;
    for(i = 0; i < l.count; i++){
        printf("\nphan tu thu %d: %d", i+1, l.elems[i]);
    }
}

//kiem tra danh sach day: neu tong so phan tu trong mang = N thi tra vr true 1 (dung)
int isFull(list l){
    return (l.count == N);
}

//kiem tra danh sach rong: neu tong so phan tu trong mang = 0 thi tra ve true 1 (dung)
int isSempty(list l){
    return (l.count == 0);
}

//tim kiem vi tri phan tu x trong mang: duyet tu phan tu dau tien den cuoi cung va so sanh xem phan tu nao trung voi x va dua ra vi tri i
int search(list l, item x){
    int i;
    for(i = 0; i < l.count; i++){
        if(l.elems[i] == x){
            return i+1;
        }
    }
}

//chen phan tu x vao vi tri p trong mang elems cua danh sach l
int insert_viTri_p (list *l, item x, int p){
    //kiem tra danh sach day
    if(isFull(*l)){
        printf("\ndanh sach mang da day");
        return 0;
    }
    //nhap vi tri can chen vao mang
    printf("\nnhap vi tri can chen trong mang: ");
    scanf("%d", &p);

    //kiem tra vi tri chen vao co hop le hay khong, vi tri p phai nam trong mang
    if(p < 0 || p > (*l).count){    //sao lai (*l).count nhi
        printf("\nvi tri chen khong hop le");
        return 0;
    }
    //neu thoa man dieu kien danh sach khong day va vi tri hop le thi thuc hien theo ba buoc
    //nhap gia tri can chen vao
    printf("\ngia tri can chen vao la: ");
    scanf("%d", &x);
    //roi cac phan tu tu vi tri cuoi danh sach den vi tri p sang ben phai 1 don vi
    int i;
    for(i = (*l).count+1; i >= p; i--){
        (*l).elems[i] = (*l).elems[i-1];
    }
    //dua phan tu moi vao vi tri p
    (*l).elems[p-1] = x;
    //tang do dai ds len 1 dv
    (*l).count++;
    return 1;
}

//xoa phan tu x thuoc vi tri k trong dang sach
int xoa_pt_Thu_k(list *l, item *x, int k){
    //kiem tra danh sach rong
    if(isSempty(*l)){
        printf("\ndanh sach nay rong");
        return 0;
    }
    printf("\nnhap vi tri can xoa:");
    scanf("%d", &k);
    //kiem tra vi tri hop le
    if(k < 1 || k > (*l).count){
        printf("\nvi tri can xoa khong hop le");
        return 0;
    }
    //luu gia tri xoa o vi tri thu k
    *x = (*l).elems[k-1];
    //thuc hien chuyen cac phan tu tu vi tri k den cuoi danh sach sang ben trai 1 don vi
    //k la vi tri thuc nhung trong mang thi k - 1 de dung vi tri: vd nhap k = 4 thi trong mang se o vi tri thu 3 do mang bat dau tu 0
    int i;
    for(i = k-1; i <= (*l).count-1; i++){
        (*l).elems[i]  = (*l).elems[i+1];    // gia tri truoc = gia tri sau
    }
    //giam do dai cua mang
    (*l).count--;
    /* l->count--; khac gi cai tren nhi?
        vd: int a = 5;
        *a = 5;
        *(&a) = 5;
        a = 5;  */
    return 1;
}

//tim va xoa phan tu x trong mang
int xoa_phanTu_x(list *l, item x){
    //kiem tra danh sach rong
    if(isSempty(*l)){
        printf("\ndanh sach nay rong");
        return 0;
    }
    printf("\nnhap vao gia tri can xoa ");
    scanf("%d", &x);
    //goi ham search de tim kiem vi tri cua gia tri x trong danh sach
    int m;
    m = search(*l,x);
    if(m = 0){
        printf("khong co gia tri %d trong danh sach", x);
        return 0;
    }
    //thuc hien xoa phan tu co gia tri x trong danh sach va tiep tuc tim den het danh sach 
    do{
        //m la vi tri thuc nhung trong mang thi m - 1 de dung vi tri: vd nhap m = 4 thi trong mang se o vi tri thu 3 do mang bat dau tu 0
        int i;
        for(i = m-1; i < (*l).count-1; i++){
            (*l).elems[i]  = (*l).elems[i+1];    // gia tri truoc = gia tri sau
            printf("\nxinchao");
        }
        //giam do dai cua mang
        (*l).count--;
        printf("\nketthuc");
        // cach khac goi ham xoa_pt_Thu_k(l, &x, m);
        m = search(*l, x);
    }while(m);
    printf("\nhet");
    return 1;
}

// xoa phan tu x
int Xoa_X(list *l,item x){
	if((*l).count == 0){
		printf("\nDanh sach rong!");
		return 0;
	}
	printf("\nNhap gia tri muon xoa: ");
	scanf("%d",&x);
	int v=search(*l,x);
	if(!v){
		printf("\nDanh sach khong co phan tu tren!");
		return 0;
	}
	do{
		for(int i=v-1;i<(*l).count-1;i++){
			(*l).elems[i] = (*l).elems[i+1];
		}
		(*l).count--;
		v=search(*l,x);
	}while(v);	
}

//dem so phan tu chan le am duong trong danh sach
int dem_chanLeAmDuong(list l){
    //kiem tra danh sach rong
    if(isSempty(l)){
        printf("\ndanh sach nay dang rong ");
        return 0;
    }
    //thuc hien dem
    int i, demChan = 0, demLe = 0, demAm = 0, demDuong = 0;
    for(i = 0; i < l.count; i++){
        //dem so chan
        if(l.elems[i] > 0 && l.elems[i] % 2 == 0){
            demChan++;
        }
        //dem so le
        if(l.elems[i] > 0 && l.elems[i] % 2 == 1){
            demLe++;
        }
        //dem so am
        if(l.elems[i] < 0){
            demAm++;
        }
        //dem so duong
        if(l.elems[i] > 0){
            demDuong++;
        }
    }
    printf("\n co %d so chan trong danh sach", demChan);
    printf("\n co %d so le trong danh sach", demLe);
    printf("\n co %d so am trong danh sach", demAm);
    printf("\n co %d so duong trong danh sach", demDuong);
    return 1;
}

//tinh trung binh cong cac phan tu trong danh sach
int tinh_TungBinh(list l){
    //kiem tra danh sach rong
    if(isSempty(l)){
        printf("\ndanh sach nay dang rong ");
        return 0;
    }
    //tinh trung binh cong
    int i, tongDS = 0;
    float tbc = 0;
    for(i = 0; i < l.count; i++){
        tongDS = tongDS + l.elems[i];
    }
    tbc = (float)tongDS / (float)l.count;
    printf("\ntong trung binh cong cua danh sach la: %.3f", tbc);
    return 1;
}

//tinh trung binh cong cac so chan le am duong trong danh sach
int TBC_chanLeAmDuong(list l){
//kiem tra danh sach rong
    if(isSempty(l)){
        printf("\ndanh sach nay dang rong ");
        return 0;
    }
    //thuc hien tinh tong va dem
    int i;
    int  demChan = 0, demLe = 0, demAm = 0, demDuong = 0; //khai bao bien dem
    int  tongChan = 0, tongLe = 0, tongAm = 0, tongDuong = 0; //khai bao bien tinh tong
    float tbChan = 0, tbLe = 0, tbAm = 0, tbDuong = 0;      //khai bao bien trung binh cong
    for(i = 0; i < l.count; i++){
        //tong so chan
        if(l.elems[i] > 0 && l.elems[i] % 2 == 0){
            tongChan = tongChan + l.elems[i];
            demChan++;
        }
        //tong so le
        if(l.elems[i] > 0 && l.elems[i] % 2 == 1){
            tongLe = tongLe + l.elems[i];
            demLe++;
        }
        //tong so am
        if(l.elems[i] < 0){
            tongAm = tongAm + l.elems[i];
            demAm++;
        }
        //tong so duong
        if(l.elems[i] > 0){
            tongDuong = tongDuong + l.elems[i];
            demDuong++;
        }
    }
    printf("\ntong chan: %d", tongChan);
    printf("\ntong le: %d", tongLe);
    printf("\ntong am: %d", tongAm);
    printf("\ntong duong: %d", tongDuong);
    //tinh trung binh cong
    tbChan = (float)(tongChan) / (float)(demChan) ;
    tbLe = float(tongLe) / float(demLe) ;
    tbAm = float(tongAm) / float(demAm) ;
    tbDuong = float(tongDuong) / float(demDuong) ;

    //in ra man hinh
    printf("\n trung binh cong cua so chan trong danh sach la: %.3f", tbChan);
    printf("\n trung binh cong cua so le trong danh sach la: %.3f", tbLe);
    printf("\n trung binh cong cua so am trong danh sach la: %.3f", tbAm);
    printf("\n trung binh cong cua so duong trong danh sach la: %.3f", tbDuong);
    return 1;
}

int main(){
    item x;
    int k;
    list danhsach;
    init(danhsach);
    inPut(danhsach);
    outPut(danhsach);
    printf("\nnhap vao gia tri x dua ra vi tri trong danh sach: ");
    scanf("%d", &x);
    k = search(danhsach, x);
    if(k){  // truong hop k >= 1 khi search tim ra va tra ve ket qua khac 0
        printf("\nvi tri cua %d trong danh sach la: %d", x, k);
    }else{  // truong hop k = 0 khi search khong tim ra va tra ve ket qua  0
        printf("\nkhong tim thay gia tri %d trong danh sach", x);
    }
    insert_viTri_p(&danhsach, x,k);
    outPut(danhsach); 
    xoa_pt_Thu_k(&danhsach,&x,k);
    outPut(danhsach);
    //xoa_phanTu_x(&danhsach,x); //loi ro loi roi
    //outPut(danhsach);
    //Xoa_X(&danhsach,x);
    //outPut(danhsach);
    dem_chanLeAmDuong(danhsach);
    tinh_TungBinh(danhsach);
    TBC_chanLeAmDuong(danhsach);
    return 0;
}
