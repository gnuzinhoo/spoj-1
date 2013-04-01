   import java.util.Scanner;

   class Main{
   
      public static void main(String[] args){
         
      
         EXP q = new EXP();
      
         q.gN();	
      
         System.exit(0);
      
      
      }
   
   }
   

   class EXP{
   
   
      private int n;
   
      public  EXP(){
      
         Scanner l = new Scanner(System.in);
      
         n = l.nextInt();
      
         if(n <= 10000){
         
            n*=n;
         
         }
      
      } 
      
   
      public void gN(){
      
         System.out.print(n);
      
      }
   
   
   
   }
 
