number=int(input("Please enter a number grater than 9"))
if number<=9:print("Lütfen 9'dan büyük bir numara giriniz")
else:
steps=0
print(number,end="")
while number>=10:
digit_sum=0
temp_number=number
while temp_number>0:
digit_sum+=temp_number%10
temp_number//=10
number=digit_sum
steps+=1
print(f" -> {number}", end="")
print(f"\nFinal value:{number}")
print(f"Total steps:{steps}")
#TASK2
while True:
n=int(input("Please enter a number between 10 and 100:"))
if 10<= n <=100:
break
else:
print("Invalid input.Please enter a number between 10 and 100.")
fizz_count=0
buzz_count=0
fizzbuzz_count=0
for i in range(1, n+1):
if i%7==0:
print(f"({i} is skipped)20")
continue
if i%3==0 and i%5==0:
print("FizzBuzz")
fizzbuzz_count +=1
elif i%3==0:
print("Fizz")
fizz_count +=1
elif i%5==0:
print("Buzz")
buzz_count +=1
else:
print(i)
print("---Summary---")
print(f"Fizz count: {fizz_count}")
print(f"Buzz count: {buzz_count}")
print(f"FizzBuzz count: {fizzbuzz_count}")
#TASK3
print("\n" + "="*40 +"\n")
print("--- Task 3: Patterm Generator---")
while True:
try:
n=int(input("Please enter a number between 3 and 9:"))
if 3<= n <=9:
break
else:
print("Invalid input.Please enter a number between 3 and 9.")
except ValueError:
print("Please enter a valid integer.")
for i in range(1, 2 * n):
k=n -abs(n-i)
for j in range (1, k+1):
print(j,end="")
print()
