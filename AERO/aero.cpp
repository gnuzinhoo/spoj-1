#include <stdio.h>
   int main(){
      int numA, numV, teste = 0, i, maximo, a, v;
      scanf( "%i%i", &numA, &numV );
      while( numA != 0 ){
         int total[numA];
         maximo = 0;
         teste++;
         for( i = 0; i < numA; i++ ){
            total[i] = 0;
         }
         for( i = 0; i < numV; i++ ){
            scanf( "%i%i", &a, &v );
            if( ++total[a - 1] > maximo ){
               maximo++;
            }          
            if( ++total[v - 1] > maximo ){            
               maximo++;         
            }      
         }       
         printf( "Teste %i\n", teste );
         for( i = 0; i < numA; i++ ){
            if(total[i] == maximo ){
               printf( "%i ", i + 1 );
            }
         }
         printf( "\n" );
         scanf( "%i%i", &numA, &numV );
      }    
      return 0;
   }