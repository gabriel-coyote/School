//Gabriel Coyote

class OverloadingClass{
	
	//Overloading methods below
	//4 of them (overMethods)
	void ovrMethod(double a) {
		System.out.println(a);
	}
	
	void ovrMethod(int a, int b, int c) {
		System.out.println("a, b and c: "+a+", "+b+", "+c);
	}

	void ovrMethod(int a, int b) {
		System.out.println("The sum of the number is: "+a+"+"+b+"="+(a+b));
	}		

	void ovrMethod(String name, int age) {
		System.out.println(name+" is "+age+" years old.");
	}
	
}


public class OverloadingClassTest {

	public static void main(String[] args) {
		
		OverloadingClass testing = new OverloadingClass();
		
		System.out.println("Result:");
		testing.ovrMethod(1.0);
		testing.ovrMethod(5,8,7);
		testing.ovrMethod(5,2);
		testing.ovrMethod("Anna", 29);

	}

}
