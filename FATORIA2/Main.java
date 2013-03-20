   import java.util.Scanner;
   class Main{
      public static void main(String args[]){
         Scanner l = new Scanner(System.in);
         int n = Integer.parseInt(l.nextLine());
         if(n >= 0 && n <= 12){
            int r = n; 
            for(int i = 1; n > i; i++){
               r = r*i;
            }
            if (n == 0){
               r = 1;
            }
            System.out.print(r);
         }
         System.exit(0);
      }
   }
