
import java.util.Scanner;

class UppercaseName
{
	public static void main (String args[])
	{
	    String[] nameList = new String[5];
	    Scanner scanner = new Scanner(System.in);
		
		for (int i = 0; i < 5; i++) {
			nameList[i] = scanner.nextLine();
		}

		for (int i = 0; i < 5; i++) {
			if (nameList[i] != null && !nameList[i].isEmpty()) {
				System.out.println(nameList[i].toUpperCase());
			} else {
				System.out.println("Invalid input");
			}
		}
		
	}
}