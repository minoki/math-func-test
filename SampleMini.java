void print_float(String s, double y)
{
    System.out.format("%s%s [%a]\n", s, Double.toString(y), y);
}

void main()
{
    print_float("sin(4)=", Math.sin(4));
    print_float("exp(-5.01)=", Math.exp(-5.01));
    print_float("pow(4.7, -2.7)=", Math.pow(4.7, -2.7));
    print_float("pow(0.6, -0.1)=", Math.pow(0.6, -0.1));
    print_float("pow(17.21, 2.0)=", Math.pow(17.21, 2.0));
    print_float("pow(95.97, 2.0)=", Math.pow(95.97, 2.0));
    print_float("pow(75.7, 0.5)=", Math.pow(75.7, 0.5));
}
