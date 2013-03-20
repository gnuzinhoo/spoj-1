#include <stdio.h>
   int main(){
      int numApostas;
      while( scanf( "%d", &numApostas ) ){
         if( !numApostas ){
            return 0;
         }
         int soma = 0;
         int sequencia = 0, maximo = 0, somaNegativo=0, aposta;
         while( numApostas-- ){
            scanf( "%d", &aposta );
            if( aposta > 0 ){
               if( sequencia != 0 ){
                  if( (somaNegativo * -1) > sequencia ){
                     sequencia = aposta;
                  }
                  else{
                     sequencia += somaNegativo + aposta;
                  }
               }
               else{
                  sequencia += aposta;
               }
               somaNegativo = 0;
               if( sequencia > maximo ){
                  maximo = sequencia;
               }
            }
            else{
               somaNegativo += aposta;
            }
         }
         if( maximo > 0 ){
            printf( "The maximum winning streak is %d.\n", maximo);
         } 
         else{
            puts( "Losing streak." );
         }
      }
   } 
