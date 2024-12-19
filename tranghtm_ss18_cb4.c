#include <stdio.h>

struct SinhVien{
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
};

int main(){
	struct SinhVien sv[50] ;	
	
	for ( int i = 0; i< 5; i++){
		sv[i].id = i+1 ;
		printf("\nNhap ten: ");
		fgets( sv[i].name, sizeof( sv[i].name), stdin);
		printf("Nhap tuoi: ");
		scanf("%d", &sv[i].age);
		fflush(stdin);
		printf("Nhap sdt: ");
		fgets( sv[i].phoneNumber, sizeof( sv[i].phoneNumber), stdin);
	}
	
	for ( int i = 0; i<5 ; i++){
		printf("\nID: %d", sv[i].id);
		printf("\nTen: %s", sv[i].name);
		printf("Tuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
	
	return 0;
}

