import java.util.*;

public class Hotpotato{

    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	System.out.println("Ingrese la cantidad de qersonas");
	int n = sc.nextInt();
	LinkedList<String> q = new LinkedList();

	while(n>0){
	    String name = sc.next();
	    q.add(name);
	    n--;
	}
	
	System.out.println("Ingrese num, # de giros.");
	n = sc.nextInt();
	hotPotato(q,n);
    }

    static void hotPotato(LinkedList<String> q, int num){
	while(q.size() > 1){
	    for(int i=1; i<=num; i++)
		q.add(q.remove());
	    System.out.println("Sale " + q.remove());
	}
	
	System.out.println("Queda: " + q.remove());
    }


}
