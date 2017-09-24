import java.util.*;
import java.io.*;

public class Plates{
    private static int count(String str){
	Set<String> set = new TreeSet<>();
	for(int i=0; i<str.length() - 2; i++){
	    char first = str.charAt(i);
	    for(int j=i+1; j < str.length() - 1; j++){
		char second = str.charAt(j);
		for(int k=j+1; k < str.length(); k++){
		    char third = str.charAt(k);
		    StringBuilder s = new StringBuilder();
		    s.append(first);
		    s.append(second);
		    s.append(third);
		    set.add(s.toString());
		}
	    }
	}
	
	return set.size();
    }
    
    
    public static void main(String[] args) throws IOException{
	BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	String str;
	
	while((str = bf.readLine()) != null){
	    System.out.println(count(str));
	}
    }
}
