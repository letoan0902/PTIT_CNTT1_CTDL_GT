import java.util.Scanner;
import java.util.Arrays;

public class sapxepdayso {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        while(n>0){
            int a = sc.nextInt();
            int arr[] = new int[a];
            for(int i=0;i<a;i++){
                arr[i]=sc.nextInt();
            }
            Arrays.sort(arr);
            for(int i=0;i<a;i++){
                System.out.print(arr[i]+" ");
            }
            System.out.println();
            n--;
        }
        
        sc.close();
    }
    
}
