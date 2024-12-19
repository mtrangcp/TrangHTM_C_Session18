#include <stdio.h>
#include <string.h>

typedef  struct {
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
}SinhVien;

void insert( SinhVien sv[], int n );

int main(){
	SinhVien sv[50] = {
        { 1, "an", 3 , "0123456789" },	
        { 2, "lin", 4 , "0123456789" },	
        { 3, "pe", 3 , "0123456789" },
        { 4, "han", 6 , "0123456789" },
        { 5, "bin", 7 , "0123456789" },
    };
    
	insert(sv, 5);
	
	return 0;
}

void insert( SinhVien sv[], int n ){
	int index;
	printf("\nVi tri chen(1 - %d): ", n+1);
	scanf("%d", &index);
	
	while ( index < 1 || index > n+1 ){
		printf("\nVui long nhap dung!");
		printf("\nVi tri chen(1 - %d): ", n+1);
		scanf("%d", &index);
	}
	fflush(stdin);
	
	// chuyen ptu
	for ( int i = n; i>= index ; i--){
		sv[i].id = sv[i-1].id +1;
		strcpy( sv[i].name, sv[i-1].name);
		sv[i].age = sv[i-1].age;
		strcpy( sv[i].phoneNumber, sv[i-1].phoneNumber );
	}
	
	// nhap  va chen
	sv[index-1].id = index ;
	printf("\nNhap ten: ");
	fgets( sv[index-1].name, sizeof( sv[index-1].name), stdin);
	int len = strlen(sv[index-1].name);
	sv[index-1].name[len-1] = '\0';
	
	printf("Nhap tuoi: ");
	scanf("%d", &sv[index-1].age);
	fflush(stdin);
	printf("Nhap sdt: "); 
	fgets( sv[index-1].phoneNumber, sizeof( sv[index-1].phoneNumber), stdin);

	printf("\nKet qua: \n");
	for ( int i = 0; i<n+1 ; i++){
		printf("\n\nID: %d", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("\nTuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
		
}

