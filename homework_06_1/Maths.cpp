//the addition function
int sum(int a, int b) { return a + b; }
//the subtraction function
int diff(int a, int b) { return a - b; }
//the multiplication function
int multiplication(int a, int b) { return a * b; }
//the division function
double division(int a, int b) { return (double)a / (double)b; }
//exponentiation
long int pow(int a, int b) 
{ 
	int temp{ 1 };
	for (; b; b--)
	{
		temp = temp * a;
	}
	return temp;
}