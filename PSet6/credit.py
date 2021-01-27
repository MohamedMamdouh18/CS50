from cs50 import get_int

credit = get_int("Number :")  # ask the use for the number
array = []
sum = 0

while credit > 0:  # put the digits of the number in array
    array.append(credit % 10)
    credit = int(credit / 10)
array.reverse()  # reverse the array to make the digits as the same order as the real number

for i in range(len(array)):  # applying the formula of the sum
    if i % 2 == 0:
        sum += (array[i] * 2) % 10 + int(array[i] * 2 / 10)
    else:
        sum += array[i]

# check for the card type and if it is invalid or not
if array[0] == 3 and (array[1] == 7 or array[1] == 4) and len(array) == 15: 
    print("AMEX")
elif sum % 10 == 0 and array[0] == 5 and (array[1] in [1, 2, 3, 4, 5]) and len(array) == 16:
    print("MASTERCARD")
elif sum % 10 == 0 and array[0] == 4 and (len(array) == 16 or len(array) == 13):
    print("VISA")
else:
    print("INVALID")
