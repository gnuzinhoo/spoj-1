   import java.util.Scanner;
   import java.util.Arrays;
   class Main{
      public static void main(String[] args){ 
         Scanner l = new Scanner(System.in); 
         int n = l.nextInt();
         int m = l.nextInt(); 
         int a[] = new int[n]; 
         for(int i = 0; i < n; i++){
            int r = l.nextInt(); 
            a[i] = r;
         } 
         Arrays.sort(a); 
         for(int z = n - 1; z >= 0 && m > 0; z-- , m--){
            System.out.println(a[z]);
         } 
         System.exit(0);
      }
   } 
