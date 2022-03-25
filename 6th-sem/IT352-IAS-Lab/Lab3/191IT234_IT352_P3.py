# Test case file is stored in a variable in the program and has to be changed to the test case file before execution.

from scapy.all import *

test_case = "Testcase-1-for-Second-Set-of-Students.pcap"
output_file = open('191IT234_IT352_P3_Output_TC1.txt', 'w')
N = int(input('Enter value for N: '))

num_of_pkts = 0
num_of_int_pkts = 0

pcap_file = rdpcap(test_case, N)

pcap_file[0]

for packet in pcap_file:
    num_of_pkts += 1
    if ICMP in packet or (
        IP in packet
        and (
            (packet[IP].src == packet[IP].dst)
            or (packet[IP].src == "255.255.255.255" or packet[IP].dst == "255.255.255.255")
        )
    ):
        num_of_int_pkts += 1
        print("Analyzed Packet is Intrusion Packet")
        output_file.write("Analyzed Packet is Intrusion Packet\n")
    else:
        print("Analyzed Packet is Not-Intrusion Packet")
        output_file.write("Analyzed Packet is Not-Intrusion Packet\n")
    print(packet.summary())
    output_file.write(packet.summary() + "\n")

print('total number of packets checked is =', num_of_pkts)
print('total number of intrusion packets detected is =', num_of_int_pkts)
output_file.write('total number of packets checked is = ' + str(num_of_pkts) + '\n')
output_file.write('total number of intrusion packets detected is = ' + str(num_of_int_pkts) + '\n')
output_file.close()
