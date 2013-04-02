
   import java.util.Scanner;

   class Main{
   
      public static void main(String[] args){
      
         Scanner l = new Scanner(System.in);
      
         int n = Integer.parseInt(l.nextLine());
      
         if(n >= 0 && n <= 10000){
         
            int x = 1;
         
            for(int d = 0;n > 0 && n <= 10000; d++){   
            
               for(int i = 1; n >= i; i++){
               
                  int a = l.nextInt();
               
                  if(i == a){
                  
                     System.out.println("Teste "+x+ "\n"+a+"\n");
                  
                  }
               
               }
            
               x++;
            
               n = l.nextInt();
            
            }	
         
         }
      
         System.exit(0);
      
      }
   
   }