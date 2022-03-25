def first_partition(blocks, nb, processes, np):
    pb = []

    for i in range(0, np):
        found = 0
        for j in range(0, nb):
            if processes[i] <= blocks[j]:
                found = 1
                blocks[j] -= processes[i]
                break
        if found:
            pb.append(j)
        else:
            pb.append(-1)

    i = 1
    print("+-------------+--------------+--------------+")
    print("| Process No. | Process Size | Block Number |")
    print("+-------------+--------------+--------------+")
    for (p, b) in zip(processes, pb):
        if(b != -1):
            print(f"|     {str(i).rjust(2,' ')}      |      {str(p).rjust(3,' ')}     |     {str(b+1).rjust(3,' ')}      |")
        else:
            print(f"|     {str(i).rjust(2,' ')}      |      {str(p).rjust(3,' ')}     |      N/A     |")
        i += 1
    print("+-------------+--------------+--------------+")


nb = int(input("Enter number of blocks: "))
np = int(input("Enter number of processes: "))

blocks = []
processes = []

print()
for i in range(0, nb):
    blocks.append(int(input(f'Enter size of Block {i+1}: ')))

print()
for i in range(0, np):
    processes.append(int(input(f'Enter size of Process {i+1}: ')))

first_partition(blocks, nb, processes, np)
