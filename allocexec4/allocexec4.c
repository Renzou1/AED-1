//Faca um programa que receba do usuario o tamanho de uma string e chame uma
//funcao para alocar dinamicamente essa string. Em seguida, o usuario devera informar o
//conteudo dessa string. O programa imprime a string sem suas vogais.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int tamanho = 0;
	
	printf("Digite o tamanho da string (incluindo o /0):\n");
	scanf("%d", &tamanho);   
	
	
	char* string = (char *)malloc(sizeof(char)*tamanho);
	
	printf("Informe o conteúdo da string:\n");
	
	for(int i = 0; i < tamanho; i++)      //revisar funções de strings
	{
		scanf("%c", &string[i]);   
		if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U' )
		{
			i--;   //leva a escrever por cima da vogal
		}
	}
	
	for(int i = 0; i <= tamanho; i++)
	{
		printf("%c", string[i]);
	}
	
	free(string);
	
	
}
