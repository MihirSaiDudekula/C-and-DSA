import java.util.ArrayList;
public class GCD {

    public static void main(String[] args) {
        int n1 = 366, n2 = 60;
        int hcf1 = euclid_hcf(n1, n2);
        int hcf2 = consec_hcf(n1,n2);
        int hcf3 = midsch_hcf(n1,n2);

        System.out.printf("\nG.C.D of %d and %d is %d.\n", n1, n2, hcf1);
        System.out.printf("\nG.C.D of %d and %d is %d.\n", n1, n2, hcf2);
        System.out.printf("\nG.C.D of %d and %d is %d.\n", n1, n2, hcf3);
        
    }

    public static int euclid_hcf(int n1, int n2)
    {
        if (n2 == 0)
        {
            return n1;
        }
        else
        {
            int rem = n1 % n2;
            return euclid_hcf(n2, rem);
        }
            
    }
    
    public static int consec_hcf(int a,int b)
    {
        int cur_hcf=1;
        for(int i=1;i<=b;i++)
        {
            if(a%i==0 && b%i==0)
            {
                cur_hcf=i;
            }
        }
        return cur_hcf;
    }
    
    
    public static int midsch_hcf(int a,int b)
    {
        int cur_hcf=1;
        
        ArrayList<Integer> fac1 = new ArrayList<Integer>();
        ArrayList<Integer> fac2 = new ArrayList<Integer>();
        
        int c1 = 2;
        int c2 = 2;
        
        while(a!=1)
        {
            if((a%c1)==0)
            {
                fac1.add(c1);
                a = a/c1;
            }
            else
            {
                c1++;
            }
        }
        
        while(b!=1)
        {
            if((b%c2)==0)
            {
                fac2.add(c2);
                b = b/c2;
            }
            else
            {
                c2++;
            }
        }
        
        for (Integer element : fac1) {
            if(fac2.contains(element))
            {
                cur_hcf = cur_hcf * element;
            }
        }
        return cur_hcf;
        
    }
}
