import sys
import csv

# check if there are the required amount of command line args.
if len(sys.argv) != 3:
    sys.exit("Usage: python tournament.py database sequence")

# Open CSV and read to a list.
data_base = []
with open(sys.argv[1], 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        data_base.append(row)

# Open Sequence TXT
with open(sys.argv[2], 'r') as file:
    list = file.read()

counts_of_first = []
counts_of_second = []
counts_of_third = []
counts_of_fourth = []
counts_of_fifth = []
counts_of_sixth = []
counts_of_seventh = []
counts_of_eighth = []

for i in range(len(list)):
    if list[i] == 'A':   # first
        count = 0
        j = 0
        while(True):
            if list[i + j: i + j + 5] == "AGATC":
                j += 5
                count += 1
            else:
                counts_of_first.append(count)
                break
    if list[i] == 'T':   # second
        count = 0
        j = 0
        while(True):
            if list[i + j: i + j + 8] == 'TTTTTTCT':
                j += 8
                count += 1
            else:
                counts_of_second.append(count)
                break
    if list[i: i+2] == 'AA':   # third
        count = 0
        j = 0
        while(True):
            if list[i + j: i + j + 4] == 'AATG':
                j += 4
                count += 1
            else:
                counts_of_third.append(count)
                break
    if list[i] == 'T':   # fourth
        count = 0
        j = 0
        while(True):
            if list[i + j: i + j + 5] == 'TCTAG':
                j += 5
                count += 1
            else:
                counts_of_fourth.append(count)
                break
    if list[i] == 'G':  # fifth
        count = 0
        j = 0
        while(True):
            if list[i + j: i + j + 4] == 'GATA':
                j += 4
                count += 1
            else:
                counts_of_fifth.append(count)
                break
    if list[i] == 'T':  # sixth
        count = 0
        j = 0
        while(True):
            if list[i + j: i + j + 4] == 'TATC':
                j += 4
                count += 1
            else:
                counts_of_sixth.append(count)
                break
    if list[i] == 'G':  # seventh
        count = 0
        j = 0
        while(True):
            if list[i + j: i + j + 4] == 'GAAA':
                j += 4
                count += 1
            else:
                counts_of_seventh.append(count)
                break
    if list[i] == 'T':  # eighth
        count = 0
        j = 0
        while(True):
            if list[i + j: i + j + 4] == 'TCTG':
                j += 4
                count += 1
            else:
                counts_of_eighth.append(count)
                break


sequence = [max(counts_of_first), max(counts_of_second), max(counts_of_third), max(counts_of_fourth),
            max(counts_of_fifth), max(counts_of_sixth), max(counts_of_seventh), max(counts_of_eighth)]


# compare valuelist to reader and if found print the name of the person whos DNA has all the occurances to the console/terminal.            
for i in range(len(data_base)):
    if sequence[0] == int(data_base[i]["AGATC"]) and sequence[1] == int(data_base[i]["TTTTTTCT"]) and sequence[2] == int(data_base[i]["AATG"]) and sequence[3] == int(data_base[i]["TCTAG"]) and sequence[4] == int(data_base[i]["GATA"]) and sequence[5] == int(data_base[i]["TATC"]) and sequence[6] == int(data_base[i]["GAAA"]) and sequence[7] == int(data_base[i]["TCTG"]):
        print(data_base[i]["name"])
        sys.exit(0)
         
print("No match")
    
