/*  Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 You have the following three operations permitted on a word:

 Insert a character
 Delete a character
 Replace a character */
import java.util.*;
/*  express in terms of (i,j)
 explore all paths of matching
 return min(all paths)
 Base case

 steps
 1+f(i,j-1) --> insert operation because we hypothetically introduce somnething ahead of bigger string
 1+f(i-1,j) --> delete operation
 1+f(i-1,j-1) --> replace the char in string

base case-->
 if string 1 gets exhausted then, eg f(i,j)-> f(-1,1)--> min operations to convert an empty string to a string with present index 1 will be 2
 which means we will return j+1 --> if(i<0){ return j+1 ;}

 if string 2 which is the smaller string gets exhausted then we require i+1 delete operations to delete the larger string
 if(j<0){ return i+1; }*/
public class EditDistance {
    public static int editDistance(String s1,String s2,int i, int j, int[][] dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // if the characters at the current positions match, no edit is needed
        if(s1.charAt(i)==s2.charAt(j)){
            return dp[i][j]=0+editDistance(s1, s2, i-1, j-1, dp);
        }

        //minimum of three choices:
        //1. Replace the character s1 with character s2
        //2. delete the character in s1
        //3. insert the character from s2 into s1

        else{
            int op1=1+editDistance(s1, s2, i-1, j-1, dp);
            int op2=1+editDistance(s1, s2, i-1, j, dp);
            int op3=1+editDistance(s1, s2, i, j-1, dp);

            return dp[i][j]=1+Math.min(op1,Math.min(op2,op3));
        }
    }
    public static int editDistance1(String S1, String S2) {
        int n = S1.length();
        int m = S2.length();

        int[][] dp = new int[n][m];
        for (int row[] : dp)
            Arrays.fill(row, -1);

        // Call the recursive helper function
        return editDistance(S1, S2, n - 1, m - 1, dp);
    }

    public static int editDistanceTabulation(String s1,String s2){
        int m=s1.length();
        int n=s2.length();

        int[][] dp=new int[m+1][n+1];

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j]=1+Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
    }

    public static void main(String[] args) {
        String s1 = "horse";
        String s2 = "ros";

        System.out.println("The minimum number of operations required is: " +editDistance1(s1, s2));
    }
}