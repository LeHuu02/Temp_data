#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef int item;

typedef struct{
	item Elems[N]; 
	int size; 
}List;
//Ham khoi tao
void Init(List &L){
	L.size = 0; 
}
// Ham nhap du lieu
void Input(List &L){
	printf("Nhap vao so phan tu danh sach: ");
	scanf("%d", &L.size);
	int i;
	for(i = 0; i < L.size; i++){
		printf("Nhap phan tu thu %d: ", i+1);
		scanf("%d", &L.Elems[i]);
	}	
}
//Ham hien thi
void Output(List L){
	printf("\n Danh sach cac phan tu la: \n");
	int i; 
	for(i = 0; i < L.size; i++){
		printf("%d ", L.Elems[i]);
	}
}
//Ham tim kiem
int Search (List L, item x)
{
    int i;
    for (i=0; i<L.size; i++)
        if (L.Elems[i] == x)
            return i+1;
    return 0;
}
//Ham chen vao vi tri k
int Insert_k (List *L, item x, int k)
{
    if ((*L).size==N) 
    {
        printf("Danh sach day !");
        return 0;
    }
    printf("\n Nhap Vi tri chen!\n");
    scanf ("%d",&k);
    if (k<1 || k>(*L).size+1)
    {
        printf("Vi tri chen khong hop le !\n");
        return 0;
    }
    printf ("\n Nhap gia tri can chen: ");
     scanf ("%d",&x);
    int i;
    for (i = (*L).size; i >= k; i--)
        (*L).Elems[i] = (*L).Elems[i-1];
    (*L).Elems[k-1]=x;
    (*L).size++;
    return 1;
}
//Ham xoa ra khoi vi tri k
int Xoa_k (List *L, int k)
{ 
if((*L).size==0)
  {
  	printf("Ds rong");
  	return 0;
  	}
printf("\n Nhap vi tri can xoa:");
scanf("%d",&k);
if (k<1 || k>(*L).size)
{
 printf("Vi tri xoa khong hop le !");
 return 0;
 }
 //*x=(*L).Elems[k-1]; //luu lai gia tri cua phan tu can xoa
 int i;
    for (i=k-1; i<(*L).size-1; i++) 
	(*L).Elems[i]=(*L).Elems[i+1];
	(*L).size--; 
	return 1;
}
//Ham xoa phan tu x
int Xoa_x(List *L, item x)
{
	if ((*L).size==0)
	{
	printf("Danh sach rong !");
	return 0;
		}
			printf("Nhap gia tri can xoa:");
			scanf("%d",&x);
			int v = Search(*L,x);
			if (!v)
			{
			printf("Danh sach khong co %d",x);
			return 0;
			}
	do
	{
		for (int i=v-1; i<(*L).size-1; i++)
			(*L).Elems[i]=(*L).Elems[i+1];
		(*L).size--;
		v = Search(*L,x);
	}
	while (v);
	return 1;
}
//Ham dem so chan
int Dem_chan(List L)
 {
 	int d=0;
 	for(int i=0; i<L.size; i++)
 		{
 			if(L.Elems[i]%2==0)
 			d++;
 		}
 	if (d>0)
 	printf("\n DS co %d so phan tu chan",d);
 	else printf ("\n DS khong co so chan");
}
//chuong trinh chinh
int main() {
	item x;
	int k;
	List danhsach;
	Init(danhsach);
	Input(danhsach);
	Output(danhsach);
	printf ("\n Moi ban nhap vao phan tu can tim: ");
    scanf("%d",&x);
    k=Search(danhsach,x);
    if (k) printf ("\n Tim thay %d trong DS tai vi tri thu: %d",x,k);
    else printf ("Khong tim thay %d trong danh sach !",x);
	if(Insert_k(&danhsach,x,k));
	Output(danhsach);
	Xoa_k(&danhsach,k);
	Output(danhsach);
	Xoa_x(&danhsach,k);
	Output(danhsach);
	Dem_chan(danhsach);
	return 0;
}
