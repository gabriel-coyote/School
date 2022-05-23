//Gabriel Coyote
//CS 2365 - 001

import java.util.Scanner; // Needed for the Scanner class
import java.io.*;         // Needed for the File class


//User Interface
class Student {

	void login(account AccountOB) {
		String id, password;
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter Student ID: ");
		id = in.nextLine();
		System.out.println("Enter Password: ");
		password = in.nextLine();
		
		AccountOB.setUserCredentials(id, password);	
	}
	
	
	void CourseOption(grade GradeOB) throws FileNotFoundException {
		String option;
		Scanner course = new Scanner(System.in);
		
		System.out.println("OPTIONS: 'CS2365' or 'CS3365'");
		System.out.println("Enter One Option: ");
		option = course.nextLine();
		
		GradeOB.displayGrade(option);
	}
}





//Entity------------------------------------------------------------------
class account{
	String ID;
	String Password;
	
	//Set ID and Password to hold user inputed Values
	void setUserCredentials(String id, String password) {
		ID = id;
		Password = password;
	}
	
	
	
	boolean checkValid(grade Grade_ob) throws IOException{
		//Get the id and password text file
		File file = new File("login.txt");
		Scanner inputFile = new Scanner(file);
		
		while(inputFile.hasNext()) {
			String Account = inputFile.nextLine();
			String values[] = Account.split(", ");
			
			//If ID & Password are valid
			if(ID.equals(values[0]) && Password.equals(values[1])) {
				inputFile.close();
				Grade_ob.setID(ID);
				return true;
			}
		}
		
		//Close the file
		//Return false for invalid ID & Password
		inputFile.close();
		return false;
	}
}







//Entity---------------------------------------------------------------------
class grade{
	String ID;
	String values[]; //Values[2] := CS2365 Grade & Values[4] := CS3365 Grade
	
	//Set ID to find grade of student
	void setID(String Student_ID){
		ID = Student_ID;
	}
	
	
	void displayGrade(String Course) throws FileNotFoundException {
		
	
		//Get the grade text file
		File file = new File("grades.txt");
		Scanner inputFile = new Scanner(file);
		
		while(inputFile.hasNext()) {
			String Account = inputFile.nextLine();
			String values[] = Account.split(", ");
		
			//If ID matches
			if(ID.equals(values[0])) {
				if(Course.equals("CS2365")) {
					System.out.println("CS2365 Course Grade: " + values[2]);
					break;
				}else if(Course.equals("CS3365")) {
					System.out.println("CS3365 Course Grade: " + values[4]);
					break;
				}else {
					//error
					System.out.println("Error; in course option");
					break;
				}
			}
		}
		
		inputFile.close();
	}		
	
	
}





//Control Logic--------------------------------------------------
public class ExamGradeApplication {
	public static void main(String[] args) throws IOException {
		account ob = new account();
		grade grade_ob = new grade();
		Student student = new Student();
		
		
		int attempts = 2;
		boolean valid = false;
	
		//Do for MAX 2 login attempts 
		do {
			student.login(ob);
			if(ob.checkValid(grade_ob) == true) {
				
				student.CourseOption(grade_ob);
				break;
			}
			
			attempts--;
			if(attempts == 0)break;
			System.out.println("");
			System.out.println("Error: Enter another ID & Password...");
			
		}while( attempts > 0 );
		
		if(attempts == 0) {
			System.out.println("//System Terminated...");
		}
		
		
	}
}
