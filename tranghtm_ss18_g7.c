#include <stdio.h>
#include <string.h>

typedef  struct {
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
}SinhVien;

void del( SinhVien sv[], int n );

int main(){
	SinhVien sv[50] = {
        { 1, "an", 3 , "0123456789" },	
        { 2, "lin", 4 , "0123456789" },	
        { 3, "pe", 3 , "0123456789" },
        { 4, "han", 6 , "0123456789" },
        { 5, "bin", 7 , "0123456789" },
    };
    
	del(sv, 5);
	
	return 0;
}

void del( SinhVien sv[], int n ){
	int count = 0, index;
	char input[50];
	
	printf("\nNhap ten muon xoa: ");
	fgets( input, 50, stdin);
	int len = strlen(input);
	input[len-1] = '\0';
	
//	printf("\nten: %s", input);
//	printf("\ndo dai: %d", strlen(input));
	
	for ( int i = 0; i< n; i++){
		if ( strcmp(sv[i].name , input) ==  0 ){
			count = 1;
			index = i;
			break;
		}
	}
	if ( count == 0 ){
		printf("\n Khong ton tai ten can tim!");
	}else{
		for ( int i = index; i<n-1 ; i++){
			sv[i].id = sv[i+1].id;
			strcpy( sv[i].name, sv[i+1].name);
			sv[i].age = sv[i+1].age;
			strcpy( sv[i].phoneNumber, sv[i+1].phoneNumber );
		}
		
		n--;
		printf("\nKet qua: \n");
		for ( int i = 0; i<n ; i++){
			printf("\n\nID: %d", sv[i].id);
			printf("\nTen: %s", sv[i].name);
			printf("\nTuoi: %d", sv[i].age);
			printf("\nSdt: %s ", sv[i].phoneNumber);
		}
	}
	
}

