import java.util.Scanner;

class Calculator
{

    int a,b;
    double c,d;

    Calculator()
    {
        a=0;
        b=0;
        c=0;
        d=0;
    }
    Calculator(int i, int j) {
        a = i;
        b = j;
    }

    Calculator(double i, double j) {
        c = i;
        d = j;
    }

    void add() {
        int x = a + b;
        double y = c + d;
        System.out.println("The integer sum is: " + x);
        System.out.println("The double sum is: " + y);
    }

    void sub() {
        int x = a - b;
        double y = c - d;
        System.out.println("The integer difference is: " + x);
        System.out.println("The double difference is: " + y);
    }

    void mul() {
        int x = a * b;
        double y = c * d;
        System.out.println("The integer prdocut is: " + x);
        System.out.println("The double product is: " + y);
    }

    void div() {
        try {
            int x = a / b;
        	double y = c / d;
            System.out.println("The integer quotient is: " + x);
            System.out.println("The double quotient is: " + y);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public static void main(String args[])
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter 2 Integers and 2 Doubles : ");
        int x = s.nextInt();
        int y = s.nextInt();
        double z = s.nextDouble();
        double a = s.nextDouble();
        Calculator C = new Calculator(x,y);
        C.c=z;
        C.d=a;
        System.out.println("Enter Operator to perform on the numbers: ");
        char option = s.next().charAt(0);
        s.close();
        switch(option)
        {
            case '+':
            	C.add();
            	break;

            case '-':
            	C.sub();
            	break;

            case '*':
            	C.mul();
            	break;

            case '/':
            	C.div();
            	break;

            default:
            	System.out.println("INVALID OPERATOR ENTERED!!");
        }
	}
}