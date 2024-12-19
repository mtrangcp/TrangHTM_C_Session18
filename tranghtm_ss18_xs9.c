#include <stdio.h>
#include <string.h>

typedef  struct {
	int id;
	char name[50];
	float price;
}Dish;

void show( Dish menu[], int n);
void add( Dish menu[], int *n);
void update( Dish menu[], int n);
void del( Dish menu[], int *n);
void sort( Dish menu[], int n);
void search( Dish menu[], int n);

int main(){
	Dish menu[100] = {
        { 1, "com tam", 30 },	
        { 2, "banh mi", 40  },	
        { 3, "pho ga", 35  },
        { 4, "bb hue", 60  },
        { 5, "buch", 55  },
    };
    
    int choice, n = 5;
    
    do {
    	printf("\n\n---------Menu-----------");
    	printf("\n1. In mon an ");
    	printf("\n2. Them ");
    	printf("\n3. Sua ");
    	printf("\n4. Xoa ");
    	printf("\n5. Sap xep ");
    	printf("\n6. Tim kiem ");
    	printf("\n7. Thoat ");
    	printf("\nLua chon cua ban:  ");
    	scanf("%d", &choice);
    	fflush(stdin);
    	
    	switch( choice){
    		case 1:{
    			show(menu, n);
				break;
			}
			case 2:{
				add(menu, &n);
				break;
			}
			case 3:{
				update(menu, n);
				break;
			}
			case 4:{
				del(menu, &n);
				break;
			}
			case 5:{
				sort(menu, n);
				break;
			}
			case 6:{
				search(menu, n);
				break;
			}
			case 7:{
				printf("\nBan chon thoat!");
				break;
			}
			default:{
				printf("\nVui long chon dung(1-7)!");
				break;
			}
		}
	}while( choice != 7 );

	return 0;
}

void show( Dish menu[], int n){
	printf("\nPhan tu trong mang: \n");
	for ( int i = 0; i< n; i++){
		printf("\n %d. %s: %.2f ", menu[i].id, menu[i].name, menu[i].price );
	}	
}

void add( Dish menu[], int *n){
	int index;
	printf("\nVi tri them(1 - %d): ", *n+1);
	scanf("%d", &index);
	
	while ( index < 1 || index > (*n)+1 ){
		printf("\nVui long nhap dung!");
		printf("\nVi tri them(1 - %d): ", (*n)+1);
		scanf("%d", &index);
	}
	fflush(stdin);
	
	// chuyen ptu
	for ( int i = *n; i>= index ; i--){
		menu[i].id = menu[i-1].id +1;
		strcpy( menu[i].name, menu[i-1].name);
		menu[i].price = menu[i-1].price;
	}
	
	// nhap  va them
	menu[index-1].id = index ;
	printf("\nNhap ten mon: ");
	fgets( menu[index-1].name, sizeof( menu[index-1].name), stdin);
	int len = strlen(menu[index-1].name);
	menu[index-1].name[len-1] = '\0';
	
	printf("Nhap gia: ");
	scanf("%f", &menu[index-1].price);
	fflush(stdin);
	
	(*n)++;
	printf("\nKet qua: \n");
	for ( int i = 0; i< *n ; i++){
		printf("\n %d. %s: %.2f ", menu[i].id, menu[i].name, menu[i].price );
	}
}

void update( Dish menu[], int n){
	int index;
	printf("\nVi tri sua(1 - %d): ", n);
	scanf("%d", &index);
	
	while ( index < 1 || index > n ){
		printf("\nVui long nhap dung!");
		printf("\nVi tri sua(1 - %d): ", n);
		scanf("%d", &index);
	}
	fflush(stdin);
	// nhap  va sua
	menu[index-1].id = index ;
	printf("\nNhap ten mon: ");
	fgets( menu[index-1].name, sizeof( menu[index-1].name), stdin);
	int len = strlen(menu[index-1].name);
	menu[index-1].name[len-1] = '\0';
	
	printf("Nhap gia: ");
	scanf("%f", &menu[index-1].price);
	fflush(stdin);
	
	printf("\nKet qua: \n");
	for ( int i = 0; i< n; i++){
		printf("\n %d. %s: %.2f ", menu[i].id, menu[i].name, menu[i].price );
	}
}

