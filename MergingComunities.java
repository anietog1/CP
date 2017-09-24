import java.util.*;

public class MergingComunities {
    static int[] p, rank, size;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n, q, i, j;
        n = sc.nextInt() + 1;
        p = new int[n];
        rank = new int[n];
        size = new int[n];
        
        for(int r=0; r<n; r++){
            p[r] = r;
            size[r] = 1;
        }
        
        q = sc.nextInt();
        while(q > 0){
            char o = sc.next().charAt(0);
            if(o == 'M'){
                i = sc.nextInt();
                j = sc.nextInt();
                merge(i, j);
            }else{
                i = sc.nextInt();
                System.out.println(sizeOf(i));
            }
            q--;
        }
    }
    
    static void merge(int i, int j){
        int x = findSet(i);
        int y = findSet(j);
        
        if(x!=y){
            if(rank[x] > rank[y]){
                p[y] = x;
                size[x] += size[y];
            }else{
                p[x] = y;
                size[y] += size[x];
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    
    static int sizeOf(int i){
        return size[i];
    }
    
    static int findSet(int i){
        return p[i] == i? i : findSet(p[i]);
    }
}
