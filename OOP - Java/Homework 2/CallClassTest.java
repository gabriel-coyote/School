//Gabriel Coyote


class CallClass{
	//Call by value method 
	//On primitive types
	void valueMethod(int a, int b) {
		a *= 2;
		b += 10;
		System.out.println("a & b within method(after method operation): "+a+", "+ b);
	}
	
	//Call by reference 
	//On objects: of class "TestObjects"
	void referenceMethod(TestObject ob) {
		ob.i += 20;
		ob.j *= 2;
	}
}




//Class TestObjects holds two integers: i & j
class TestObject{
	int i;
	int j;
	
	//Constructor for Object of class "TestObject"
	TestObject(int a, int b){
		i = a;
		j = b;
	}
}






public class CallClassTest {

	public static void main(String[] args) {
		
		CallClass ob = new CallClass();
		
		int a = 5;
		int b = 7;
		
		//Call by value demo
		System.out.println("Call by Value Demo: ");
		System.out.println("a & b before call: "+a+", "+b);
		ob.valueMethod(a, b);
		System.out.println("a & b after call: "+a+", "+b);
		System.out.println();
		
		
		//Call by reference demo
		System.out.println("Call by Reference Demo:");
		TestObject testObject = new TestObject(5,15);
		System.out.println("testObject.i & testObject.j value before call: "+testObject.i+", "+testObject.j);
		ob.referenceMethod(testObject);
		System.out.println("testObject.i & testObject.j value after call: "+testObject.i+", "+testObject.j);
	}
}
