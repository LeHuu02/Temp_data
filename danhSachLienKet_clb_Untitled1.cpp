#include <stdio.h>
#include <stdlib.h>

typedef int item; // dinh nghia item 

struct Node{
	item Data;
	Node *Next;
};
typedef Node *List; //dinh nghia danh sach

//Khoi tao rong
void init (List &L){
	L=NULL;
}
//Kiem tra rong
int isempty (List L){
	return (L==NULL);
}
//Tinh do dai 
int len(List L){
	Node *P=L;
	int i=0;
	while (P!=NULL){
		i++;
		P=P->Next;
	}
	return i;
}
//tao nut
Node *Make_Node (Node *P,item x){
	P = (Node *) malloc (sizeof (Node));
	P->Next = NULL;
	P->Data =x;
	return P;
}

//Ham chen dau
void Insert_first(List &L,item x){
	Node *P;
	P =Make_Node(P,x);
	P->Next = L;
	L = P;
}
//ham chen vao vi tri
void insert_k(List &L, item x,int k){
	Node *P,*Q = L;
	int i=1;
	if(k<1 || k> len(L)+1){
		printf("Vi tri chen khong hop le!");
	}else{
		P=Make_Node(P,x);
		if(k==1){
			Insert_first(L,x);
		}else{
			while (Q!= NULL && i != k-1){
				i++;
				Q=Q->Next;
			}	
			P->Next = Q->Next;
			Q->Next =P;
		}
	}
}
//Tim kiem 
int Search (List L,item x){
	Node *P = L;
	int i=1;
	while (P!= NULL && P->Data != x){
		P=P->Next;
		i++;
	}
	if(P!= NULL){
		return i;
	}else{
		return 0;
	}
}
// Xoa phan tu dau
void Del_frist (List &L,item &x){
	x = L->Data;
	L = L->Next;
}
//xoa phan tu khoi vi tri
void Del_k (List &L,item &x,int k){
	Node *P = L;
	int i=1;
	if(k<1 || k>len(L)){
		printf("Vi tri chen khong hop le!");
	}else{
		if(k==1){
			Del_frist(L,x);
		}else{
			while(P != NULL && i!=k-1){
				P=P->Next;
				i++;
			}
			P->Next = P->Next->Next;
		}
	}
}
//xoa x ra khoi danh sách
void Del_x (List &L,item x){
	while (Search(L,x)){
		Del_k(L,x,Search(L,x));
	}
}
//Hamnhap
void Input(List &L){
	int i=0;
	item x;
	do{
		i++;
		printf("Nhap phan tu thu %d: ",i);
		scanf("%d",&x);
		if(x!=0){
			insert_k(L,x,len(L)+1);
		}
	}while(x != 0);
}
//Ham xuat
void output(List L){
	Node *P = L;
	while (P!= NULL){
		printf("%5d",P->Data);
		P = P->Next;
	}
	printf("\n");
}
int main(){
	List L;
	init(L);
	Input(L);
	output(L);
	int lua_chon;
	printf("Nhap phep toan vs danh sach LK");
	printf("\n1: Kiem tra danh sach rong");
	printf("\n2: Do dai danh sach ");
	printf("\n3: Chen phan tu x vao vi tri k trong DS");
	printf("\n4: Tim mot phan tu t?ng danh sach");
	printf("\n5: Xoa phan tu tai vi tri k");
	printf("\n6: Xoa phan tu x trong danh sach");
	printf("\n7: Thoat");
	do{
		printf("\n Ban chon: ");
		scanf("%d",&lua_chon);
		switch(lua_chon){
			case 1:{
				if(isempty(L)){
					printf("DS rong");
				}else{
					printf("DS khong rong");
				}
				break;
			}
			case 2:{
				printf("Do dai cua DS la: %d",len(L));
				break;
			}
			case 3:{
				item x;
				int k;
				printf("Nhap phan tu can chen vao DS:");
				scanf("%d",&x);
				printf("Nhap vi tri can chen: ");
				scanf("%d",&k);
				insert_k(L,x,k);
				printf("DS sau khi chen: \n");
				output(L);
				break;
			}
			case 4:{
				item x;
				printf("Nhap phan tu can tim:");
				scanf("%d",&x);
				int k = Search(L,x);
				if(k){
					printf("Tim thay %d trong DS tai vi tri thu: %d",x,k);
				}else{
					printf("Khong tim thay %d",x);
				}
				break;
			}
			case 5:{
				int k;
				item x;
				printf("Nhap vi tri can xoa:");
				scanf("%d",&k);
				Del_k(L,x,k);
				printf("DS sau khi xoa: \n");
				output(L);
				break;
			}
			case 6:{
				item x;
				printf("Nhap phan tu can xoa:");
				scanf("%d",&x);
				Del_x(L,x);
				printf("DS sau khi xoa: \n");
				output(L);
				break;
			}
			case 7:
				break;
		}
	}while(lua_chon !=7);
	return 0;
}
