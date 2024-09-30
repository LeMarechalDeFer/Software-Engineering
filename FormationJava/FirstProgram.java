
// ... est un varargs

public class FirstProgram {
    public static void main(String... args) {
        System.out.println("Hello World");
        int sum = sumOf(1,3,2,4,6) ;

        System.out.println(sum);
    }


    public static double add(double a, double b) {
        return a + b;
    }

    public static int sumOf(int... args){
        int sum = 0;
        for(int i=0; i<args.length ;i++){
            sum += args[i];
        }

        return sum;
    }

    // public static void averageOfStudent(){


    //     int... ArrayList = [0];
    //     while (ArrayList[i] >= 0 ) {
    //         System.out.println("Entrez une note (entrez un nombre négatif pour arrêter) :") ;
         
    //         System.in.read();    
    //     }
        
        
    // }
}