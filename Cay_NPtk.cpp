// cay nhi phan
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef int TData;

struct TNode {
	TData Data;
	TNode *Left;
	TNode *Right;
};
typedef TNode *TTree;
//Khoi tao cay rong

void Makenull(TTree *T)
{
	(*T)=NULL;
}
//xac dinh con trai
TTree LeftChild(TTree n){
	if (n!=NULL){
		return n->Left;
	}else{
		return NULL;
	}
}
//xac dinh con phai
TTree RightChild(TTree n){
	if(n!=NULL){
		return n->Right;
	}else{
		return NULL;
	}
}
//duyet tien to
void PreOrder(TTree T){
	printf("%d\t",T->Data);
	if(LeftChild(T)!=NULL){
		PreOrder(LeftChild(T));
	}
	if(RightChild(T)!=NULL){
		PreOrder(RightChild(T));
	}
}
//duyet trung to
void InOrder(TTree T){
	if(LeftChild(T)!=NULL){
		InOrder(LeftChild(T));
	}printf("%d\t",T->Data);
	if(RightChild(T)!=NULL){
		InOrder(RightChild(T))	;
	}
}
//Duyet hau to
void PosOrder(TTree T){
	if(LeftChild(T)!=NULL){
		InOrder(LeftChild(T));
	}
	if(RightChild(T)!=NULL){
		InOrder(RightChild(T))	;
	}
	printf("%d\t",T->Data);
}
//thu tuc them 1 khoa vao cay nhi phan tim kiem
void InsertNode (TTree *Root,TData x){
	if(*Root == NULL){
		(*Root)=(TNode*)malloc(sizeof(TNode));
		(*Root)->Data =x;
		(*Root)->Left =NULL;
		(*Root)->Right=NULL;
	}else{
		if(x<(*Root)->Data){
			InsertNode(&(*Root)->Left,x);
		}else
		if(x>(*Root)->Data){
			InsertNode(&(*Root)->Right,x);
		}		
	}
}
//nhap
void Tree(TTree *k)
{
	int x;
	printf("nhap cac phan tu co trong cay tim kiem\n");
	printf("Nhap 0 de ket thuc:");
	do{
		scanf("%d",&x);
		if(x!=0){
			InsertNode(*&k,x);
		}
	}while(x!=0);
}
int Search(TTree Root,TData x){
	if(Root ==NULL){
		return 0;
	}else
	if(Root->Data ==x){
		return 1;
	}else
	if(Root->Data <x){
		return Search(Root->Right,x);
	}else{
		return Search(Root->Left,x);
	}
}
//
int main(){
	TTree T;
	int n,x;
	Makenull(&T);
	Tree(&T);
	printf("\nGia tri cua cay khi duyet NLR \n");
	PreOrder(T);
	printf("\nGia tri cua cay khi duyet LNR \n");
	InOrder(T);
	printf("\nGia tri cua cay khi duyet LRN \n");
	PosOrder(T);
	printf("Nhap phan tu muon tim kiem: ");
	scanf("%d",&n);
	if(Search(T,n)==0){
		printf("khong co phan tu nay!");
	}else{
		printf("co phan tu %d trong cay",n);
	}
	printf("Nhap gia tri can them: ");
	scanf("%d",&x);
	InsertNode(&T,x);
	printf("Gia tri cua cay sau khi duyet LNR lai.\n");
	InOrder(T);
	getch();
}

