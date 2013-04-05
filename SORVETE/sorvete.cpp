#include <stdio.h>
#include <stdlib.h>
   typedef 
      struct{
         int inicio;
         int fim;
      } Range;
   int ordenaRanges( const void* e1, const void* e2 ){
      Range *r1 = (Range*)e1;
      Range *r2 = (Range*)e2;
      if( r1->inicio < r2->inicio || (r1->inicio == r2->inicio && r1->fim < r2->fim ) ){
         return -1;
      }
      if( r1->inicio == r2->inicio && r1->fim == r2->fim ){
         return 0;
      }
      return 1;
   }
   int main(){
      int teste=1;
      int ms, sorveteiros, i, j;
      while( scanf( "%d%d", &ms, &sorveteiros ) ){
         if( !(ms && sorveteiros) ){
            return 0;
         }
         j = 0;
         Range rs[sorveteiros], rs2[sorveteiros];
         for( i = 0; i < sorveteiros; i++ ){
            scanf( "%d%d", &rs[i].inicio, &rs[i].fim );
         }
         qsort( rs, sorveteiros, sizeof( Range ), ordenaRanges );
         rs2[0] = rs[0];
         for( i = 1 ; i < sorveteiros; i++ ){
            if( rs[i].inicio >= rs2[j].inicio && rs[i].inicio <= rs2[j].fim ){
               if( rs[i].fim > rs2[j].fim ){
                  rs2[j].fim = rs[i].fim;
               }
            } 
            else{
               j++;
               rs2[j] = rs[i];
            }
         }
         printf( "Teste %d\n", teste++ );
         for( i = 0; i <= j; i++ ){
            printf( "%d %d\n", rs2[i].inicio, rs2[i].fim );
         }
         puts("");
      }
      return 0;
   } 
