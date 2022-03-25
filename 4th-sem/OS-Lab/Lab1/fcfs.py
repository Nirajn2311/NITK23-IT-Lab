def disp_result(data):
    twt = ttat = 0
    print("\nProcess\t|  AT\t|  BT\t|  CT\t| TAT\t| WT\t|")
    print("-"*48+"|")
    for i in range(0, len(data)):
        print(
            f"{i + 1}\t|  {data[i]['at']}\t|  {data[i]['bt']}\t|  {data[i]['ct']}\t|  {data[i]['tat']}\t|  {data[i]['wt']}\t|")
        twt += data[i]['wt']
        ttat += data[i]['tat']

    print(f"\nAVERAGE TURNAROUND TIME: {ttat/len(data)}")
    print(f"AVERAGE WAITING TIME: {twt/len(data)}")


def first_come_first_serve(data):
    arr_time = []
    indx = 0

    for i in data:
        arr_time.append([i['at'], indx])
        indx += 1

    arr_time.sort()
    curr_time = 0

    for v in arr_time:
        if data[v[1]]['at'] > curr_time:
            curr_time += data[v[1]]['at'] - curr_time
        curr_time += data[v[1]]['bt']
        data[v[1]]['ct'] = curr_time
        data[v[1]]['tat'] = data[v[1]]['ct'] - data[v[1]]['at']
        data[v[1]]['wt'] = data[v[1]]['tat'] - data[v[1]]['bt']

    return data


n = int(input("Enter the number of processes: "))

data = list('0' * n)

for i in range(0, n):
    print(f"\nProcess {i + 1}")
    data[i] = {}
    data[i]['bt'] = int(input("Enter burst time: "))
    data[i]['at'] = int(input("Enter arrival time: "))

final = first_come_first_serve(data)

disp_result(final)
