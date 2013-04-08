#include <stdio.h>
   int main(){
      int num, i, varetas, comprimentos, retangulos;
      scanf( "%i", &num );
      while( num != 0 ){
         i = retangulos = 0;
         while( i < num ){
            scanf( "%i", &comprimentos );
            scanf( "%i", &varetas );
            retangulos += varetas / 2;
            i++;
         }
         printf( "%i\n", retangulos / 2 );
         scanf( "%i", &num );
      }
      return 0;
   } 
