   import java.io.BufferedReader;
   import java.io.InputStreamReader;
   import java.io.IOException; 
   /*Para este proble a seguinte formula é valida (2^n)-1 onde n é o numero de discos*/
   class Main{ 
      public static void main (String[] args) throws IOException{
         BufferedReader reader = new BufferedReader (new InputStreamReader(System.in)); 
         int n = Integer.parseInt(reader.readLine()); 
         int x = 1;
         if(n >= 0 && n <= 30){ 
            for(int i = 0; n > 0 && n <= 30; i++){ 
               double j = Math.pow(2,(n));
               int r = (int)j;
               r -=1; 
               System.out.println("Teste "+x+ "\n"+r+"\n");
               x++;
               n = Integer.parseInt(reader.readLine()); 
            } 
         }
         System.exit(0);
      }
   } 
