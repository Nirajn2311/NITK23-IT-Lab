class emp
{
	int id;
	String name;
	int salary;
	emp(int sid, String sname,int ssalary)
	{
		id=sid;
		name=sname;
		salary=ssalary;
	}

}

class Employee
{
	public static void main(String args[])
	{
		emp e1 = new emp(56789, "Ritvik", 56789);
		emp e2 = new emp(34567, "Niraj", 34567);
		System.out.println("Employees with salary above 50K");
		if(e1.salary>50000)
			{
				System.out.println("ID: " + e1.id);
				System.out.println("Name: " + e1.name);
			}
		if(e2.salary>50000)
			{
				System.out.println("\nID: " + e2.id);
				System.out.println("Name: " + e2.name);
			}

	}
}