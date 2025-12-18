import math

def print_float(msg: str, x: float) -> None:
    print(f"{msg}{x} [{x.hex()}]")

print_float("sin(4)=", math.sin(4))
print_float("exp(-5.01)=", math.exp(-5.01))
print_float("pow(4.7, -2.7)=", math.pow(4.7, -2.7))
print_float("pow(0.6, -0.1)=", math.pow(0.6, -0.1))
print_float("pow(17.21, 2.0)=", math.pow(17.21, 2.0))
print_float("pow(95.97, 2.0)=", math.pow(95.97, 2.0))
print_float("pow(75.7, 0.5)=", math.pow(75.7, 0.5))
