import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        BigInteger fibo[] = new BigInteger[1010];
        fibo[0] = BigInteger.ZERO;
        fibo[1] = BigInteger.ONE;

        for(int i = 2; i < 1010; ++i) {
            fibo[i] = fibo[i - 1].add(fibo[i - 2]);
        }

        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(fibo[n + 2]);
        }
    }
}
