//Gabriel Coyote
//CS 2365 - 001

import java.util.Scanner;


class Rectangle{
	double Length;
	double Width;
	
	//Verify the length is greater than 0, and less than 50
	boolean setLength(double l) {
		if( 0 < l && l < 50) {
			Length = l;
			return true;
		}else {
			System.out.println("INVALID: Enter a value larger than 0, and less than 50.");
			return false;
		}
	}
	
	//Verify the width is greater than 0, and less than 50
	boolean setWidth(double w) {
		if ( 0 < w && w < 50) {
			Width = w;
			return true;
		}else {
			System.out.println("INVALID: Enter a value larger than 0, and less than 50.");
			return false;
		}
	}
	
	
	//Prints the Length
	void getLength() {
		System.out.println("The Rectangle's length is: "+ Length);
	}
	//Prints the Width
	void getWidth() {
		System.out.println("The Rectangle's Width is: " + Width);
	}
	
	
	//I didn't make a variable for Area and Perimeter
	//since from my understanding the class only has attributes Length and Width
	
	//Prints the Area of the Rectangle
	void Area() {
		System.out.println("The Rectangle's Area is: " + (Length * Width));
	}
	
	//Prints the Perimeter of the Rectangle
	void Perimeter() {
		System.out.println("The Rectangle's Perimeter is: " + (2*Length + 2*Width));
	}
}






public class TestRectangle {

	public static void main(String[] args) {
		//Attributes
		double length;
		double width;
		
		Scanner in = new Scanner(System.in);
		Rectangle myrectangle = new Rectangle();	//create myrectangle	
		
		//Get valid input for rectangle's length
		do {
		System.out.print("Enter Rectangle's Length: ");
		length = in.nextDouble();
		} while(myrectangle.setLength(length) == false);
		
		
		
		
		
		//Get valid input for rectangle's width
		do {
		System.out.print("Enter Rectangle's width: ");
		width = in.nextDouble();
		} while(myrectangle.setWidth(width) == false);
		
		//For Formatting: Readablilty
		System.out.println("");
		
		myrectangle.getLength();
		myrectangle.getWidth();
		myrectangle.Area();
		myrectangle.Perimeter();
		

	}

}
