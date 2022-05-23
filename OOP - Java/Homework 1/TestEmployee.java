//Gabriel Coyote
//CS 2365 - 001

import java.util.Scanner;


class Employee{
	String name;
	int ID;
	String position;
	
	//Constructor used when Name, ID, and Position are known
	Employee(String Name, int id, String Position){
		name = Name;
		ID = id;
		position = Position;
	}
}



public class TestEmployee {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		String name;
		int id;
		String pos;
		
		System.out.println("Enter Employees Info");
		System.out.println("");
		
		
		//Name, ID, Position for Employee 1
		//Used Constructor to create employee object
		System.out.println("");
		System.out.print("Enter  Employee 1 Name: ");
		name = in.nextLine();
		System.out.print("Enter Employee 1 ID: ");
		id = in.nextInt();
		in.nextLine(); 		//Fixes .nextInt() method not reading the newline character
		System.out.print("Enter Employee 1 Position: ");
		pos = in.nextLine();
		
		Employee employee1 = new Employee(name,id,pos);	//Constructor for employee object
		
		//Name, ID, Position for Employee 2
		//Used Constructor to create employee object
		System.out.println("");
		System.out.print("Enter  Employee 2 Name: ");
		name = in.nextLine();
		System.out.print("Enter Employee 2 ID: ");
		id = in.nextInt();
		in.nextLine(); 		//Fixes .nextInt() method not reading the newline character
		System.out.print("Enter Employee 2 Position: ");
		pos = in.nextLine();
				
		Employee employee2 = new Employee(name,id,pos);	//Constructor for employee object
				
		//Name, ID, Position for Employee 3
		//Used Constructor to create employee object
		System.out.println("");
		System.out.print("Enter  Employee 3 Name: ");
		name = in.nextLine();
		System.out.print("Enter Employee 3 ID: ");
		id = in.nextInt();
		in.nextLine(); 		//Fixes .nextInt() method not reading the newline character
		System.out.print("Enter Employee 3 Position: ");
		pos = in.nextLine();
				
		Employee employee3 = new Employee(name,id,pos);	//Constructor for employee object
		

		
		//Display Each Employee's Name, ID, and Position
		System.out.println("");
		System.out.println("");
		System.out.println("Employee: [NAME], [ID], [POSITION]");
		System.out.println("________________________________________");
		System.out.println("Employee 1: " + employee1.name + ", " +employee1.ID + ", " +employee1.position);
		System.out.println("Employee 2: " + employee2.name + ", " +employee2.ID + ", " +employee2.position);
		System.out.println("Employee 3: " + employee3.name + ", " +employee3.ID + ", " +employee3.position);
		
	}

}
