class factorial{
    static int fact(int n,int product){
        if(n<=1)
            return product;
        return fact(n-1,product*n);
    }
    public static void main(String [] args){
        System.out.println("Factorial: "+ fact(5,1));
    }
}