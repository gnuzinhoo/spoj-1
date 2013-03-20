#include <stdio.h>

   int main(){
   
      int v[] = {50,10,5,1};
   
      int result[4];
   
      int teste = 1, valor, i;
   
   
      while( scanf( "%d", &valor ) ){
      
         if( !valor ){
         
            return 0;
         
         }
      
      
         for( i = 0; i < 4;i++ ){
         
            result[i] = valor / v[i];
         
            valor = valor % v[i];
         
         }
      
      
         printf( "Teste %d\n%d %d %d %d \n\n", teste++, result[0],result[1], result[2], result[3] );
      
      }
   
   }
