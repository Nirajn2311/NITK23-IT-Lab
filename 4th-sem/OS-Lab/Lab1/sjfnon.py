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


def shortest_job_first_non_pre(data):
    sjf = []
    indx = 0
    curr_time = 0

    for dct in data:
        sjf.append([dct['bt'], dct['at'], indx])
        indx += 1

    sjf.sort()

    while sjf:
        tlen = len(sjf)
        for val in sjf:
            if val[1] <= curr_time:
                curr_time += data[val[2]]['bt']
                data[val[2]]['ct'] = curr_time
                data[val[2]]['tat'] = data[val[2]]['ct'] - data[val[2]]['at']
                data[val[2]]['wt'] = data[val[2]]['tat'] - data[val[2]]['bt']
                sjf.remove(val)
                break
        if tlen == len(sjf):
            curr_time += 1

    return data


n = int(input("Enter the number of processes: "))

data = list('0' * n)

for i in range(0, n):
    print(f"\nProcess {i + 1}")
    data[i] = {}
    data[i]['bt'] = int(input("Enter burst time: "))
    data[i]['at'] = int(input("Enter arrival time: "))

final = shortest_job_first_non_pre(data)

disp_result(final)
