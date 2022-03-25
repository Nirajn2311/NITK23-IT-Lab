class car {
	int modelno;
	car(int no)
	{
		modelno=no;
	}
}

class CarSwap
{
	public static void swap(car c1,car c2)
	{
		int temp=c1.modelno;
		c1.modelno=c2.modelno;
		c2.modelno=temp;
	}

	public static void main(String[] args)
	{
		car c1 = new car(5);
		car c2 = new car(10);
		System.out.println("Before Swapping");
		System.out.println("Car 1 model no. = " + c1.modelno); 
		System.out.println("Car 2 model no. = " + c2.modelno); 
		swap(c1,c2);
		System.out.println("\nAfter Swapping");
		System.out.println("Car 1 model no. = " + c1.modelno); 
		System.out.println("Car 2 model no. = " + c2.modelno); 
	}
}