void del( Dish menu[], int *n){
	int index;
	printf("\nVi tri xoa(1 - %d): ", *n);
	scanf("%d", &index);
	
	while ( index < 1 || index > *n ){
		printf("\nVui long nhap dung!");
		printf("\nVi tri them(1 - %d): ", *n );
		scanf("%d", &index);
	}
	fflush(stdin);
	
	// chuyen ptu
	for ( int i = index-1 ; i < (*n)-1  ; i++){
		menu[i].id = menu[i+1].id ;
		strcpy( menu[i].name, menu[i+1].name);
		menu[i].price = menu[i+1].price;
	}
	
	(*n)--;
	printf("\nKet qua: \n");
	for ( int i = 0; i< *n ; i++){
		printf("\n %d. %s: %.2f ", menu[i].id, menu[i].name, menu[i].price );
	}
}

void sort( Dish menu[], int n){
	char choice;
	do{
		printf("\na. Giam dan theo price");
		printf("\nb. Tang dan theo price");
		printf("\nMoi chon: ");
		scanf("%c", &choice);
	}while( choice != 'a' && choice != 'b');
	
	if ( choice == 'a' ){
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( menu[j].price < menu[j+1].price ){
					Dish temp = menu[j];
	                menu[j] = menu[j+1];
	                menu[j+1] = temp;
				}
			}
		}
	}else{
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( menu[j].price > menu[j+1].price ){
					Dish temp = menu[j];
	                menu[j] = menu[j+1];
	                menu[j+1] = temp;
				}
			}
		}
	}
	printf("\nKet qua: \n");
	for ( int i = 0; i< n ; i++){
		printf("\n %d. %s: %.2f ", menu[i].id, menu[i].name, menu[i].price );
	}
}

void search( Dish menu[], int n){
	char input[50];
	int count = 0;
	char choice;
	do{
		printf("\na. Tim kiem tuyen tinh");
		printf("\nb. Tim kiem nhi phan");
		printf("\nMoi chon: ");
		scanf("%c", &choice);
	}while( choice != 'a' && choice != 'b');
	fflush(stdin);
	
	printf("\nNhap ten can tim: ");
	fgets( input, 50, stdin);
	int len = strlen(input);
	input[len-1] = '\0';
	
	if (choice == 'a' ){
		// tuyen tinh
		for ( int i = 0; i< n; i++){
			if ( strcmp(menu[i].name, input) == 0 ){
				count = 1;
				printf("\nMon can tim: ");
				printf("\n %d. %s: %.2f ", menu[i].id, menu[i].name, menu[i].price );
				break;
			}
		}
	}else{
		// nhi phan
		for (int i = 0; i < n ; i++) {
	        for (int j = 0; j < n-i-1; j++) {
	            if (strcmp(menu[j].name, menu[j+1].name) > 0) {
	                Dish temp = menu[j+1];
	                menu[j+1] = menu[j];
	                menu[j] = temp;
	            }
	        }
	    }
		int left = 0, right = n - 1 ;
	    while (left <= right) {
	        int mid = (right + left) / 2;
	        if (strcmp(menu[mid].name, input) == 0) {
	        	count = 1;
	            printf("\nMon can tim: ");
				printf("\n %d. %s: %.2f ", menu[mid].id, menu[mid].name, menu[mid].price );
				break;
	        } else if (strcmp(menu[mid].name, input) < 0) {
	            left = mid + 1;
	        } else {
	            right = mid - 1;
	        }
	    }
	}

	if ( count == 0 ) printf("\n Khong tim thay mon an!");
}





