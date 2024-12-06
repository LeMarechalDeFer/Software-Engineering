// The necessary packages are already included
// Copy all the classes you've implemented
// However, Point3D already exists, so there's no need to include it.

// Engine[id=0, name=null, manDate=null, force=0][fuelLevel=0]
// Machine[id=0, name=null, manDate=null, force=0]
// Vehicle[id=0, name=null, manDate=null, force=0][wheels=[Wheel[brand=unknown]], position=Point3D[x=0, y=0, z=0]]
// MotorVehicle[id=0, name=null, manDate=null, force=0][wheels=[Wheel[brand=unknown]], position=Point3D[x=0, y=0, z=0]][engines=[]]


// import java.time.LocalDate;
// import java.util.ArrayList;
// import java.util.Arrays;


public class Tool{
    //class vide
    }
    
    interface Powered{
        int getForce();
    }
    
    interface Motorized extends Powered{
        int getFuellevel();
    }
    
    public class TooFarException extends Exception{
        private Point3D from;
        private Point3D to;
    
        
        public TooFarException(){
        }
        public TooFarException(String message){
            super(message);
        }
        public TooFarException(Point3D from, Point3D to){
            this.from = from;
            this.to = to;
        }
        // public String toString(){
        //     return("TooFarException[from="+this.from+", to="+this.to+"]");
        // }
        //^prévention des uknow
         @Override
        public String toString() {
            return "TooFarException[from=" + (this.from != null ? this.from : "unknown") +
                   ", to=" + (this.to != null ? this.to : "unknown") + "]";
        }
    }
    
    interface Mobile{
        int LIMIT = 1000;
        Point3D getPosition();
        void goTo(Point3D position) throws TooFarException;
    }
    
    
    
    public class Machine extends Tool implements Powered{
        private int id;
        private String name;
        private LocalDate manDate;
        private int force ;
        
        
        public Machine(){
        }
    
        public Machine(int id, String name, LocalDate manDate, int force){
            this.id = id ;
            this.name = name ;
            this.manDate = manDate ;
            this.force = force ; 
        }
        
        @Override
        public int getForce(){
            return this.force ;
        } 
        
        @Override 
        public String toString(){
            return("Machine[id="+this.id+", name="+this.name+", manDate="+this.manDate+", force="+this.force+"]");
        }
        
        @Override
        public boolean equals(Object objet){
            if(this == objet){
                return true;
            }
            
            if(!(objet instanceof Machine)){
                return false;
            }
    
            if (objet == null || getClass() != objet.getClass()) {
                return false; 
            }
            
            Machine other = (Machine) objet ;
            
            // return(
            //     this.id == other.id && Objects.equals(this.name, other.name) && Objects.equals(this.manDate, other.manDate) && this.force == other.force
            //     );
            return this.id == other.id &&
               Objects.equals(this.name, other.name) &&
               Objects.equals(this.manDate, other.manDate) &&
               this.force == other.force;
        }
        
        @Override 
        public int hashCode(){
            return Objects.hash(id, name, manDate, force);
        }
        
    }
    
    
    public class Engine extends Machine{
        private int fuelLevel; 
        
        public Engine(){
        }
        public Engine(int id, String name, LocalDate manDate, int force, int fuelLevel){
            super(id, name, manDate, force);
            this.fuelLevel = fuelLevel;
        }
    
    
        public int getFuellevel(){
            return this.fuelLevel;
        }
    
        public void setFuelLevel(int fuelLevel){
            this.fuelLevel = fuelLevel;
        }
        
        //Engine[id=0, name=null, manDate=null, force=0][fuelLevel=0]
        // @Override
        // public String toString(){
        //     return super.toString()+"[fuelLevel="+this.fuelLevel+"]";
        // }
        @Override
        public String toString() {
            return "Engine" + super.toString().substring(7) + "[fuelLevel=" + this.fuelLevel + "]";
        }
    
        @Override
        public boolean equals(Object objet){
            if(this == objet){
                return true;
            }
            
            if(!(objet instanceof Engine)){
                return false;
            }
            
            Engine other = (Engine) objet ;
            
            return(
                super.equals(other) && this.fuelLevel == other.fuelLevel
                );
        }
    
        @Override
        public int hashCode(){
            return (Objects.hash(super.hashCode(), fuelLevel));
        }
    }
    
    public class MotorVehicle extends Vehicle implements Motorized{
        private ArrayList<Engine> engines;
    
        public MotorVehicle(){
        }
    
        public MotorVehicle(int id, String name, LocalDate manDate, int force, Wheel[] wheels, Point3D position, Engine... engines) {
            super(id, name, manDate, force, wheels, position);
            this.engines = new ArrayList<>(Arrays.asList(engines)); 
        }
    
        public void addEngine(Engine engine) {
        if (this.engines == null) {
            this.engines = new ArrayList<>(); 
        }
        this.engines.add(engine);
    }
    
        // @Override
        // public String toString(){
        //     return super.toString() + "[engines=" + (engines != null ? engines : "[]") + "]";
        // }
        @Override
        public String toString() {
            return "MotorVehicle" + super.toString().substring(7) +
                "[engines=" + (engines != null ? engines : "[]") + "]";
        }
    
    
        @Override
        public boolean equals(Object objet){
            if(this == objet){
                return true;
            }
            
            if(!(objet instanceof MotorVehicle)){
                return false;
            }
            
            MotorVehicle other = (MotorVehicle) objet ;
            
            return(
                super.equals(other) && Objects.equals(this.engines, other.engines)
                );
        }
    
        @Override
        public int hashCode(){
            return Objects.hash(super.hashCode(), engines);
        }
    
        @Override
        public void goTo(Point3D position) throws TooFarException {
            // if (this.position.distance(position) > Mobile.LIMIT) {
            //     throw new TooFarException(this.position, position);
            // }
    
            // super.goTo(position);
    
                if (this.position.getDistance(position) > Mobile.LIMIT) {
                throw new TooFarException(this.position, position);
            }
            this.position = position; 
        }
    
    
        public int getForce(){
            int force = 0;
            for(Engine engine : engines){
                force += engine.getForce();
            }
            return force;
        }
    
        public int getFuellevel(){
            int fuelLevel = 0;
            for(Engine engine : engines){
                fuelLevel += engine.getFuellevel();
            }
            return fuelLevel;
        }
    
        // @Override
        // protected int rank(){
        //     int forceRank = this.getForce(); 
        //     return forceRank ;
        // }
    
        @Override
        protected int rank() {
            int forceRank = this.getForce(); 
            int fuelRank = this.getFuellevel(); 
            // int wheelRank = this.wheels != null ? this.wheels.length : 0; 
            return forceRank * 1000 + fuelRank ;
        }
    
    }
    
    public class Vehicle extends Machine implements Mobile, Comparable<Vehicle>{
        private Wheel[] wheels;
        protected Point3D position;
    
        public Vehicle(){
            this.position = new Point3D(0, 0, 0);
        }
    
        public Vehicle(int id, String name, LocalDate manDate, int force, Wheel[] wheels, Point3D position){
            super(id, name, manDate, force);
            this.wheels = wheels;
            this.position = position;
        }
        
        // @Override
        // public String toString() {
        //     return super.toString() +
        //            "[wheels=" + (wheels != null ? Arrays.toString(wheels) : "[Wheel[brand=unknown]]") +
        //            ", position=" + (position != null ? position : "Point3D[x=0, y=0, z=0]") + "]" + "]";
        // }
        @Override
        public String toString() {
            return "Vehicle" + super.toString().substring(7) +
                "[wheels=" + (wheels != null ? Arrays.toString(wheels) : "[Wheel[brand=unknown]]") +
                ", position=" + (position != null ? position : "Point3D[x=0, y=0, z=0]") + "]";
        }
    
        @Override
        public boolean equals(Object objet){
            if(this == objet){
                return true;
            }
            
            if(!(objet instanceof Vehicle)){
                return false;
            }
            
            Vehicle other = (Vehicle) objet ;
            
            return(
                super.equals(other) && Arrays.equals(this.wheels, other.wheels) && Objects.equals(this.position, other.position)
                );
        }
    
        @Override
        public int hashCode(){
            return Objects.hash(super.hashCode(), Arrays.hashCode(wheels), position);
        }
    
        
        @Override
        public int compareTo(Vehicle other) {
            if (this == other) {
                return 0; 
            }
            return Integer.compare(this.rank(), other.rank());
        }
    
        public Point3D getPosition(){
            return this.position;
        }
    
        @Override
        public void goTo(Point3D position) throws TooFarException {
    
            if (this.position.getDistance(position) > Mobile.LIMIT) {
                throw new TooFarException(this.position, position);
            }
            this.position = position; 
        }
    
    
        protected int rank() {
            return this.wheels != null ? this.wheels.length : 0;
        }
    
    
        
      
    }
    
    public class Wheel{
        private String brand;
    
        public Wheel(){
        }
        public Wheel(String brand){
            this.brand = brand;
        }
    
        @Override
        public String toString() {
            return "Wheel[brand=" + (this.brand != null ? this.brand : "unknown") + "]";
        }
    
        @Override
        public boolean equals(Object objet){
            if(this == objet){
                return true;
            }
            
            if(!(objet instanceof Wheel)){
                return false;
            }
            
            Wheel other = (Wheel) objet ;
            
            return(
                Objects.equals(this.brand, other.brand)
                );
        }
    
        @Override
        public int hashCode(){
            return Objects.hash(brand);
        }
    }
    
    
    
    public final class Bicycle extends Vehicle{
    //class vide
    }
    
    public final class Car extends MotorVehicle{
    //class vide
    }
    
    public final class Bus extends MotorVehicle{
    //class vide 
    }
    
    