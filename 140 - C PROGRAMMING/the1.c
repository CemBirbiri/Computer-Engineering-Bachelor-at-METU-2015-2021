#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char* stack_bosaltma(char stack[],char operandlar[],int *kontrol, int *operandkontrol, int* birsifirkontrol,char bir_sifir[]){
	
     while(1){
     	
	if (stack[*kontrol-1]!='(') {printf("girdi1\n");
     	operandlar[*operandkontrol]=stack[*kontrol-1]; *operandkontrol+=1;
	 stack[*kontrol-1]='\0';  *kontrol-=1;
	 printf("sifir koyma2\n"); 
	 bir_sifir[*birsifirkontrol]='0';
	 *birsifirkontrol+=1;}
	

	else {printf("girdi2\n");
		
		stack[*kontrol-1]='\0'; *kontrol-=1;
		
		
		 return stack;}}}

char* gecici_boslatma(char gecici[],int* gecici_uzunlugu){
	if(*gecici_uzunlugu==0) {*gecici_uzunlugu=0; return gecici;}
	else {
		gecici[*gecici_uzunlugu-1]='\0';
		*gecici_uzunlugu-=1;
		return gecici_boslatma(gecici,gecici_uzunlugu);

	}
}
/*char operand_bosaltma(char operandlar[],int length){
	int i;
	for(i=0;i<length;i++){
		if(operandlar[length-1]!='+' && operandlar[length-1]!='-' &&  operandlar[length-1]!='/' &&  operandlar[length-1]!='*' 
			&&  operandlar[length-1]!='^' &&  operandlar[length-1]!='s' &&  operandlar[length-1]!='q' &&  operandlar[length-1]!='l' &&  operandlar[length-1]!='c' &&  operandlar[length-1]!='~'){
			operandlar[length-1]='\0';
			length-=1;
		}
		else return operandlar;
	}
}*/


int compare(int operand){
	int value=0;
	if (operand=='+' || operand=='-'){value=1; return value;}
	else if (operand=='*' || operand=='/'){value=2; return value;}
	else if (operand=='(') {value=0; return value;}
	else if(operand=='s' || operand=='c' || operand=='l' || operand=='q' || operand=='~'){value =44; return value;}
	else  {value=3; return value;}    
	
}


char* nulla_cevir(char array[],int kontrol){
	array[kontrol-1]='\0';
	return array;}


