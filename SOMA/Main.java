   import java.util.Scanner;
   class Main{
      public static void main(String [] args){
         Soma s = new Soma();
         System.out.print(s.R()); 
      } 
   }
   class Soma{
      private int r, n, x; 
      public Soma(){
         Scanner l = new Scanner(System.in);
         n = Integer.parseInt(l.nextLine());
         for(int i = 0; i < n; i++){
            x = Integer.parseInt(l.nextLine());
            r += x;
         }
      } 
      public int R(){
         return r;
      }
   }
