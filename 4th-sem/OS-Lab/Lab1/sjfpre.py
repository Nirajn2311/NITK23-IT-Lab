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


def shortest_job_first_pre(data):
    def find_min_rt(curr_time, lst):
        lst.sort(key=lambda x: x[1])
        for i in lst:
            if curr_time >= i[0]:
                return i[2]
        return -1

    def all_finished(lst):
        for i in lst:
            if i[1] != 0:
                return False
        return True

    def dec_bt(indx, lst):
        for i in range(len(lst)):
            if lst[i][-1] == indx:
                lst[i][1] -= 1
                if lst[i][1] == 0:
                    del lst[i]
                    return lst, True
        return lst, False

    srtf = []
    indx = 0

    for i in data:
        srtf.append([i['at'], i['bt'], indx])
        indx += 1

    srtf.sort()
    curr_time = 0

    while not all_finished(srtf):
        index = find_min_rt(curr_time, srtf)
        if(index == -1):
            curr_time += 1
        else:
            curr_time += 1
            srtf, is_done = dec_bt(index, srtf)
            if is_done:
                data[index]['ct'] = curr_time
                data[index]['tat'] = data[index]['ct'] - data[index]['at']
                data[index]['wt'] = data[index]['tat'] - data[index]['bt']
    return data


n = int(input("Enter the number of processes: "))

data = list('0' * n)

for i in range(0, n):
    print(f"\nProcess {i + 1}")
    data[i] = {}
    data[i]['bt'] = int(input("Enter burst time: "))
    data[i]['at'] = int(input("Enter arrival time: "))

final = shortest_job_first_pre(data)

disp_result(final)
