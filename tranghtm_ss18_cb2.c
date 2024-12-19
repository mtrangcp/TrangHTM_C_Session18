#include <stdio.h>

struct SinhVien{
	char name[50];
	int age;
	char phoneNumber[15];
};

int main(){
	struct SinhVien sv ;	
	
	printf("\nNhap ten: ");
	fgets( sv.name, sizeof( sv.name), stdin);
	printf("Nhap tuoi: ");
	scanf("%d", &sv.age);
	fflush(stdin);
	printf("Nhap sdt: ");
	fgets( sv.phoneNumber, sizeof( sv.phoneNumber), stdin);
	
	
	
	printf("\nTen: %s", sv.name);
	printf("Tuoi: %d", sv.age);
	printf("\nSdt: %s ", sv.phoneNumber);

	return 0;
}

