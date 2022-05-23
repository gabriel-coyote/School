//Gabriel Coyote

import java.util.Scanner;

//Exception Class: MonthException
class MonthException extends Exception{
	private int month;
	
	MonthException(int a){
		month = a;
	}
	
	public String toString() {
		return "MonthException["+month+"]:"+ "Reenter the month:";
	}
}

//Exception Class: DayException
class DayException extends Exception{
	private int day;
	
	DayException(int a){
		day = a;
	}
	
	public String toString() {
		return "DayException["+day+"]:"+ "Reenter the day:";
	}
}

//Exception Class: YearException
class YearException extends Exception{
	private int year;
	
	YearException(int a){
		year = a;
	}
	
	public String toString() {
		return "YearException["+year+"]:"+ "Reenter the year:";
	}
}







public class datesTest {
	//Method to check month
	static void checkMonth(int month) throws MonthException{
		if(month > 12 || month < 1)
			throw new MonthException(month);
	}
	
	//Method to check day
	static void checkDay(int day, int month) throws DayException{
		
		switch(month) {
		case 1, 3, 5, 7, 8, 10, 12 :
			if(day < 1 || day > 31)
				throw new DayException(day);
			break;
		case 2:
			if(day < 1 || day > 28)
				throw new DayException(day);
			break;
		case 4, 6, 9, 11:
			if(day < 1 || day > 30)
				throw new DayException(day);
			break;
		default:
			break;
		}
	}
	
	//Method to check year
	static void checkYear(int year) throws YearException{
		if(year > 3000 || year < 1000)
			throw new YearException(year);
	}
	
	
	//Method to Print normal "month day, year
	static void printDates(int month, int day, int year) {
		System.out.println();
		//Printing month
		switch(month) {
		case 1:
			System.out.print("January ");
			break;
		case 2:
			System.out.print("Febuary ");
			break;
		case 3:
			System.out.print("March ");
			break;
		case 4:
			System.out.print("April ");
			break;
		case 5:
			System.out.print("May ");
			break;
		case 6:
			System.out.print("June ");
			break;
		case 7:
			System.out.print("July ");
			break;
		case 8:
			System.out.print("August ");
			break;
		case 9:
			System.out.print("September ");
			break;
		case 10:
			System.out.print("October ");
			break;
		case 11:
			System.out.print("November ");
			break;
		case 12:
			System.out.print("December ");
			break;
		default:
			break;
		}
		
		//Printing day
		System.out.print(day);
		
		//Printing Year
		System.out.print(", "+year);
		
		System.out.println();
	}
	
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int month, day, year = 0;
		boolean done = false;
		String inputDate; 
		
		//Get input date
		System.out.println("Enter the date as month/day/year (Example: 12/25/2000): ");
		inputDate  = in.nextLine();
		String values[] = inputDate.split("/");
		
		//Assuming they enter numbers
		month = Integer.parseInt(values[0]);
		day = Integer.parseInt(values[1]);
		year = Integer.parseInt(values[2]);
		
		
		//Check month 
		while(done != true) {
			try {
				checkMonth(month);
				done = true;
			} catch (MonthException e) {
				System.out.println("Error "+ e);
				month = in.nextInt();
			}
		}
		
		
		//Check Day
		done = false;
		while(done != true) {
			try {
				checkDay(day, month);
				done = true;
			} catch (DayException e) {
				System.out.println("Error "+ e);
				day = in.nextInt();
			}
		}
		
		//Check Year
		done = false;
		while(done != true) {
			try {
				checkYear(year);
				done = true;
			} catch (YearException e) {
				System.out.println("Error "+ e);
				year = in.nextInt();
			}
		}	
		
		
		printDates(month, day, year);
		
		
	}
}