int main(){
	int kontrol=0,k=0,temp,infix_uzunlugu=0,d,s,stackte_kalan_sayisi=0,i,j,m,sum1=0,birsifirkontrol=0;
	char infix[200],stack[200],gecici[200],operandlar[200];
	int numkontrol=0,gecici_uzunlugu=0,operandkontrol=0;
	double numericallar[200];
	char bir_sifir[200];
	char a[26] = {0,0,0};
	int letter_count=0;
	int interval_sayisi;
	long int iteration_sayisi;
	char harff,harfler[26];
	double olasiliklar[200][200];


	int operand_uzunlugu=0,sonuc_uzunlugu=0,birsifiruzunlugu=0,numericaluzunlugu=0;
	double sonuc[200];
	int sum;
	double randomsayi,deger,alt,len,x;
	double max,min;
	
	max=-(RAND_MAX); min=RAND_MAX;

	
	
	




scanf("%[^\n]",infix);
for(i=0;i<200;i++){
	if(infix[i]=='\0') break;
	else infix_uzunlugu+=1;}





/* input alma kismi */

for(i=0;i<infix_uzunlugu;i++){
	if (infix[i]>=65 && infix[i]<=90){
		if(a[infix[i]-65]==0){
			a[infix[i]-65]=1;            /* Kac harf oldugunu buluyor */
			letter_count+=1;
		}
	}
}

scanf("%d %ld",&interval_sayisi,&iteration_sayisi);



for(i=0;i < letter_count;i++){
	scanf(" %c",&harff);
	harfler[i]=harff;
	scanf(" %lf %lf", &olasiliklar[i][0],&olasiliklar[i][1]);
	for(j = 2; j < interval_sayisi + 2; j++){
		scanf(" %lf",&olasiliklar[i][j]);
	}
}


	  






for(i=0;i<infix_uzunlugu;i++){ 

if (infix[i]==' ') { ;}	
else if (infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')' 
	&& infix[i]!=' ' && infix[i]!='s' && infix[i]!='~' && infix[i]!='c' && infix[i]!='l'){ 

	 
	
	if(infix[i]=='1' || infix[i]=='2' || infix[i]=='3' || infix[i]=='4' || infix[i]=='5' || infix[i]=='6' || infix[i]=='7' || infix[i]=='8' || infix[i]=='9' || infix[i]=='0' || infix[i]=='.' ){

		for(m=i;infix[m]!='\0';m++){ 
		if (infix[m]!='+' && infix[m]!='-' && infix[m]!='*' && infix[m]!='/' && infix[m]!='^' && infix[m]!='(' && infix[m]!=')' 
	&& infix[m]!=' ') { /*printf("sum1 geciciden once=%d\n",sum1);*/ gecici[sum1]=infix[m]; gecici_uzunlugu+=1;  /*printf("%c\n",infix[m]);*/
	if(infix[m+1]=='\0'){/*printf("sorunlu yer\n");*/ numericallar[numkontrol]=atof(gecici); 
		/*printf("sorunlu yerdeki birsifirkontrol=%d\n",birsifirkontrol);*/
		bir_sifir[birsifirkontrol]='1';
		birsifirkontrol+=1;}
	}
		
	else {/*printf("gecici [0]=%c\n",gecici[0]);
		printf("gecici [1]=%c\n",gecici[1]);
		printf("gecici [2]=%c\n",gecici[2]);
		printf("gecici [3]=%c\n",gecici[3]);*/
		numericallar[numkontrol]=atof(gecici); 
		bir_sifir[birsifirkontrol]='1';
		birsifirkontrol+=1;






		/*printf("numericallar[numkontrol] = %f\n",numericallar[numkontrol]); printf("numkontrol once=%d\n",numkontrol); */
	numkontrol+=1; /*printf("numkontrol sonra=%d\n",numkontrol);*/
		break;}
	/*printf("sum1 her for dongusunde %d\n",sum1);*/
	sum1+=1;

	
	}

i+=sum1-1;
sum1=0;
gecici_boslatma(gecici,&gecici_uzunlugu);


}
else{
	for(s=0;s<letter_count;s++){
		if(infix[i]==harfler[s]){
			randomsayi=(double)rand()/((double)RAND_MAX);



	sum=0;
	for(d=2;d<interval_sayisi;d++){
		if(sum >= randomsayi) {
			x = d - 2;
			break;
		}
		else {
			sum += olasiliklar[s][d];
		}
	}
	len = (olasiliklar[s][1] - olasiliklar[s][0])/interval_sayisi;
	alt = olasiliklar[s][0] + (len * x);
	deger = (rand() / (double)RAND_MAX )*len + alt;
	numericallar[numkontrol]=deger; 
	
		bir_sifir[birsifirkontrol]='1';
		birsifirkontrol+=1;
		numkontrol+=1;

		}
	}

}




}

else if (infix[i]=='s') {
	if (infix[i+1]=='i'){stack[kontrol]='s'; kontrol+=1; i+=2; }
	else {stack[kontrol]='q'; kontrol+=1; i+=3; }
}
else if (infix[i]=='c'){stack[kontrol]='c'; kontrol+=1; i+=2; }
else if (infix[i]=='l'){stack[kontrol]='l'; kontrol+=1; i+=1; }

else if (infix[i]=='~'){stack[kontrol]='~'; kontrol+=1; }
else{
	
	if(i==2) {
		stack[0]=infix[i];
				kontrol+=1;}
	else if (infix[i]=='(') {stack[kontrol]='('; kontrol+=1; }
	else if (infix[i]==')') {
	stack_bosaltma(stack,operandlar,&kontrol,&operandkontrol,&birsifirkontrol,bir_sifir); 
		


	}




	else if (infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^' ){
		
		if (kontrol==0) {
			stack[kontrol]=infix[i]; kontrol+=1;}
		else {
			
			if(compare(infix[i])>compare(stack[kontrol-1])){
				
				stack[kontrol]=infix[i]; kontrol+=1;}
			else{
				bus: operandlar[operandkontrol]=stack[kontrol-1];
				operandkontrol+=1;
				bir_sifir[birsifirkontrol]='0';
				
				birsifirkontrol+=1;
				
					nulla_cevir(stack,kontrol);
					kontrol-=1;
					if (kontrol==0) {
						
						stack[0]=infix[i]; kontrol+=1;} 
					else{
				
				
				/*printf("stack kontrol-1 %c\n",stack[kontrol-1]);*/
					if (compare(stack[kontrol-1])<compare(infix[i])){

						
						stack[kontrol]=infix[i]; kontrol=kontrol+1;}
					else{
						
						goto bus;}
				}
		}



		

	}} }}


for(i=0;i<100;i++){
	if(stack[i]=='\0') break;
	else stackte_kalan_sayisi+=1;
}



j=stackte_kalan_sayisi-1;
 

 while(k<j)  /* burası stacki ters ceviriyor */
     { 
     	
     temp=stack[k];
     stack[k]=stack[j];
     stack[j]=temp;
     k++;
     j--;
     }






/*stackta kalanları operandlar arrayine atıyor */



/*for(i=0;1;i++){if(operandlar[i]=='\0') break;
else op++;}*/
/*operand_bosaltma(operand,op);*/
/*printf("******%c\n",operandlar[operandkontrol-1]);
printf("******%c\n",operandlar[operandkontrol]);*/





/* asagidaki iki for dongusu, numericallar ve operandlar arraylerinde ne oldugunu gosteriyor
for(i=0;1;i++){
	if(numericallar[i]=='\0') break;
	else printf(" numericallar  = %f\n",numericallar[i]);
}

for(i=0;1;i++){
	if(operandlar[i]=='\0') break;
	else printf(" operandlar sirayla = %c\n",operandlar[i]);
}
*/

/* for(i=0;i<10;i++) printf("birsifir= %c\n",bir_sifir[i]); bir_sifir arrayinin icindekileri basiyor*/

/* LET THE EVALUATION BEGIN */





/*printf("numericaluzunlugu==%d\n",numericaluzunlugu);*/



for(i=0;1;i++){
	if(bir_sifir[i]=='\0') break; /*bir_sifir arrayinde kac eleman oldugunu buluyor*/
	else birsifiruzunlugu+=1;}
/*printf("bir sifir uzunlugu= %d\n",birsifiruzunlugu);*/




for(i=0;i<birsifiruzunlugu;i++){
	
	if(bir_sifir[i]=='1'){  
		/*printf("bir_sifir[i]=%c\n",bir_sifir[i]);*/
		sonuc[sonuc_uzunlugu]=numericallar[numericaluzunlugu];
		/*printf("sonuc[sonucuuzunlugu]= %f\n",sonuc[sonuc_uzunlugu]);*/
		sonuc_uzunlugu+=1; numericaluzunlugu+=1;
		/*printf("sonuc uzunlugu numericallarda %d\n",sonuc_uzunlugu);*/
	}
	

	else {/*printf("girdi20.55555\n"); 
		printf("operand uzunlugu=%d\n",operand_uzunlugu);*/
		
		if(operandlar[operand_uzunlugu]=='-'){
			sonuc[sonuc_uzunlugu-2]= sonuc[sonuc_uzunlugu-2]-sonuc[sonuc_uzunlugu-1];
			sonuc[sonuc_uzunlugu-1]=0;
			sonuc_uzunlugu-=1;
			operand_uzunlugu+=1;
			/*printf("sonuc uzunlugu - de%d\n",sonuc_uzunlugu);
			printf("sonuc[sonuc_uzunlugu-1]=%f\n",sonuc[sonuc_uzunlugu-1]);*/}
		
		else if(operandlar[operand_uzunlugu]=='+'){

			/*printf("girdi22\n"); printf("sonuc uzunlugu= %d\n",sonuc_uzunlugu);*/
		/*printf("i=%d\n",i);
		printf("birsifiruzunlugu=%d\n",birsifiruzunlugu);*/
			sonuc[sonuc_uzunlugu-2]= sonuc[sonuc_uzunlugu-2]+sonuc[sonuc_uzunlugu-1];
			sonuc[sonuc_uzunlugu-1]=0;
			sonuc_uzunlugu-=1;
			operand_uzunlugu+=1;
			/*printf("sonuc[sonuc_uzunlugu-1]=%f\n",sonuc[sonuc_uzunlugu-1]);*/}
		
		else if(operandlar[operand_uzunlugu]=='/'){
			sonuc[sonuc_uzunlugu-2]= sonuc[sonuc_uzunlugu-2]/sonuc[sonuc_uzunlugu-1];
			sonuc[sonuc_uzunlugu-1]=0;
			sonuc_uzunlugu-=1;
			operand_uzunlugu+=1;
			/*printf("sonuc[sonuc_uzunlugu-2]=%f\n",sonuc[sonuc_uzunlugu-2]);*/}
		
		else if(operandlar[operand_uzunlugu]=='*'){
			sonuc[sonuc_uzunlugu-2]= sonuc[sonuc_uzunlugu-2]*sonuc[sonuc_uzunlugu-1];
			sonuc[sonuc_uzunlugu-1]=0;
			sonuc_uzunlugu-=1;
			operand_uzunlugu+=1;}
		
		else if(operandlar[operand_uzunlugu]=='^'){
			sonuc[sonuc_uzunlugu-2]= pow(sonuc[sonuc_uzunlugu-2],sonuc[sonuc_uzunlugu-1]);
			sonuc[sonuc_uzunlugu-1]=0;
			sonuc_uzunlugu-=1;
			operand_uzunlugu+=1;}
		
		else if(operandlar[operand_uzunlugu]=='s'){/*printf("girdi26\n");*/
			sonuc[sonuc_uzunlugu-1]= sin(sonuc[sonuc_uzunlugu-1]);
			operand_uzunlugu+=1;
			/*printf("sonuc[sonuc_uzunlugu-1]=%f\n",sonuc[sonuc_uzunlugu-1]);*/}
		
		else if(operandlar[operand_uzunlugu]=='c'){
			sonuc[sonuc_uzunlugu-1]= cos(sonuc[sonuc_uzunlugu-1]);
			operand_uzunlugu+=1;}
		
		else if(operandlar[operand_uzunlugu]=='l'){
			sonuc[sonuc_uzunlugu-1]= log(sonuc[sonuc_uzunlugu-1]);
			operand_uzunlugu+=1;}
		
		else if(operandlar[operand_uzunlugu]=='~'){
			sonuc[sonuc_uzunlugu-1]= -(sonuc[sonuc_uzunlugu-1]);
			operand_uzunlugu+=1;}
		
		else {

			sonuc[sonuc_uzunlugu-1]= sqrt(sonuc[sonuc_uzunlugu-1]);
			operand_uzunlugu+=1;
		}


	}

	}
	
	if(sonuc[0]>max) max=sonuc[0];
	if(sonuc[0]<min) min=sonuc[0];
	








return 0;
}


 








 





















