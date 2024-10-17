class Vehicle {
    private String maker;
    private String model;
    
    public Vehicle(String maker, String model){
        this.maker = maker;
        this.model = model; 
    }

    public String toString(){
        return(this.maker +" "+ this.model);
    }
}


class Car extends Vehicle{
    
    private int year ;
    public Car(String maker, String model, int year){
        super(maker, model);
        this.year = year;
    }

    @Override
    public String toString(){
        return(super.toString()+" "+this.year);
    }
}

class Train extends Vehicle{

    private String country;
    
    public Train(String maker, String model, String country){
        super(maker, model);
        this.country = country;
    }

    @Override
    public String toString(){
        return(super.toString()+" "+this.country);
    }
}
