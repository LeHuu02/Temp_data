//LE MINH HUU - KTMT K19A - 7/4/2022 - fix OK
/*
DE BAI: 
		Cho 1 cây NPTK ch?a các s? nguyên.
		Yêuc?u:
		
		–Bi?u di?n cây b?i con tr?.
		–Nh?p d? li?u cho cây.
		–Hi?n th? d? li?u trên cây: theo th? t? tru?c, gi?a, sau.
		–Tìm ki?m 1 d?nh có khóa x trên cây
		–Thêm m?t khóa x vào cây sao cho sau khi thêm cây v?n là cây NPTK.
		–Xóa d?nh có khóa x ra kh?i cây cho sau khi xóa cây v?n là cây NPTK.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int TData;
//cau truc cua node
struct TNode{
	TData Data;
	TNode* Left;
	TNode* Right;
};
//cau truc cay
typedef TNode *TTree;
//khoi tao cay rong
void MakeNullTree(TTree *T){
	(*T) = NULL;
}
//xac dinh con trai
TTree LeftChild(TTree n){
	if (n != NULL)
		return n->Left;
	else
		return NULL;
}
//xac dinh con phai
TTree RightChild(TTree n){
	if(n != NULL)
		return n->Right;
	else
		return NULL;
}
//duyet tien to
void PreOrder(TTree T){
	printf("%d  ", T->Data);
	if(LeftChild(T)!=NULL)
		PreOrder(LeftChild(T));
	if(RightChild(T)!=NULL)
		PreOrder(RightChild(T));
}

//duyet trung to
void InOrder(TTree T){
	if(LeftChild(T)!=NULL)
		InOrder(LeftChild(T));
	printf("%d  ", T->Data);
	if(RightChild(T)!=NULL)
		InOrder(RightChild(T));
}

//duyet hau to
void PosOrder(TTree T){
	if(LeftChild(T)!=NULL)
		PosOrder(LeftChild(T));
	if(RightChild(T)!=NULL)
		PosOrder(RightChild(T));
	printf("%d  ", T->Data);
}

//thu tuc them 1 khoa vao cay tim kiem nhi phan
void InsertNode(TTree *Root, TData x){
	if(*Root == NULL){//them nut moi chua khoa x
		(*Root) = (TNode*)malloc(sizeof(TNode));
		(*Root)->Data = x;
		(*Root)->Left = NULL;
		(*Root)->Right = NULL;
	}
	//DE Y DOAN NAY NHA -  LE MINH HUU
	else if(x < (*Root)->Data)
		InsertNode(&(*Root)->Left, x);
	else if(x > (*Root)->Data)
		InsertNode(&(*Root)->Right, x);
}

//nhap cac node vao cay
void Tree(TTree*k){
	int x;
	printf("nhap vao cac phan tu trong cay nhi phan tim kiem.\n");
	printf("nhap so 0 thi ket thuc: ");
	do{
		scanf("%d", &x);
		if(x != 0)
			InsertNode(&*k,x);
	}while(x !=0);
}

//ham tim kiem nhi phan neu tim thay tra ve 1 nguoc lai 0
int Search(TTree Root, TData x){
	if (Root == NULL)
		return 0;
	else if(Root->Data ==x)
		return 1;
	else if(Root->Data <x)
		return Search(Root->Right,x);
	else
		return Search(Root->Left,x);
}

//xoa mot node x trong cay
int delKey(TTree &T, TData x)     // xoa nut co key x
{
    if (T==NULL) return 0;
    else if (T->Data > x) return delKey(T->Left, x);
    else if (T->Data < x) return delKey(T->Right, x);
    else // T->key == x
    {
        if (T->Left == NULL) T = T->Right;    // Node chi co cay con phai
        else if (T->Right == NULL) T = T->Left;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
            TNode *Q = T->Left;
            while (Q->Right != NULL)
            {
                Q = Q->Right;
            }
            T->Data = Q->Data;
            delKey(T->Left, Q->Data);
        }
    }
    return 1;
}
//LE MINH HUU - KTMT K19A - 7/4/2022 - fix OK

int main(){
	TTree T;
	int n,x,a;
	MakeNullTree(&T);
	Tree(&T);
	printf("\ngia tri cua cay truoc khi duye NLR, \n");
	PreOrder(T);
	printf("\ngia tri cua cay truoc khi duye LNR, \n");
	InOrder(T);
	printf("\ngia tri cua cay truoc khi duye LRN, \n");
	PosOrder(T);
	
	printf("\nban muon tim phan tu gi trong cay? ");
	scanf("%d", &n);
	if(Search(T,n) == 0)
		printf("\nPhan tu %d khong co trong cay tim kiem.\n", n);
	else
		printf("\nPhan tu %d co trong cay nhi phan tim kiem.\n");
	printf("\nnhap gia tri can them: ");
	scanf("%d", &x);
	InsertNode(&T,x);
	printf("\ngia tri cua cay khi duyet LNR lai.\n");
	InOrder(T);
	printf("\nnhap gia tri can xoa: ");
	scanf("%d", &a);
	if (delKey(T, a))
		 printf("Xoa thanh cong\n");
	InOrder(T);
	getch();		
		//LE MINH HUU - KTMT K19A - 7/4/2022 - fix OK
	return 0;
}


