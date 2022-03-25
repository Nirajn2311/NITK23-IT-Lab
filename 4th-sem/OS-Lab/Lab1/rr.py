def round_robin(data, n, quantum, completion):
    queue = []
    time = 0
    arrived = 0
    ready = 0
    done = 0
    start = 0

    while done < n:
        for i in range(arrived, n):
            if time >= data[i][1]:
                queue.append(data[i])
                arrived += 1
                ready += 1

        if ready < 1:
            time += 1
            continue

        if start:
            queue.append(queue.pop(0))

        if queue[0][0] > 0:
            if queue[0][0] > quantum:
                time += quantum
                queue[0][0] -= quantum
            else:
                time += queue[0][0]
                queue[0][0] = 0
                done += 1
                ready -= 1
                completion[queue[0][2]-1] = time

            start = 1


def waiting_turnaround(data, burst, turnaround, completion_time, waiting):
    for i in range(0, n):
        turnaround[i] = completion_time[i]-data[i][1]
        waiting[i] = turnaround[i]-burst[i]


def average(n, quantum, turnaround, waiting):
    twt = ttat = 0
    for i in range(0, n):
        twt += waiting[i]
        ttat += turnaround[i]

    print("\nAVERAGE TURNAROUND TIME: ", ttat/n)
    print("AVERAGE WAITING TIME: ", twt/n)


n = int(input("Enter number of processes: "))
quantum = int(input("\nEnter quantum time: "))

data = []
completion = [0]*n
turnaround = [0]*n
waiting = [0]*n
burst = [0]*n
b_a = [0]*3

for i in range(0, n):
    print(f"\nProcess {i + 1}")
    b_a[0] = int(input("Enter burst time: "))
    b_a[1] = int(input("Enter arrival time: "))
    b_a[2] = i+1
    burst[i] = b_a[0]
    data.append([b_a[0], b_a[1], b_a[2]])

round_robin(data, n, quantum, completion)
waiting_turnaround(data, burst, turnaround, completion, waiting)

print("\nProcess\t|  AT\t|  BT\t|  TAT\t| WT\t|")
print("-"*40+"|")
for i in range(n):
    print(
        f"{i + 1}\t|  {data[i][1]}\t|  {burst[1]}\t|  {turnaround[i]}\t|  {waiting[i]}\t|")

average(n, quantum, turnaround, waiting)
