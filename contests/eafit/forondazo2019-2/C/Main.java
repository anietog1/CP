import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        while(n-- != 0) {
            BigInteger Y = new BigInteger(sc.next());

            BigInteger xn0 = BigInteger.ZERO.setBit(Y.bitLength() / 2);
            BigInteger xn1 = xn0.add(Y.divide(xn0)).shiftRight(1);

            while(xn0.compareTo(xn1) != 0) {
                xn0 = xn1;
                xn1 = xn0.add(Y.divide(xn0)).shiftRight(1);
            }

            System.out.println(xn0);

            if(n != 0) {
                System.out.println();
            }
        }
    }
}
