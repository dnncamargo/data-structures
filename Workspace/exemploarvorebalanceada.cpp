#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

 typedef struct avlNo {
	int info;
	struct avlNo *left;
	struct avlNo *right;
	int fatBal;
} AvlNo;  

bool status = false;

void createNode (AvlNo * &root, int elem) {
	root = new avlNo;
	root-> info = elem;
	root-> left = NULL;
	root-> right = NULL;
	root-> fatBal = 0;
}

void rotRRRL (AvlNo * a, bool &status) {
	printf("rot RR");
	avlNo *b, *c;
	b = a-> left;
	if (b-> fatBal == -1) { // rotacao simples
		printf(" simple\n");
		a-> left = b-> right;
		b-> right = a;
		a-> fatBal = 0;
		a = b;
	}
	else { // rotacao dupla
			printf(" double\n");
			c = b-> right;
			b-> right = c-> left;
			c-> left = b;
			a-> left = c-> right;
			c-> right = a;
			if (c-> fatBal == -1)
					a-> fatBal = 1;
			else a-> fatBal = 0;
			
			if (c-> fatBal == 1)
					b-> fatBal = -1;
			else b-> fatBal = 0;
			a = c;
		}
		a-> fatBal = 0;
		status = false;
}

void rotLLLR (AvlNo * a, bool &status) {
		printf("rot LL\n");
		AvlNo * b, * c;
		b = a-> right;
		if (b-> fatBal == 1) { // rotacao simples
			a-> right = b-> left;
			b-> left = a;
			a-> fatBal = 0;
			a = b;
		}
			else { // rotacao dupla
					c = b-> left;
					b->left = c-> right;
					c-> right = b;
					a-> right = c-> left;
					c-> left = a;
					if (c-> fatBal == 1)
						a-> fatBal = -1;
						else a-> fatBal = 0;
					if (c-> fatBal == -1)
						b-> fatBal = 1;
					else
						b-> fatBal = 0;
						a = c;
				}
				a-> fatBal = 0;
				status = false;
}

void insertAvl (AvlNo * &root, int elem, bool &status) {
	if (root == NULL) {
		createNode(root, elem);
		status = true;
	} else if (elem == root-> info) {
			printf ("Elemento repetido.: %d \n", elem);
			return;
	} else if (elem < root-> info) {
		insertAvl(root-> left, elem, status);
		if (status) {
			switch (root-> fatBal) {
				case 1 : root-> fatBal = 0; status = false; break;
				case 0 : root-> fatBal = -1; break;
				case -1 : rotLLLR(root, status); break;
			}
			printf("fatBal: %d\n", root-> fatBal);
			}
	} else {
		insertAvl(root-> right, elem, status);
		if (status){
			switch (root-> fatBal) {
				case -1 : root-> fatBal = 0; status = false; break;
				case 0 : root-> fatBal = 1; break;
				case 1 : rotRRRL(root, status); break;
			}
			printf("fatBal: %d\n", root-> fatBal);
		}
	}
}

void printAvl(AvlNo * root) {
    if(root != NULL) {
		printf("enter left\n");
        printAvl(root-> left);

		printf("show info\n");
		printf("%d\n", root-> info);

		printf("enter right\n");
        printAvl(root-> right);

    }
}


int main(){
	AvlNo * root = NULL;

	int op;
	while (true) {
		scanf("%d", &op);
		switch (op) {
		case 1:
			int value;
			printf("insert node: ");
			scanf("%d", &value);
			insertAvl(root, value, status);
			break;
		case 2:
			printAvl(root);
			break;
		default:
			return 0;
		}

	}
	return 0;
}
	
	
	
