// Problem statement: Given an array stalls[] representing the positions of stalls and an integer k denoting the number of aggressive cows, 
// place the cows in the stalls such that the minimum distance between any two cows is as large as possible. Return this maximum possible minimum distance.
import java.util.*;
public class AggresiveCows{
    public static int aggresiveCows(int stalls[], int k){
        Arrays.sort(stalls);
        int ans=0;

        int l=0;
        int h=stalls[stalls.length-1]-stalls[0];

        while(l<=h){
            int mid=l+(h-l)/2;

            if(isPossible(mid,k,stalls)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }

    private static boolean isPossible(int mid, int k, int[] stalls) {
        int placed=1;
        int pos=stalls[0];

        for(int i=1;i<stalls.length;i++){
            if(stalls[i]-pos>=mid){
                placed++;
                pos=stalls[i];
            }
            if(placed==k){
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int stalls[]={1,2,4,8,9};
        int k=3;
        System.out.println(aggresiveCows(stalls, k));
    }
}