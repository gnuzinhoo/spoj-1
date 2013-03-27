    #include <stdio.h>
    #include <string.h>
   int main(){
      int n,i,contador=1;
      char x[22],nome[22];
      while(scanf("%d",&n)==1 && n!=0){
         if(n==0||n<1||n>100) 
            return 0;
         int menornota=0,nota=0;
         scanf("%s %d",x,&menornota);
         for(i=0;i<n-1;i++){
            scanf("%s %d",nome,&nota);
            if(nota<menornota){
               menornota=nota;
               strcpy (x,nome);
            }
            else if(nota==menornota && strcmp(nome,x)>0) strcpy(x,nome);
         }
         printf("Instancia %d\n%s\n\n",contador++,x);
      }
      return 0;
   }

