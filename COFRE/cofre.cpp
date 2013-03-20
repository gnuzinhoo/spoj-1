#include <stdio.h>
   int main(){
      int n, j, z, dif, i, inst = 1; 
      scanf( "%d", &n );
      while( n ){ 
         dif = 0; 
         printf( "Teste %d\n", inst++ );
         for( i = 0; i < n; i++ ){ 
            scanf( "%d%d", &j, &z ); 
            dif += j - z; 
            printf( "%d\n", dif ); 
         }
         printf( "\n" ); 
         scanf( "%d", &n ); 
      }
      return 0;
   } 
