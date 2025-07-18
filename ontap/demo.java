import java.util.Scanner;

public class demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Nhap ten cua ban: ");
        String c = sc.nextLine();
        System.out.println("Xin chao: "+c);
        sc.close();
    }
}
