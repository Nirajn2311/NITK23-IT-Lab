from math import gcd
from sympy.matrices import Matrix
from numpy import bitwise_xor

MOD_VAL = 128
KEY = Matrix(
    [
        [5, 13],
        [3, 15],
    ]
)
IV = Matrix(
    [
        [7, 12],
        [16, 7],
    ]
)
DUMMY_CHAR = "&"

output_file = open("191IT234_IT352_P6_Output_TC6.txt", "w")

inp_str = input("Enter plaintext: ")
inp_ascii = []

if len(inp_str) % 4 != 0:
    inp_str += (4 - (len(inp_str) % 4)) * DUMMY_CHAR

for char in inp_str:
    inp_ascii.append(ord(char))

print("\nASCII values of plaintext:", inp_ascii)
output_file.write(f"ASCII values of plaintext: {inp_ascii}\n")

if gcd(KEY.det(), MOD_VAL) != 1:
    print("Key-inverse does not exist")
    output_file.write("Key-inverse does not exist\n")
    output_file.close()
    exit(1)

print("\nENCRYPTION OPERATION")
output_file.write("\nENCRYPTION OPERATION\n")
enc_ascii = []
curr_inp = IV
for i in range(0, len(inp_ascii), 4):
    hc_output = (KEY * curr_inp) % MOD_VAL
    curr_inp = hc_output
    final_op = bitwise_xor(
        Matrix([inp_ascii[i : i + 2], inp_ascii[i + 2 : i + 4]]), hc_output
    )
    for v in final_op.tolist():
        enc_ascii.append(v[0])
        enc_ascii.append(v[1])
print("Plaintext:", inp_str)
print("Ciphertext:", "".join([chr(x) for x in enc_ascii]))
output_file.write("Plaintext: " + inp_str + "\n")
output_file.write("Ciphertext: " + "".join([chr(x) for x in enc_ascii]) + "\n")

print("\n\nDECRYPTION OPERATION")
output_file.write("\n\nDECRYPTION OPERATION\n")
dec_ascii = []
curr_inp = IV
for i in range(0, len(enc_ascii), 4):
    hc_output = (KEY * curr_inp) % MOD_VAL
    curr_inp = hc_output
    final_op = bitwise_xor(
        Matrix([enc_ascii[i : i + 2], enc_ascii[i + 2 : i + 4]]), hc_output
    )
    for v in final_op.tolist():
        dec_ascii.append(v[0])
        dec_ascii.append(v[1])
print("Ciphertext:", "".join([chr(x) for x in enc_ascii]))
print("Plaintext:", "".join([chr(x) for x in dec_ascii]))
output_file.write("Ciphertext: " + "".join([chr(x) for x in enc_ascii]) + "\n")
output_file.write("Plaintext: " + "".join([chr(x) for x in dec_ascii]) + "\n")

output_file.close()
