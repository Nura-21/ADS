import java.util.*;
public class l2{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m;
        while(n > 0){
            m = 0;
            int l = scan.nextInt();
            int[] arr = new int[l+1];
            int[] arr1 = new int[l+1];
            for (int i = 1; i <= l; i++) {
                arr[i] = scan.nextInt();
                arr1[i] = arr[i];
            }
            for (int i = 1; i <= l; i++) {
                int pos = i + arr[i];
                if(pos <= l){
                    arr1[pos] = Math.max(arr1[pos], arr1[i] + arr[pos]);
                }
                m = Math.max(m, arr1[i]);
            }
            System.out.println(m);
            n--;
        }
    }
}
