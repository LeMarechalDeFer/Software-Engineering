// class Point {
// 	private int abscissa;
// 	private int ordinate;
	
// 	public Point (int a, int o) {
// 		this.abscissa = a;
// 		this.ordinate = o;
// 	}

// 	// public void display () {
// 	// 	System.out.println("abscissa: " + this.abscissa + " ordinate: " + this.ordinate);
// 	// }

//     public void setAbscissa (int abs){
//         this.abscissa = abs ;
//     }
    
    
//     public void setOrdinate (int ord){
//         this.ordinate = ord;
//     } 

//     public int getAbscissa(){
//         return(this.abscissa);
//     }

//     public int getOrdinate(){
//         return(this.ordinate);
//     }

//     // your code here
	
// }

class Point { 
    private int x, y;	//abscissa and ordinate 

    public Point (int abs, int ord)  { 
        x = abs; 
        y = ord;
    } 

    public void translate (int d) {
        x += d; 
        y += d; 
    } 
    
    public int getX() { return x; } 

    public int getY() { return y; } 

    public String toString(){
        return("["+x+","+y+"]");
    }
    
}


class Point3D extends Point {
    private int z ;

    public Point3D (int abs, int ord, int z ){
        super(abs, ord);
        this.z = z;
    }

    public int getZ(){return z;}

    public void setZ(int z){this.z=z; }

    // @Override
    // public String toString(){
    //     return("["+getX()+","+getY()+","+z+"]");
    // }

    @Override
    public String toString(){
        
        return (super.toString()+ "[" + z + "]");
    }


    @Override
    public void translate(int d){
        super.translate(d);
        this.z += d; 
    }
}


// // Classe Main pour tester Point et Point3D
// public class Main {
//     public static void main(String[] args) {
//         // Test de la classe Point
//         Point p = new Point(1, 2);
//         System.out.println("Point initial: " + p);  // Affiche [1,2]
//         p.translate(3);
//         System.out.println("Point après translation de 3: " + p);  // Affiche [4,5]

//         // Test de la classe Point3D
//         Point3D p3d = new Point3D(1, 2, 3);
//         System.out.println("Point3D initial: " + p3d);  // Affiche [1,2][3]
//         p3d.translate(2);
//         System.out.println("Point3D après translation de 2: " + p3d);  // Affiche [3,4][5]
        
//         // Modification de la coordonnée z
//         p3d.setZ(10);
//         System.out.println("Point3D après modification de z: " + p3d);  // Affiche [3,4][10]
//     }
// }