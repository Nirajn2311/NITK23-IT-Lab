s1_box = [
    [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
    [0, 15, 7, 4, 14, 2, 13, 10, 3, 6, 12, 11, 9, 5, 3, 8],
    [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
    [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13],
]

output_file = open("191IT234_IT352_P5_Output_TC4.txt", "w")

inp_str = input("Enter plaintext: ")
inp_bin = ""

for char in inp_str:
    inp_bin += f"{ord(char):08b}"

inp_bin = inp_bin[:48]

print("Input of S-1 box Operation:", inp_bin)
output_file.write(f"Input of S-1 box Operation: {inp_bin}\n")

s1_output = ""
for grp in range(0, len(inp_bin), 6):
    row = int(f"{inp_bin[grp]}{inp_bin[grp+5]}", 2)
    col = int(f"{inp_bin[grp+1:grp+5]}", 2)
    s1_output += f"{s1_box[row][col]:04b}"

print("Output of S-1 box Operation:", s1_output)
output_file.write(f"Output of S-1 box Operation: {s1_output}\n")

output_file.close()