#include <stdio.h>
#include "matrix.h"

struct matrix {
	struct matrix* right;
	struct matrix* below;
	int line;
	int column;
	float info;
}

Matrix* matrix_create( void )
{
    //lê de stdin os elementos diferentes de zero de uma matriz 
    //e monta a estrutura especificada acima. 
    //A entrada consiste dos valores de m e n (número de linhas e de colunas da matriz) 
    //seguidos de triplas (i, j, valor) 
    //para os elementos diferentes de zero da matriz. Por exemplo, para a matriz da Figura 1, a entrada seria:
}

void matrix_destroy( Matrix* m )
{
    //devolve todas as células da matriz m para a área de memória disponível.
}

void matrix_print( Matrix* m )
{
    // imprime a matriz m para stdout no mesmo formato usado por matrix_create().
}

Matrix* matrix_add( Matrix* m, Matrix* n )
{
    //recebe como parâmetros as matrizes m e n, 
    //retornando a soma das mesmas 
    //(a estrutura da matriz retornada deve ser alocada dinamicamente pela própria operação).

}

Matrix* matrix_multiply( Matrix* m, Matrix* n)
{
    //recebe como parâmetros as matrizes m e n, retornando a multiplicação das mesmas 
    //(a estrutura da matriz retornada deve ser alocada dinamicamente pela própria operação).
}

Matrix* matrix_transpose( Matrix* m )
{
    //recebe como parâmetro a matriz m, 
    //retornando mT – a transposta de m 
    //(a estrutura da matriz retornada deve ser alocada dinamicamente pela própria operação).

}

float matrix_getelem( Matrix* m, int x, int y)
{
    //retorna o valor do elemento (x, y) da matriz m.
    //void matrix_setelem( Matrix* m, int x, int y, float elem ): 
    //atribui ao elemento (x, y) da matriz m o valor elem.

}


int main( void ) {
    /* Inicializacao da aplicacao ... */
    Matrix *A = matrix_create();
    matrix_print( A );
    Matrix *B = matrix_create(); 
    matrix_print( B );
    Matrix *C = matrix_add( A, B ); 
    matrix_print( C );
    matrix_destroy( C );
    C = matrix_multiply( A, B ); 
    matrix_print( C );
    matrix_destroy( C );
    C = matrix_transpose( A ); 
    matrix_print( C );
    matrix_destroy( C );
    matrix_destroy( A );
    matrix_destroy( B );
    return 0;
}
int main( int argc, char const *argv[] )
{

    typedef struct matrix Matrix;

    printf("Hello World!\n");

    return 0;
}
