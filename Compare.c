#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool match(char *wzorzec, char *lancuch){
	char wzorzec1[30]="";
	if(strlen(wzorzec)==0 && strlen(lancuch)==0) return true;
	if(wzorzec[strlen(wzorzec)-1]=='*'){
		strncpy(wzorzec1,wzorzec,strlen(wzorzec)-1);
		if(strlen(wzorzec1)==0) return true;
		for(int i=0;i<strlen(lancuch);i++){
			char lancuch1[30]="";
			strncpy(lancuch1,lancuch,strlen(lancuch)-i);
			if(match(wzorzec1,lancuch1)) return true;
		}	
	}
	char lancuch1[30]="";
	if(((wzorzec[strlen(wzorzec)-1]!=lancuch[strlen(lancuch)-1]))&&(wzorzec[strlen(wzorzec)-1]!='?')) return false;
	else{
	strncpy(wzorzec1,wzorzec,strlen(wzorzec)-1);
        strncpy(lancuch1,lancuch,strlen(lancuch)-1);
      	return match(wzorzec1,lancuch1);
	}
}	
int main(){
	char wzorzec[30];
	char lancuch[30];
	printf("Podaj wzorzec: \n");
	scanf("%29s",wzorzec);
	printf("Podaj lancuch: \n");
	scanf("%29s",lancuch);
	if(match(wzorzec,lancuch)) printf("Lancuch jest zgodny ze wzorcem\n");
	else printf("Lancuch nie jest zgodny ze wzorcem\n");
	return 0;
}
