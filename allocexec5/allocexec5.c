#include<stdio.h>
#include<stdlib.h>

//Faca um programa que leia um numero N e:
//Crie dinamicamente e leia um vetor de inteiro de N posicoes;
//Leia um numero inteiro X e conte e mostre os multiplos desse numero que existem
//no vetor.


int main()
{
	int n = 0, x = 0, multiplos = 0, d = 0, e = 0; //d = número de múltiplos unicos 
	
	
	
	printf("Digite quantos numeros:\n");
	scanf("%d", &n);
	
	int nreal = n-1;

	int* vetor = (int*)malloc(sizeof(int) * n);
	int multiplosUnicos[nreal]; //limite de multiplos unicos é o tamanho maximo do vetor
	
	for(int i = 0; i <= nreal; i++)  
	{
		multiplosUnicos[i] = 0;
	}
		
	printf("Digite os numeros para preencher o vetor:\n");
	for(int i = 0; i <= nreal; i++)
	{
		scanf("%d", &vetor[i]);
	}
	
	printf("Digite x:\n");
	scanf("%d", &x);

	
	
	for(int i = 0; i <= nreal; i++)
	{
		int auxd = d;
		if(vetor[i] % x == 0) // se for multiplo
		{
			if(auxd == 0)
			{
				multiplosUnicos[d] = vetor[i];
				d++;
			}
			else
			{
				for(int c = 0; c < auxd; c++)   //vai até d pra passar por todo o multiplosUnicos
				{
					if(vetor[i] != multiplosUnicos[c])
					{
						e++;  
					} 

					if(e == d) //se e conta até d, quer dizer que passou por todos os multiplos unicos e não encontrou nenhum igual
					{
						multiplosUnicos[d] = vetor[i];  
						d++;
						auxd = d;
						e = 0;
					}

					if(c == auxd-1)
					{
						auxd = d;
						e = 0;
					}
					
				}
			}
			multiplos++;
			
			
		}
	}
	
	//quis fazer que ele imprime quais são os múltiplos únicos também
	
	printf("Numero de multiplos: %d\nNumero de multiplos unicos: %d\n", multiplos, d);
	printf("Multiplos Unicos: ");
	if(d == 0)
	{
		printf("não tem\n");
	}else
		{
			for(int i = 0; i < d; i++)
			{
			printf("%d ", multiplosUnicos[i]);
			
			}
		}
		
	printf("\n");
	
	free(vetor);
	
}
