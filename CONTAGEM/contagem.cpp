


#include <stdio.h>

 #include <string.h>

 #include <math.h>

 #include <stdlib.h>
 

   int main(){
   
      int i, j = 0, tamanho;
   
      char palavra[65];
   
      while(scanf("%s", palavra) != EOF){
      
      
         tamanho = strlen( palavra );
      
         long long int valor = 0;
      
         for( i = 0; i < tamanho; i++ ){
         
         
            if( palavra[i] == 'b'){
            
               valor += (long long int)pow( 2, tamanho - i -1 ); }
         
         }
      
      
         printf("Palavra %i\n", ++j); printf("%lli\n\n", valor);
      
      }
   
      return 0;
   
   }