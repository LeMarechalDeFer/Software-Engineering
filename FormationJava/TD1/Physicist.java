
import java.time.LocalDate;

class Physicist {

    private String physicistName;
    private String physicistCountry;
    private java.time.LocalDate physicistBirthday;

    
  
    public Physicist(String name, java.time.LocalDate birthday, String country){
        this.physicistName = name ;
         if(birthday.isBefore(java.time.LocalDate.of(1, 1, 1)) || birthday.isAfter(java.time.LocalDate.of(2024, 10, 02))){
            this.physicistBirthday = null;
        }
        else{
            this.physicistBirthday = birthday;
        }
        
        this.physicistBirthday = birthday;
    }

    public Physicist(String name, java.time.LocalDate birthday){
        this.physicistName = name ;
        if(birthday.isBefore(java.time.LocalDate.of(1, 1, 1)) || birthday.isAfter(java.time.LocalDate.of(2024, 10, 02))){
            this.physicistBirthday = null;

        }
        else{
            this.physicistBirthday = birthday;
        }
        this.physicistCountry = null;
    }

    public Physicist(String name){
        this.physicistName = name ;
        this.physicistBirthday = null;
        this.physicistCountry = null;
    }

    public String toString(){

        if(physicistCountry == null && physicistBirthday==null){
            return(physicistName);
        }
        else if(physicistCountry == null){
            return(physicistName +"," + physicistBirthday);
        }
        else if(physicistBirthday == null){
                return(physicistName +"," + physicistCountry);
        }else {
            return(physicistName +"," + physicistBirthday +","+physicistCountry);
        }
    }


    public void setBirthDate(LocalDate newBirthday) {
        if(newBirthday.isBefore(java.time.LocalDate.of(1, 1, 1)) || newBirthday.isAfter(java.time.LocalDate.of(2024, 10, 02))){
             
        }
        else{
            this.physicistBirthday = newBirthday;
        }
    }


}
