// package TD1;
//optionnel declaration de package (pour architecture)
//premiere declaration est la classe,
//deuxieme declaration est la methode,

//les types primitif
//l'interet des wrapper

public class Main {
	
    //Q1
    // public static void main(String[] args) {
    //     System.out.println("Hello World");
    // }

    //Q2
    // public static void main(String[] args) {
    //     int i = 0;
	//     while( i <10 ){
            
    //         System.out.println("Hello World");
    //         i++;
    //     }
	// }

    // Q3
    // public static void main(String[] args){
    //     int i = 0;
    //     StringBuilder sb = new StringBuilder();

    //     do {
    //         sb.append("Hello Word\n");    
    //         i++;
    //     } while (i<10);

    //     System.out.println(sb.toString());
    // }
    
    //Q4
    // public static void main(String[] args){

    //     for(int i=1; i<7; i++){
    //         System.out.println("Hello World "+ i);
    //     }
    // }

    //Q5
    // public static void main(String[] args){
    //     for (String string : args) {
    //         System.out.println(string);
    //     }
    // }

    //Q5bis
    // public class Main {
    //     public static void main(String[] args) {
    //         // Initialisation directe d'un tableau de chaînes
    //         String[] strings = {"one", "two", "three", null, "four", "five"};
    
    //         // Boucle for-each pour afficher chaque élément
    //         for (String string : strings) {
    //             System.out.println(string);
    //         }
    //     }
    // }
    

    //Q6
    // public static void main(String[] args){
    //     int i;
    //     for(i=1; i<= 5; i++){
    //         if(i==3){
    //             System.out.println("i = "+ i);
    //         }
    //         else{
    //             System.out.println("Hello World "+ i);
    //         }
    //     }
    // }

    //Q7
    public static void main(String[] args) {
        for (int i = 1; i <= 5; i++) {
            if (i == 3) {
                System.out.println(" Stop !");
                break; // Arrête la boucle lorsque i vaut 3
            } else {
                System.out.println("Hello World " + i);
            }
        }
    }

    // public static void main(String[] args) {
    //     for (int i = 1; i <= 5; i++) {
    //         if (i <= args.length && args[i - 1].equals("Stop")) {
    //             System.out.println("Stop");
    //             break; // Arrête la boucle lorsque "Stop" est trouvé
    //         } else {
    //             System.out.println("Hello World " + i);
    //         }
    //     }
    // }

   
    //Q8
    // public class Main{
    //     public static void main(String[] args) {
    //         // Initialisation du tableau bidimensionnel (matrice)
    //         int[][] matrix = {
    //             {1, 3, 5, 7},
    //             {2, 4, 6, 8},
    //             {9, 11, 13, 15}
    //         };
    
    //         // Parcourir la matrice avec deux boucles for imbriquées
    //         for (int i = 0; i < matrix.length; i++) {
    //             for (int j = 0; j < matrix[i].length; j++) {
    //                 // Afficher l'élément de la matrice
    //                 System.out.print(matrix[i][j] + " ");
    //             }
    //             // Retour à la ligne après chaque ligne de la matrice
    //             System.out.println();
    //         }
    //     }
    // }

    //Q10

    // class GetBinaryValue {
    //     public static void main(String[] args) {
            
    //         if (args.length == 0) {
    //             System.out.println("Usage: java GetBinaryValue <decimal integer>");
    //         } 
            
    //         else {
                
    //             System.out.println("Received " + args.length + " arguments.");
    //             System.out.println("The arguments are:");
    
                
    //             for (String arg : args) {
    //                 System.out.println(arg);
    //             }
    
    //             try {
                    
    //                 int firstNumber = Integer.parseInt(args[0]);
    
                  
    //                 String binaryValue = Integer.toBinaryString(firstNumber);
    //                 System.out.println("The binary representation of " + firstNumber + " is " + binaryValue);
    //             } catch (NumberFormatException e) {
    //                 System.out.println("Le premier argument doit être un entier valide.");
    //             }
    //         }
    //     }
    // }
    

    // class WrappersDemo {
    //     public static void main(String[] args) {
    //         if (args.length > 0) {
    //             Boolean boolValue = Boolean.parseBoolean(args[0]);
    //             System.out.println("value is: " + boolValue);
    //         } else {
    //             System.out.println("Aucun argument fourni.");
    //         }
    //     }
    // }

    class WrappersDemo {
        public static void main(String[] args) {
            
            if (args.length > 0) {
                try {
                  
                    long longValue = Long.parseLong(args[0]);
    
       
                    System.out.println("value is: " + longValue);
                } catch (NumberFormatException e) {
                    
                    System.out.println("L'argument doit être un entier valide.");
                }
            } else {
           
                System.out.println("Aucun argument fourni.");
            }
        }
    }
    
    
    
}
