using Printf

function print_float(msg::String, x::Float64)
    @Printf.printf("%s%s [%a]\n", msg, x, x)
end

print_float("sin(4)=", sin(4))
print_float("exp(-5.01)=", exp(-5.01))
print_float("pow(4.7, -2.7)=", 4.7 ^ -2.7)
print_float("pow(0.6, -0.1)=", 0.6 ^ -0.1)
print_float("pow(17.21, 2.0)=", 17.21 ^ 2.0)
print_float("pow(95.97, 2.0)=", 95.97 ^ 2.0)
print_float("pow(75.7, 0.5)=", 75.7 ^ 0.5)
