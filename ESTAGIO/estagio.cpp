#include <stdio.h>
   int main(){
      int n, nota, aluno, maxNota, qtde, i, inst = 1; 
      scanf( "%d", &n );
      while( n ){ 
         qtde = i = 0; 
         maxNota = -1; 
         int x[n];
         for(; i < n; i++ ){ 
            scanf( "%d%d", &aluno, &nota );
            if( nota > maxNota ){ 
               maxNota = nota; 
               qtde = 0; 
               x[ qtde++ ] = aluno; 
            } 
            else if( nota == maxNota ){ 
               x[qtde++] = aluno; 
            } 
         } 
         printf( "Turma %d\n", inst++ );
         for( i = 0; i < qtde; i++ ){ 
            printf( "%d ", x[i] ); 
         }
         printf( "\n\n" ); 
         scanf( "%d", &n ); 
      } 
      return 0;
   } 
