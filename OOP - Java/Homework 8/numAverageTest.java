//Gabriel Coyote


import java.util.Scanner;

//This program creates a custom exception type.
class MyException extends Exception {
	private float num;

	MyException(float a) {
		num = a;
	}
}


public class numAverageTest {
	static void check( float num) throws MyException {
		if( num < 0)
			throw new MyException(num);
	}
	
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		boolean done = false;
		float amount = 0;
		float num = 0;
		float sum = 0;
		
		
		// For enter the total amount of numbers to enter
		while(done != true) {
			try {
				System.out.println('\n'+"Enter the total amount of numbers you wish to enter: ");
				amount = in.nextFloat();
				check(amount);
				done = true;
			}catch (MyException e){
				System.out.println(amount+" must be positive.");
			}catch (Exception error) { 
				System.out.println("[Error...enter number again]");
				in.next();
			}
		}
		
		
		//For entering the individual numbers
		done = false;
		int i = 0;
		while(done != true && i != amount) {
			try {
				System.out.println("Enter number["+i+"]: ");
				num = in.nextFloat();
				check(num);
				sum += num;
				i++;
				
			}catch (MyException e) {
				System.out.println(num+" must be positive.");
			}catch (Exception error) { 
				System.out.println("[Error...enter number again]");
				in.next();
			}
		}
		
		
		float average = sum/amount;
		System.out.println("Average:" + average);
		in.close();
		
	}

}
