string HexFloat(double x)
{
    if (x == 0.0)
    {
        return Double.IsNegative(x) ? "-0x0p0" : "0x0p0";
    }
    else if (Double.IsFinite(x))
    {
        int e = Math.ILogB(x);
        double y = Math.ScaleB(Math.Abs(x), 52-e);
        long yy = (long)y;
        // Debug.Assert((double)yy == y);
        string s = String.Format("{0:x}", yy);
        string s1 = s.Substring(0, 1);
        // Debug.Assert(s1 == "1");
        string s2 = s.Substring(1).TrimEnd('0');
        return String.Format("{0}0x{1}{2}p{3}", Double.IsNegative(x) ? "-" : "", s1, s2 == "" ? s2 : "." + s2, e);
    }
    else
    {
        // Infinity, NaN
        return x.ToString();
    }
}

void print_float(string s, double y)
{
    Console.WriteLine($"{s}{y} [{HexFloat(y)}]");
}

print_float("sin(4)=", Math.Sin(4));
print_float("exp(-5.01)=", Math.Exp(-5.01));
print_float("pow(4.7, -2.7)=", Math.Pow(4.7, -2.7));
print_float("pow(0.6, -0.1)=", Math.Pow(0.6, -0.1));
print_float("pow(17.21, 2.0)=", Math.Pow(17.21, 2.0));
print_float("pow(95.97, 2.0)=", Math.Pow(95.97, 2.0));
print_float("pow(75.7, 0.5)=", Math.Pow(75.7, 0.5));
