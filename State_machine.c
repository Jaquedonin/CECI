#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int test_Reset(int reset, int clock_atual)
{
	int clock = 0;
	if(reset == 0)
	{	
		return clock_atual;
	}

	clock = Decode(clock_atual);
	return clock;
	
}

int Decode(int clock_atual)
{
	
	if(clock_atual)	
	{
	// decodifica a instrução lida em fetch
		printf("Descida de Clock\n");
		printf("Estado atual: S_0\n");
		clock_atual = 0;
		//chama próximo estado
	}

	printf("Subida de Clock\n");
	printf("Estado atual: S_1\n");
	clock_atual = 1;
	//decodifica a instrução

	/*switch (){
		case 1:
		break;
		case 2:
		break;
		case 3:
		break;
		default:
	}
	*/
	return clock_atual;
}



int main(int argc, char const *argv[])
{	
	
	int clock_atual = 0;
	int init = 1;
	int reset = 0;
	char c, letra ='\n';
	int numero_linhas = 0;
	//contando o número de linhas do arquivo
	FILE *arq;
    arq = fopen("instrucoes.txt","r");
    //Lendo linha por linha
    while(fread (&c, sizeof(char), 1, arq)) 
    {
        if(c == letra) 
		{
            numero_linhas++;
        }
    } 
    fclose(arq);
	
	printf("Inicialização: Clock atual em zero\n");
	FILE *pont_arq; 
	//abrindo o arquivo
	pont_arq = fopen("instruções.txt", "r");
	//Calcula a quantidade de instruções		
	for (int i = 0; i <= numero_linhas; ++i)
	{
		if(clock_atual==0)
		{
			int clock = 0;
			printf("Subida de clock\n");
			printf("Estado atual: S_0\n");
			//Lê a primeira instrução
			clock = test_Reset(1, clock_atual);
			if(clock)
			{
				clock_atual = 1;
			}
				
		}
		else
		{
			printf("Descida de clock\n");
			clock_atual = 0;

			//print descida do clock, 
		}
	}
	// fechando arquivo
	fclose(pont_arq);

	return 0;
}
	



