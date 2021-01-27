from cs50 import get_int

height = get_int("Height:")  # asks user for height
 
while(height > 8 or height < 1):  # reject values smaller tha 1 and biggh=er tha 8
    height = get_int("Height:")

for i in range(1, height + 1):  # draw the pyramid
    print(" " * (height - i) + i * "#" + " " * 2 + i * "#") 
