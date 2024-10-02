

class SimplePoint {

    private char pointName; 
    private double pointAbscisse;

    public SimplePoint(char name, double abscisse){
        pointName = name ;
        pointAbscisse = abscisse;
        
    }
    
    public void display(){
        System.out.println("Nom: "+ pointName +" "+"abscisse: "+ pointAbscisse);
    } 

    public void translate(double trans){
            pointAbscisse += trans;

    }

    public String toString(){
        return( pointName+": "  + pointAbscisse);
    }

    // public static void main(String[] args) {
    //     SimplePoint p = new SimplePoint('P', 11.3);
    //     SimplePoint d = new SimplePoint('A', 13.3);
    //     p.display();
    //     p.translate(10);
    //     p.display();

    //     System.out.println("The points are: " + p + " " + d);
        

    // }

    
}

// class SimplePoint { char pointName; double pointAbscisse; 
//     public SimplePoint(char name, double abscisse){ pointName = name ; pointAbscisse = abscisse;
//  } public void display(){ System.out.println("Nom: "+ pointName +" "+"abscisse: "+ pointAbscisse); } public void translate(double trans){ if(trans>0){ pointAbscisse += trans; } else{ pointAbscisse -= trans; } } public String toString(){ return( pointName + " " + pointAbscisse); } public static void main(String[] args) { SimplePoint p = new SimplePoint('P', 11.3); SimplePoint d = new SimplePoint('A', 13.3); p.display(); p.translate(10); p.display(); System.out.println("The points are: " + p + " " + d); } }
// Both attributes shoud be private! One of type char, one of type double!