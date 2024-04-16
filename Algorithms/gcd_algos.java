public class GCD {

    public static void main(String[] args) {
        int n1 = 366, n2 = 60;
        int hcf = consec_hcf(n1, n2);

        System.out.printf("G.C.D of %d and %d is %d.", n1, n2, hcf);
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
    
    
    public int midsch_hcf(int a,int b)
    {
        
    }
}
