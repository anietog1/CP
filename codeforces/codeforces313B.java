import java.util.*;
import java.io.*;

public class codeforces313B {
    public static void codeForcesChallenge(){
        Scanner sc = new Scanner(System.in);

        String s = sc.next();

	int[] acum = new int[s.length()];
        acum[0] = 0;
        for(int i=1; i<acum.length; i++){
	    acum[i] = acum[i-1];
	    if(s.charAt(i) == s.charAt(i-1))
		acum[i]++;
	}

	// for(int i: acum)
	//     System.out.print(i);

        int n = sc.nextInt();

        while(n > 0){
            int l = sc.nextInt() - 1;
            int r = sc.nextInt() - 1;

            System.out.println(acum[r] - acum[l]);
            n--;
        }
    }
    
    public static void main(String[] args) throws IOException{
	codeForcesChallenge();
    }
}
