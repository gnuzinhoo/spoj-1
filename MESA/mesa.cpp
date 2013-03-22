#include <cstdio>
#include <deque>
   using namespace std;
   int colocarDirecao( deque<int> *adj, int *vis, int i, int dir ){
      if( !vis[i] ){
         vis[i] = dir;
         dir = dir%2 + 1;
         for( deque<int>::iterator it=adj[i].begin(); it!=adj[i].end(); it++ ){
            if( !colocarDirecao( adj, vis, *it, dir ) ){
               return 0;
            }
         }
         return 1;
      } 
      else{
         return vis[i] == dir;
      }
   }
   int main(){
      int pessoas, relacoes, dir, inst=1;
      while( scanf( "%d%d", &pessoas, &relacoes ) != EOF ){
         deque<int> adj[pessoas];
         int *vis = new int[pessoas];
         int possivel = 1;
         memset( vis, '\0', pessoas * sizeof( int ) );
         dir = 1;
         int pessoa, amigo, i;
         for( i = 0; i < relacoes; i++ ){
            scanf( "%d%d", &pessoa, &amigo );
            pessoa--, amigo--;
            adj[pessoa].push_back( amigo );
            adj[amigo].push_back( pessoa );
         }
         i = 0;
         while( possivel && i < pessoas ){
            if( !vis[i] ){
               possivel = colocarDirecao( adj, vis, i, dir );
            }
            i++;
         }
         printf( "Instancia %d\n%s\n\n", inst++, (possivel) ? "sim" : "nao" );
      }
      return 0;
   } 
