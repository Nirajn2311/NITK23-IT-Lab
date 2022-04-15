from hashlib import sha1

output_file = open("191IT234_IT352_P9_Output_TC6.txt", "w")

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "

P = 2267
Q = 103
e1 = 354
e2 = 1206
d = 30
r = 7

msg = input("Enter message: ")

print("\nP =", P)
print("Q =", Q)
print("e1 =", e1)
print("e2 =", e2)
print("d =", d)
print("r =", r)
print("msg =", msg)
output_file.write("P = " + str(P) + "\n")
output_file.write("Q = " + str(Q) + "\n")
output_file.write("e1 = " + str(e1) + "\n")
output_file.write("e2 = " + str(e2) + "\n")
output_file.write("d = " + str(d) + "\n")
output_file.write("r = " + str(r) + "\n")
output_file.write("msg = " + str(msg) + "\n")

msg = "".join([f"{alphabet.index(char)}".rjust(2, "0") for char in msg.upper()])
print("\nEncoded message: " + msg)
output_file.write("\nEncoded message: " + msg + "\n")

s1 = sha1((msg + str(pow(e1, r, P))).encode())
s1_int = int(s1.hexdigest(), 16)
s2 = (r + (d * s1_int)) % Q
print("s1 =", s1_int)
print("s2 =", s2)
output_file.write("s1 = " + str(s1_int) + "\n")
output_file.write("s2 = " + str(s2) + "\n")

V = sha1((msg + str(pow(pow(e1, s2, P) * pow(e2, -s1_int, P), 1, P))).encode())
V_int = int(V.hexdigest(), 16)
print("\nV =", V_int)
output_file.write("\nV = " + str(V_int) + "\n")

output_file.close()
