#include <stdio.h>
   int main(){
      int a,d,bi,ci,buf,x,cont;
      while(scanf("%d",&a)!=0){
         x=10000;
         buf=0;
         cont=0;
         scanf("%d",&d);
         if(a<1||a>10000||d<1||d>10000) 
            return 0;
         buf=a;
         while(buf>=1){
            scanf("%d",&bi);
            if(bi<=x) x=bi;
            buf=buf-1;
         }
         buf=d;
         while(buf>=1){
            scanf("%d",&ci);
            if(ci>x) cont++;
            buf=buf-1;
         }
         if(d-cont>=2) printf("N\n");
         else printf("Y\n");
      }
      return 0;
   }
