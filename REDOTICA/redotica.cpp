#include <cstdio>
#include <list>
#include <set>
#include<string.h>
#include<stdio.h>
#include <iostream>
   using namespace std;
   typedef
      struct Esp{
         int orig, dest, custo;
         bool operator()( const struct Esp &e1, const struct Esp &e2 ) const{
            return e1.custo < e2.custo;
         }
         bool operator< (const struct Esp & e1 ) const{
            return (custo < e1.custo) || (( custo == e1.custo) && (orig < e1.orig || (dest < e1.dest) ));
         }
         bool operator=( const struct Esp & e1 ) const{
            return dest == e1.dest && custo == e1.custo;
         }
      } 
   Esp;
   void geraArvoreMinima( int el, list<int> *grafo, int **custo, int *escolhidos, set<Esp>custos, list<int> *minima, int falt ){
      for( list<int>::iterator it = grafo[el].begin(); it != grafo[el].end(); it++ ){
         if( !escolhidos[*it] ){
            custos.insert( (Esp){ el, *it, custo[el][*it] } );
         }
      }
      set<Esp>::iterator it;
      for( it = custos.begin(); it != custos.end(); it++ ){
         if( escolhidos[it->dest] ){
            custos.erase( it );
         }
      }
      Esp value = *custos.begin();
      custos.erase( custos.begin() );
      escolhidos[value.dest] = 1;
      falt--;
      if( value.orig < value.dest ){
         minima[value.orig].push_front( value.dest );
      }
      else{
         minima[value.dest].push_front( value.orig );
      }
      if( falt ){
         geraArvoreMinima( value.dest, grafo, custo, escolhidos, custos, minima, falt );
      }
      return;
   }
   int main(){
      int aldeias, ligacoes, teste = 1;
      while( scanf( "%d%d", &aldeias, &ligacoes ) ){
         if( !aldeias )
            return 0;
         int *vet = new int[aldeias];
         list<int> *grafo = new list<int>[aldeias];
         list<int> *grafo2 = new list<int>[aldeias];
         int **custos = new int*[aldeias];
         set<Esp> custosSet;
         for( int i = 0; i < aldeias; i++ ){
            custos[i] = new int[aldeias];
         }
         memset( vet, 0, aldeias * 4 );
         for( int i = 0; i < ligacoes; i++ ){
            Esp a;
            scanf( "%d %d %d", &a.orig, &a.dest, &a.custo );
            a.orig--, a.dest--;
            grafo[a.orig].push_front( a.dest );
            grafo[a.dest].push_front( a.orig );
            custos[a.orig][a.dest] = a.custo;
            custos[a.dest][a.orig] = a.custo;
         }
         vet[0] = 1;
         geraArvoreMinima( 0, grafo, custos, vet, custosSet, grafo2, aldeias - 1 );
         printf( "Teste %d\n", teste++ );
         for( int i = 0; i < aldeias; i++ ){
            for( list<int>::iterator it = grafo2[i].begin(); it != grafo2[i].end(); it++ ){
               printf( "%d %d\n", i + 1, *it + 1 );
            }
         }
         puts( "\n" );
      }
   }
