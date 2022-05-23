import java.util.Scanner;
class GetInputFromUser
{
		public static void main(String args[])
		{
			Scanner in = new Scanner(System.in);
			
			System.out.print("Enter a string: ");
			String s = in.nextLine();
			System.out.println("You entered string "+s);
						
			System.out.print("Enter an integer: ");
			int a = in.nextInt();
			System.out.println("You entered integer "+a);	

			System.out.print("Enter a floating point number: ");
			float b = in.nextFloat();
			System.out.println("You entered float "+b);
		}
}