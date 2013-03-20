#include <cstdio>
#include <cstring>
#define MAX_L 1001
#define max(i,j) (i>j?i:j)
   using namespace std;
   char s[MAX_L], w[MAX_L];
   int m[MAX_L][MAX_L][2], k, ls, lw;
   int main(){
      s[0] = w[0] = ' ';
      for(int i=0; i<MAX_L; i++) m[0][i][0] = m[i][0][0] = m[0][i][1] = m[i][0][1] = 0;
      while(scanf("%d", &k), k){
         scanf("%s%s", &s[1], &w[1]);
         ls = strlen(s);
         lw = strlen(w);
         for(int i=1; i<ls; i++) 
            for(int j=1; j<lw; j++) {
               m[i][j][0] = s[i]==w[j]? 1+m[i-1][j-1][0] : 0;
               if(m[i][j][0]<k) m[i][j][1] = max(m[i-1][j][1], m[i][j-1][1]);
               else{
                  m[i][j][1]=max(k+m[i-k][j-k][1], max(m[i][j-1][1], m[i-1][j][1]));
                  for(int l=k+1, L=m[i][j][0]; l<=L; l++)
                     m[i][j][1] = max(m[i][j][1], l+m[i-l][j-l][1]);
               }
            }
         printf("%d\n",m[ls-1][lw-1][1]);
      }
      return 0;
   }
