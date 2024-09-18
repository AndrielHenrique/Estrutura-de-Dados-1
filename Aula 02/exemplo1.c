/*Escrever uma funcao potencia que receba como entrada dois parametros(real e inteiro)
e forneca como saida o valor correspondente ao primeiro parametro elevado ao segundo. sem utilizar a funcao
pow. Escreva um programa que utilize essa funcao.*/
#include <stdlib.h>
#include <stdio.h>


float pot(int x, int y){
	float pot = 1;
	
	for(int i = 0; i<y; i++){
		pot *= x;
		
	}

	printf("A potencia eh = %d", pot);
	return pot;
}
int main(){
	
	int x = 5;
	float y = 5;
	//pot(x,y);

	
	int exp;
	float base, resultado;
	
	printf("Informe a base: ");
	scanf("%f", &base);
	
	printf("Informe o expoente: ");
	scanf("%d", &exp);
	
	if(exp <= 0)
		{resultado = 0;
		}
	
	resultado = 1;
	for(int i = 0; i<exp; i++){
		resultado *= base;
	}
	printf("%.2f elevado a %d eh = %.2f\n", base, exp, resultado);

	
	return 0;
}