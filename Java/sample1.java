import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class sample1 {
    private int xy;
    public static void main(String[] args) {
        System.out.println("Hare Krishna");    
        int a;
        boolean b;
        String c=new String("Hare");
        a=10;
        b=false;
        if(!b){
            System.out.println(a + " " +  b + " " + c + " ");
        }
        int i=0;
        do{
            System.out.println(i);
            i++;
        }while(i<10);
        for(i=0;i<10;i++){
            System.out.print(i+" ");
        }
        System.out.println();

        int[] arr1=new int[5];
        Arrays.fill(arr1,-1);
        int arr2[]=new int[5];
        for(int p:arr1){
            System.out.print(p);
        }
        System.out.println();
        for(i=0;i<arr2.length;i++){
            arr2[i]=i+1;
            System.out.print(arr2[i]);
        }
        System.out.println(meth());
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int ax=0;
        try{
            ax=br.read();
        }catch(IOException ioe){

        }
        System.out.print(ax);
    }

    public static String meth(){
        sample1 s=new sample1();
        s.xy=2;
        return "Haribol"+s.xy+s.getxy()+s;
    }
    public int getxy(){
        return this.xy;
    }
    public String toString(){
        return "The value of xy is:"+this.xy;
    }
}
