   import java.util.Scanner;
   public class Main{
      public static void main( String args[] ){
         Scanner scan = new Scanner( System.in );
         int vezes;
         while( (vezes = scan.nextInt() ) != 0 ){
            int soma = 0;
            while( vezes-- != 0 ){
               scan.nextInt();
               soma += scan.nextInt() / 2;
            }
            System.out.println( soma / 2 );
         }
      }
   } 
