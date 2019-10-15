package diff_utility_dp;

public class Diff_Utility_DP {

    int lcs(String s, String p, int table[][], int n) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    table[i][j] = 0;
                } else if (s.charAt(i - 1) == p.charAt(j - 1)) {
                    table[i][j] = table[i - 1][j - 1] + 1;
                } else {
                    table[i][j] = Integer.max(table[i - 1][j], table[i][j - 1]);
                }
            }
        }

        return table[n][n];
    }

    void diff_utility(String x, String y, int[][] table, int m, int n) {

        if (m>0&&n>0&&x.charAt(m - 1) == y.charAt(n - 1)) {
            diff_utility(x, y, table, m - 1, n - 1);
            
            System.out.print(x.charAt(m - 1));
           
        }
        
        else if (n > 0 && (m == 0 || table[m][n - 1] >= table[m - 1][n])) {
             
            diff_utility(x,y,table,m,n-1);
            System.out.print("+" + y.charAt(n - 1));
          
        }
        
        else if (m > 0 && (n == 0 || table[m][n - 1] < table[m - 1][n])) {
            
              diff_utility(x,y,table,m-1,n);
            System.out.print("-" + x.charAt(m - 1));
           
        }
    }

    
    
    public static void main(String[] args) {
        Diff_Utility_DP ob = new Diff_Utility_DP();

        String x = "XMJYAUZ";
        String y = "XMJAATZ";
        int table[][] = new int[x.length() + 1][y.length() + 1];
        System.out.println("the lcs length is: " + ob.lcs(x, y, table, x.length()));
        System.out.println();
        System.out.println("the lcs table is : ");
        for (int i = 0; i <= x.length(); i++) {
            for (int j = 0; j <= x.length(); j++) {
                System.out.print(table[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println();
        int m = x.length() ;
        int n = y.length();
        ob.diff_utility(x, y, table, m, n);
        
        System.out.println();

    }

}
