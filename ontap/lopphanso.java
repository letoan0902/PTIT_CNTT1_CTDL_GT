import java.util.Scanner;
public class lopphanso {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long ucln = ucln(a,b);
        a = a / ucln;
        b = b / ucln;
        System.out.println(a + "/" + b);
        sc.close();
    }

    static long ucln(long a, long b) {
        if(b == 0) return a;
        return ucln(b, a % b);
    }
}
