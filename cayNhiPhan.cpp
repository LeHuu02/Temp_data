#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
	int data;
	node *trai;
	node *phai;
};
typedef node *tree;

void init(tree &t){
	t = NULL;
}

//tao node
node *make(node *p, int x){
	p = (node*)malloc(sizeof(node));
	p->data = x;
	p->trai = p->phai = NULL;
	return p;
}

//ham nhap
node *nhap(node*p, int x){
	printf("node = ");
	scanf("%d", &x);
	if(x== 0)
		return 0;
	p = make(p,x);	
	printf("\t con trai node %d \n", x);
	p->trai = nhap(p,x);
	printf("\t con phai node %d \n", x);
	p->phai = nhap(p,x);
	return p;
}

//ham duyet 
void duyet_truoc(tree t){
	node *duyet = t;
	if(duyet != NULL){
		printf("\t%d", duyet->data);
		duyet_truoc(duyet->trai);
		duyet_truoc(duyet->phai);
	}
}

void duyet_giua(tree t){
	node *duyet = t;
	if(duyet != NULL){
		duyet_giua(duyet->trai);
		printf("\t%d", duyet->data);
		duyet_giua(duyet->phai);
	}
}

void duyet_sau(tree t){
	node *duyet = t;
	if(duyet != NULL){
		duyet_sau(duyet->trai);
		duyet_sau(duyet->phai);
		printf("\t%d", duyet->data);
	}
}

int main(){
	tree t;
	node*p; 
	int x;
	init(t);
	printf("\t\t nhap 0 de chuyen sang nhap node khac hoac thoat\n");
	t = nhap(p,x);
	int chon;
	printf("\t\t1: duyet truoc\t 2: duyet giua\t3: duyet sau \t4: break\n");
	do{
		printf("ban chon: ");
		scanf("%d", &chon);
		switch(chon){
			case 1:{
				printf("ket qua duyet truoc: ");
				duyet_truoc(t);
				printf("\n");
				break;
			}
			case 2:{
				printf("ket qua duyet giua: ");
				duyet_giua(t);
				printf("\n");
				break;
			}
			case 3:{
				 printf("ket qua duyet sau: ");
				 duyet_sau(t);
				 printf("\n");
				break;
			}
			case 4:
				break;
		}
		getch();
	}while(chon !=4);
	return 0;
}




