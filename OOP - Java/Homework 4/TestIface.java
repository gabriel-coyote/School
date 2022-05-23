//Gabriel Coyote
//CS 2365 - 001

//INTERFACE
interface CarbonFootprint{
	void getCarbonFootprint(int param);
}


//CLASS BUILDINGS
class Building implements CarbonFootprint{
	public void getCarbonFootprint(int footprint) {
		System.out.println(footprint + ", this message from Building CarbonFoot.");
	}
}

//CLASS CAR
class Car implements CarbonFootprint{
	public void getCarbonFootprint(int footprint) {
		System.out.println(footprint + ", this message from Car CarbonFoot.");
	}
}

//CLASS BICYCLE
class Bicycle implements CarbonFootprint{
	public void getCarbonFootprint(int footprint) {
		System.out.println(footprint + ", this message from Bicycle CarbonFoot.");
	}
}



public class TestIface {

	public static void main(String[] args) {
		///Interface reference variable
		CarbonFootprint c;
		
		//Objects of each of the three classes
		Building obBuilding = new Building();
		Car obCar = new Car();
		Bicycle obBicycle = new Bicycle();
		
		
		//Assigning eash object to interface reference variable
		//AND invoke each objects' getCarbonFootprint method
		c = obBuilding;
		c.getCarbonFootprint(58);
		
		c = obCar;
		c.getCarbonFootprint(87);
		
		c = obBicycle;
		c.getCarbonFootprint(10);
		
		

	}

}
