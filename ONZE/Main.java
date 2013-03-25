   import java.io.*; 
   class Main{
      public static void main(String args[])throws Exception { 
         BufferedReader in = new BufferedReader(
            new InputStreamReader (System.in));
         String aux; 
         while( !( (aux=in.readLine()).equals("0") ))
         {
            int somapar = 0, somaimpar = 0; 
            for(int i= 0; i<aux.length();i = i + 2)
            {
               somapar = somapar + (int) aux.charAt(i);
            } 
            for(int i= 1; i<aux.length();i = i + 2)
            {
               somaimpar = somaimpar + (int) aux.charAt(i);
            } 
            int diferenca = somapar - somaimpar; 
            if(diferenca%11 == 0) System.out.println(aux + " is a multiple of 11.");
            else System.out.println(aux + " is not a multiple of 11.");
         } 
         System.exit(0); 
      }
   } 
