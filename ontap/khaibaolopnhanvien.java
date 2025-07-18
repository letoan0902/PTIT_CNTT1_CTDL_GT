import java.util.Scanner;

class NhanVien{
    private String ma;
    private String hoTen;
    private String gioiTinh;
    private String ngaySinh;
    private String diaChi;
    private String maSoThue;
    private String ngayKyHopDong;

    public NhanVien(String hoTen, String gioiTinh, String ngaySinh, String diaChi, String maSoThue, String ngayKyHopDong){
        this.ma = "00001";
        this.hoTen = hoTen;
        this.gioiTinh=gioiTinh;
        this.diaChi=diaChi;
        this.ngaySinh = ngaySinh;
        this.maSoThue=maSoThue;
        this.ngayKyHopDong=ngayKyHopDong;
    }

    public String getNhanVien(){
        return ma+" "+hoTen+" "+gioiTinh+" "+ngaySinh+" "+ diaChi+" "+ maSoThue+ " "+ ngayKyHopDong;
    }

}


public class khaibaolopnhanvien {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a,b,c,d,e,f;
        a=sc.nextLine();
        b=sc.nextLine();
        c=sc.nextLine();
        d=sc.nextLine();
        e=sc.nextLine();
        f=sc.nextLine();
        NhanVien nv1 = new NhanVien(a,b,c,d,e,f);
        System.out.println(nv1.getNhanVien());
        sc.close();;
    }
}
