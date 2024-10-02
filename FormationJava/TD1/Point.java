class Point {
	private int abscissa;
	private int ordinate;
	
	public Point (int a, int o) {
		this.abscissa = a;
		this.ordinate = o;
	}

	// public void display () {
	// 	System.out.println("abscissa: " + this.abscissa + " ordinate: " + this.ordinate);
	// }

    public void setAbscissa (int abs){
        this.abscissa = abs ;
    }
    
    
    public void setOrdinate (int ord){
        this.ordinate = ord;
    } 

    public int getAbscissa(){
        return(this.abscissa);
    }

    public int getOrdinate(){
        return(this.ordinate);
    }

    // your code here
	
}