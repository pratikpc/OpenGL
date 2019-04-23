
#shit code
process_queue = []
total_wtime = 0
total_tat = 0
ct = 0
n = int(input('Enter the total no of processes: '))
for i in range(n):
    at = 0
    bt = 0
    process_queue.append([])#append a list object to the list
    process_queue[i].append(int(input('Enter p_id: ')))
    at = int(input('Enter p_arrival: '))
    process_queue[i].append(at)
    bt = int(input('Enter p_burst: '))
    process_queue[i].append(bt)
    ct += bt
    process_queue[i].append(ct)
    total_tat += process_queue[i][3]-process_queue[i][1] #ct-at
    total_wtime += (process_queue[i][3]-process_queue[i][1])-process_queue[i][2] #tat-bt
    print('')

process_queue.sort(key = lambda process_queue:process_queue[1]) #sort by arrival time

print ('ProcessName\tArrivalTime\tBurstTime\tCompletionTime')
for i in range(n):
    print (process_queue[i][0],'\t\t',process_queue[i][1],'\t\t',process_queue[i][2],'\t\t',process_queue[i][3])
    
print ('Total waiting time: ',total_wtime)
print ('Average waiting time: ',(total_wtime/n))
print ('Total turnaround time: ',total_tat)
print ('Average turnaround time: ',(total_tat)/n)
