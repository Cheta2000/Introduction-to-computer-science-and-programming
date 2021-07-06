#include <stdio.h>
#include <stdbool.h>

bool czy_pasuje(int czerwone,int biale,int pom1[4],int pom2[4]){
	int pozycja=0,ogolnie=0,liczba=0;
	for(int i=0;i<4;i++){
		if(pom1[i]==pom2[i]) pozycja++;
	}
	for(int i=0;i<6;i++){
		int licz1=0,licz2=0;
		liczba++;
		for(int j=0;j<4;j++){
			if(pom1[j]==liczba) licz1++;
			if(pom2[j]==liczba) licz2++;
		}
		if(licz1<licz2) ogolnie=ogolnie+licz1;
		else ogolnie=ogolnie+licz2;
	}
	ogolnie=ogolnie-pozycja;
	if(pozycja==czerwone && ogolnie==biale) return true;
	else return false;
}


bool gra(int czerwone,int biale,int t[1296][4],int akt){
	int pom1[4],pom2[4];
	for(int i=0;i<4;i++){
		pom1[i]=t[akt][i];
		printf("%d ",pom1[i]);
	}
	printf("?\n");
	printf("Czerwone: ");
	scanf("%d",&czerwone);
	printf("Biale: ");
	scanf("%d",&biale);
	if(czerwone==4) return true;
	for(int i=akt+1;i<1296;i++){
		if(t[i][0]!=0){
			for(int j=0;j<4;j++){
				pom2[j]=t[i][j];
			}
			if(czy_pasuje(czerwone,biale,pom1,pom2)==false) t[i][0]=0;
		}
	}
	int akt1=0;
	for(int i=akt+1;i<1296;i++){
		if(t[i][0]!=0){
			akt1=i;
			break;
		}
	}
	if(akt1==0) return false;
	return gra(czerwone,biale,t,akt1);
}


int main(){
	int t[1296][4];
	int czerwone=0,biale=0,indeks=0;
	for(int i=3;i>=0;i--){
		int licznik=1;
		int a=1;
		for(int j=0;j<1296;j++){
			t[j][i]=a;
			if(i==3) a++;
			if(i==2 && licznik%6==0) a++; 
			if(i==1 && licznik%36==0) a++;
			if(i==0 && licznik%216==0) a++;
			licznik++;
			if(a==7) a=1;
		}
	}
	if(gra(czerwone,biale,t,indeks)) printf("Wygralem\n");
	else printf("Oszukujesz\n");
}


