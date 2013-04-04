#include <cstdio>
#include <list>
#include <set>
#include<string.h>
#include<stdio.h>
#include <iostream>
   using namespace std; 
   int main(){
      int cartas, jogadores; 
      while( scanf( "%d%d", &cartas, &jogadores ) ){
         if( !cartas ){
            return 0;
         } 
         int jog[jogadores][2], monte[13], vez = 0;
         int carta, temCarta, i;
         int max = 0; 
         memset( jog, '\0', jogadores * 2 *sizeof( int ) );
         memset( monte, '\0', 13 *sizeof( int ) ); 
         while( cartas-- ){
            scanf( "%d", &carta ); 
            temCarta = 0; 
            for( i = 0; i < jogadores; i++ ){
               if( i == vez ){
                  if( carta == jog[i][0] ){
                     jog[i][1]++; 
                     if( jog[vez][1] > max ){
                        max = jog[vez][1];
                     } 
                     temCarta = 1; 
                     break;
                  }
               }
               else if( jog[i][0] == carta ){
                  jog[vez][0] = carta;
                  jog[i][0] = 0;
                  jog[vez][1] += jog[i][1] + 1;
                  jog[i][1] = 0;
                  temCarta = 1; 
                  if( jog[vez][1] > max ){
                     max = jog[vez][1];
                  }
                  break;
               }
            } 
            if( !temCarta && monte[carta-1] == 0 ){
               monte[ carta - 1] = 1;
               vez = ++vez % jogadores;
            } 
            else if( !temCarta ){
               jog[vez][0] = carta;
               jog[vez][1] += 2;
               monte[carta-1] = 0; 
               if( jog[vez][1] > max ){
                  max = jog[vez][1];
               }
            }
         } 
         printf( "%d ", max ); 
         for( i = 0; i < jogadores; i++ ){
            if( jog[i][1] == max ){
               printf( "%d ", i + 1 );
            }
         } 
         puts( "\n" );
      }
   }
