#include <stdio.h>
   int main(){
      int participantes, linhas, teste = 1;
      while( scanf( "%d%d", &participantes, &linhas ) ){
         if( !linhas ){
            return 0;
         }
         int i, ordem, numero, j, part;
         int v[participantes];
         for( i = 0; i < participantes; i++ ){
            scanf( "%d", &v[i] );
         }
         while( linhas-- ){
            scanf( "%d%d", &numero, &ordem );
            for( i = 0, j = 0; i < numero; i++, j++ ){
               scanf( "%d", &part );
               if( v[j] ){
                  if( ordem != part ){
                     v[j] = 0;
                  }
               } 
               else{
                  for( ; j < participantes; j++ ){
                     if( v[j] ){
                        if( ordem != part ){
                           v[j] = 0;
                        }
                        break;
                     }
                  }
               }
            }
         }
         int *p = v;
         for( i = 0; i < participantes; i++, p++ ){
            if( *p ){
               printf( "Teste %d\n%d\n", teste++, *p );
               break;
            }
         }
      }
   } 
