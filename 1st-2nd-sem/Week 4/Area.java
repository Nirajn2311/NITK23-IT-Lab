class ar
{
	float rad, l, b;
	ar(float rrad)
	{
		rad = rrad;
	}
	ar(float ll,float bb)
	{
		l = ll;
		b = bb;
	}
}
class Area
{
	public static void main(String args[])
	{
		ar a1 = new ar(10);
		ar a2 = new ar(2, 3);
		float area1 = a1.rad * a1.rad;
		area1 *= 3.14;
		float area2 = a2.l * a2.b;
		System.out.println("Area of circle: " + area1);
		System.out.println("Area of rectangle: " + area2);
	}
}