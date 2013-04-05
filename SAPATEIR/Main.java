   import java.util.StringTokenizer; 
   class Main{ 
      static int numVisitados = 0; 
      static void dfs(int vertice, boolean[] visitados, int arestaIgnorada, 
      int[][] arestasPorConf, int[] grau, int[][] arestas) { 
         visitados[vertice] = true; 
         numVisitados++; 
         for (int i = 0; i < grau[vertice]; i++) { 
            int aresta = arestasPorConf[vertice][i]; 
            if (aresta == arestaIgnorada) { 
               continue; 
            } 
            int outroVert = arestas[aresta][0]; 
            if (outroVert == vertice) { 
               outroVert = arestas[aresta][1]; 
            } 
            if (!visitados[outroVert]) { 
               dfs(outroVert, visitados, arestaIgnorada, arestasPorConf, grau, 
                  arestas); 
            } 
         } 
      } 
      static boolean conectado(int arestaIgnorada, int nVertices, int nArestas, 
      int[] grau, int[][] arestasPorConf, int[][] arestas) { 
         boolean[] visitados = new boolean[nVertices + 1]; 
         numVisitados = 0; 
         int empt = 0; 
         for (int i = 1; i <= nVertices; i++) { 
            if (grau[i] == 0) 
               empt++; 
         } 
         int i = 1; 
         while (grau[i] == 0) { 
            i++; 
         } 
         dfs(i, visitados, arestaIgnorada, arestasPorConf, grau, arestas); 
         return numVisitados == nVertices - empt; 
      } 
      static String readln() { 
         String newLine = System.getProperty("line.separator"); 
         StringBuffer buffer = new StringBuffer(); 
         int car = -1; 
         try { 
            car = System.in.read(); 
            while ((car > 0) && (car != newLine.charAt(0))) { 
               buffer.append((char) car); 
               car = System.in.read(); 
            } 
            if (car == newLine.charAt(0)) 
               System.in.skip(newLine.length() - 1); 
         } 
            catch (java.io.IOException e) { 
               return (null); 
            } 
         if ((car < 0) && (buffer.length() == 0)) 
            return (null); 
         if (buffer.length() == 0) 
            return ""; 
         return (buffer.toString()).trim(); 
      } 
      public static void main(String[] args) { 
         StringBuffer saida = new StringBuffer(); 
         while (true) { 
            StringTokenizer config = new StringTokenizer(readln().trim()); 
            int N = Integer.parseInt(config.nextToken()); 
            int C = Integer.parseInt(config.nextToken()); 
            if (N == 0 && C == 0) { 
               break; 
            } 
            int[] grau = new int[C + 1]; // C vertices 
            int[][] cidades = new int[N + 1][2]; 
            int[][] arestasPorConf = new int[C + 1][N + N + 1]; 
            for (int i = 1; i <= C; i++) { 
               config = new StringTokenizer(readln().trim()); 
               int K = Integer.parseInt(config.nextToken()); 
               for (int j = 1; j <= K; j++) { 
                  int cid = Integer.parseInt(config.nextToken()) + 1; 
                  arestasPorConf[i][grau[i]++] = cid; 
                  if (cidades[cid][0] == 0) {
                     cidades[cid][0] = i; 
                  } 
                  else { 
                     cidades[cid][1] = i; 
                  } 
               } 
            } 
            for (int i = 1; i <= N; i++) { 
               if (cidades[i][1] == 0) { 
                  int u = cidades[i][0]; 
                  cidades[i][1] = u; 
                  arestasPorConf[u][grau[u]++] = i; 
               } 
            } 
            int numeroDeGrauImpar = 0; 
            for (int i = 1; i <= C; i++) { 
               if (grau[i] % 2 == 1) { 
                  if (++numeroDeGrauImpar > 2) { 
                     break; 
                  } 
               } 
            } 
            int sol = 0; 
            if (conectado(-1, C, N, grau, arestasPorConf, cidades)) { 
               if (numeroDeGrauImpar == 0) { 
                  sol = 1; 
               } 
               else if (numeroDeGrauImpar == 2) { 
                  sol = -1; 
                  for (int i = 1; i <= N; i++) { 
                     if (grau[cidades[i][0]] % 2 == 0 
                     && grau[cidades[i][1]] % 2 == 0) { 
                        continue; 
                     } 
                     else { 
                        if (grau[cidades[i][0]] == 1 
                        || grau[cidades[i][1]] == 1 
                        || conectado(i, C, N, grau, arestasPorConf, 
                        cidades)) { 
                           sol = i; 
                           break; 
                        } 
                     } 
                  } 
               } 
               else { 
                  sol = -1; 
               } 
            } 
            else { 
               sol = -1; 
            } 
            saida.append((sol == -1 ? sol : sol - 1) + "\n"); 
         } 
         System.out.print(saida); 
      } 
   } 
