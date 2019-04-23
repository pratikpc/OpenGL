process_queue = []
total_wtime = 0
ct = 0
n = int(input('Enter the total no of processes: '))
for i in range(n):
    at = 0
    bt = 0
    process_queue.append([])#append a list object to the list
    process_queue[i].append(int(input('Enter p_id: ')))
    at = int(input('Enter p_arrival: '))
    process_queue[i].append(at)
    bt = int(input('Enter p_bust: '))
    process_queue[i].append(bt)
    print('')

process_queue.sort(key = lambda process_queue:process_queue[1])

print ('ProcessName\tArrivalTime\tBurstTime\tCompletionTime')
for i in range(n):
    ct += process_queue[i][2]
    process_queue[i].append(ct)
    print (process_queue[i][0],'\t\t',process_queue[i][1],'\t\t',process_queue[i][2],'\t\t',process_queue[i][3])
    total_wtime += (ct)-process_queue[i][2]
    
print ('Total waiting time: ',total_wtime)
print ('Average waiting time: ',(total_wtime/n))
#need to add print for tat and atat
