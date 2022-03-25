from random import randint
import re


def generate_key(plaintext):
    key = [randint(1, 25)]
    key_string = chr(key[0] + 97)
    plaintext = re.sub("[^a-zA-Z]", "", plaintext)[:-1]
    for char in plaintext:
        key_string += char
        if char.isupper():
            key.append(ord(char) - 65)
        else:
            key.append(ord(char) - 97)
    return key, key_string


def encryption(plaintext, key):
    cipher = ""
    spaces = 0
    for i in range(len(plaintext)):
        if plaintext[i] == " ":
            cipher += " "
            spaces += 1
            continue
        if plaintext[i].isupper():
            cipher += chr(((ord(plaintext[i]) - 65) + key[i - spaces]) % 26 + 65)
        else:
            cipher += chr(((ord(plaintext[i]) - 97) + key[i - spaces]) % 26 + 97)
    return cipher


def decryption(ciphertext, key):
    plain = ""
    spaces = 0
    for i in range(len(ciphertext)):
        if ciphertext[i] == " ":
            plain += " "
            spaces += 1
            continue
        if ciphertext[i].isupper():
            plain += chr(((ord(ciphertext[i]) - 65) - key[i - spaces]) % 26 + 65)
        else:
            plain += chr(((ord(ciphertext[i]) - 97) - key[i - spaces]) % 26 + 97)
    return plain


inp_plain = input("Enter plaintext: ")
if re.search(r"[^a-zA-Z ]", inp_plain):
    print("Invalid input")
    exit(1)

auto_key, key_str = generate_key(inp_plain)

output_file = open("191IT234_IT352_P4_Output_TC6.txt", "w")

ciphertext = encryption(inp_plain, auto_key)
print("\n\nENCRYPTION OPERATION")
print("Plaintext:", inp_plain)
print("Ciphertext:", ciphertext)
print("Key:", key_str)
output_file.write("ENCRYPTION OPERATION\n")
output_file.write("Plaintext: " + inp_plain + "\n")
output_file.write("Ciphertext: " + ciphertext + "\n")
output_file.write("Key: " + key_str + "\n")

plaintext = decryption(ciphertext, auto_key)
print("\n\nDECRYPTION OPERATION")
print("Ciphertext:", ciphertext)
print("Plaintext:", plaintext)
print("Key:", key_str)
output_file.write("\n\nDECRYPTION OPERATION\n")
output_file.write("Ciphertext: " + ciphertext + "\n")
output_file.write("Plaintext: " + plaintext + "\n")
output_file.write("Key: " + key_str + "\n")
output_file.close()
