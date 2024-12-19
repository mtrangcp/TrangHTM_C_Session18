#include <stdio.h>

struct SinhVien{
	char name[50];
	int age;
	char phoneNumber[15];
};

int main(){
	struct SinhVien sv[5] ;	
	
	for ( int i = 0; i< 5; i++){
		printf("\nNhap ten: ");
		fgets( sv[i].name, sizeof( sv[i].name), stdin);
		printf("Nhap tuoi: ");
		scanf("%d", &sv[i].age);
		fflush(stdin);
		printf("Nhap sdt: ");
		fgets( sv[i].phoneNumber, sizeof( sv[i].phoneNumber), stdin);
	}
	
	for ( int i = 0; i<5 ; i++){
		printf("\nSV %d", i+1);
		printf("\nTen: %s", sv[i].name);
		printf("Tuoi: %d", sv[i].age);
		printf("\nSdt: %s ", sv[i].phoneNumber);
	}
	
	return 0;
}

