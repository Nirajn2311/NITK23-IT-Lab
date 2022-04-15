from math import gcd
from sympy import isprime

output_file = open("191IT234_IT352_P8_Output_TC6.txt", "w")

P = int(input("Enter P value: "))
Q = int(input("Enter Q value: "))
e = int(input("Enter e value: "))

N = P * Q
phi_N = (P - 1) * (Q - 1)

print("\nP =", P)
print("Q =", Q)
print("e =", e)
print("n =", N)
print("phi(n) =", phi_N)
output_file.write("P = " + str(P) + "\n")
output_file.write("Q = " + str(Q) + "\n")
output_file.write("e = " + str(e) + "\n")
output_file.write("n = " + str(N) + "\n")
output_file.write("phi(n) = " + str(phi_N) + "\n")

if (
    e >= phi_N
    and e <= 1
    and P == Q
    and (not isprime(P))
    and (not isprime(Q))
    and gcd(e, phi_N) != 1
):
    print("Key Pair Cannot Be Generated")
    output_file.write("Key Pair Cannot Be Generated\n")
    exit()

try:
    d = pow(e, -1, phi_N)
except:
    print("Key Pair Cannot Be Generated")
    output_file.write("Key Pair Cannot Be Generated\n")
    exit()

print("d =", d)
output_file.write("d = " + str(d) + "\n")

output_file.close()
