#include <stdio.h>
   int main(){
      int teste = 0, aldo, beto, entradas, n1, n2;
      scanf( "%d", &entradas );
      while( entradas != 0 ){
         aldo = beto = 0;
         while( --entradas > -1 ){
            scanf( "%i%i", &n1, &n2 );
            aldo += n1, beto += n2;
         }
         teste++;
         printf( "Teste %i\n", teste );
         printf( aldo > beto ? "Aldo\n" : "Beto\n" );
         scanf( "%d", &entradas );
      }
      return 0;
   }
