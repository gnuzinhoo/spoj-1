#include <stdio.h>
   int main(){
      int x1, y1, x2, y2, x, y, teste=1;
      while( scanf( "%d%d%d%d", &x1, &y1, &x2, &y2 ) ){
         if( !x1 ){
            return 0;
         }
         int qtde=0, caidos;
         scanf( "%d", &caidos );
         while( caidos-- ){
            scanf( "%d%d", &x, &y );
            if( x >= x1 && x <= x2 && y <= y1 && y >= y2 ){
               qtde++;
            }
         }
         printf( "Teste %d\n%d\n\n", teste++, qtde );
      }
      return 0;
   } 
