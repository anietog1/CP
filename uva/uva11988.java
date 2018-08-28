import java.util.*;
import java.io.*;

public class uva11988{
    public static LinkedList<StringBuilder> brokenKeyboard(String input) {
        LinkedList<StringBuilder> list = new LinkedList<>();

        boolean atFirst = true;
        StringBuilder sb = new StringBuilder();

        int i = 0;
        while (i < input.length()) {
            if (!isBracket(input.charAt(i))){
                sb.append(input.charAt(i));
            } else {
                add(sb, list, atFirst);
                sb = new StringBuilder();
                atFirst = input.charAt(i) == '[';
            }
            
            i++;
        }
        
        if(sb.length() > 0) add(sb, list, atFirst);
        return list;
    }
    
    private static void add(StringBuilder sb,
			    LinkedList<StringBuilder> list, boolean atFirst){
        if (atFirst) list.addFirst(sb);
        else list.addLast(sb);
    }
    
    private static boolean isBracket(char o) {
        return o == '[' || o == ']';
    }

    public static void testKeyboard() throws IOException{
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
	String s;
	while ((s = br.readLine()) != null && !s.equals("")) {
	    brokenKeyboard(s).forEach((str) -> {
		    pw.print(str);
	    });
	    pw.println();
	    pw.flush();
	}
	pw.close();
    }

    public static void main(String[] args) throws IOException{
	testKeyboard();
    }
}
