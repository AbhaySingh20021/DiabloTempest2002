import java.util.*;

 



public static void main(String[] args) {

    
    Scanner in = new Scanner(System.in);
    int max = in.nextInt();
    for (int i = 1; i <= max; i++) {
    	System.out.println(new String(new char[max-i]).replace("\0", " ") + new String(new char[i]).replace("\0", "#"));
    }
}
