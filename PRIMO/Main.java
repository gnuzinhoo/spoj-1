   import java.util.Scanner;
   class Main{
      public static void main(String[] args){
         Scanner l = new Scanner(System.in);
         int n = Integer.parseInt(l.nextLine());
         double b = Math.pow(2,31);
         int d = (int)b; 
         if(n < d){ 
            if(n < -1 || n > 1){
               int r = 0;
               if(n < -1){
                  n *= -1;
               }
               for(int i = 1; n >= i; i++){
                  if(n%i == 0){
                     r++;
                  }
               }
               if(r > 2){
                  System.out.print("nao");
               }
               else{
                  System.out.print("sim");
               }
            }
         }
         System.exit(0);
      }
   } 
