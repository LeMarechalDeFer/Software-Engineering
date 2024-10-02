class Vector3d {

    private double Vcoordonne_1 ;
    private double Vcoordonne_2 ; 
    private double Vcoordonne_3 ;

    public Vector3d(double coordonne_1, double coordonne_2, double coordonne_3){
        this.Vcoordonne_1 = coordonne_1 ;
        this.Vcoordonne_2 = coordonne_2 ;
        this.Vcoordonne_3 = coordonne_3 ;
    }

    public String toString(){
        return("<"+this.Vcoordonne_1+", "+this.Vcoordonne_2+", "+this.Vcoordonne_3+" >");
    }

    public void display(){
        System.out.println(toString());
    }

    public double norm(){
        //double vnorm = (coordonne_1*coordonne_1)+(coordonne_2*coordonne_2)+(coordonne_3*coordonne_3);

        double vnorm = Math.pow(this.Vcoordonne_1, 2)+Math.pow(this.Vcoordonne_2, 2)+Math.pow(this.Vcoordonne_3, 2);
        vnorm = Math.sqrt(vnorm);
        return(vnorm);
    } 

    public static Vector3d addition(Vector3d v1, Vector3d v2){
        Vector3d result = new Vector3d(
            v1.Vcoordonne_1 + v2.Vcoordonne_1,
            v1.Vcoordonne_2 + v2.Vcoordonne_2,
            v1.Vcoordonne_3 + v2.Vcoordonne_3
        );
        return result;
    }

    public double scalarProduct(Vector3d v){
        double result ; 
        result = (v.Vcoordonne_1*this.Vcoordonne_1)+(v.Vcoordonne_2*this.Vcoordonne_2)+(v.Vcoordonne_3*this.Vcoordonne_3);
        return result;
    }

    // public static void main(String... args){
    //     //test toString() & display 
    //     var v = new Vector3d (1.1, 2.2, 3.3);
    //     System.out.println(v);
    //     v.display();

    //     System.out.println(v.norm());

    
    //         var v1 = new Vector3d (1.1, 2.2, 3.3);
    //         var v2 = new Vector3d (1.0, 2.0, 3.0);
    //         System.out.println(Vector3d.addition(v1,v2));
    // }


}
