# print("hello world!")
'''
def egcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        gcd, x, y = egcd(b % a, a)
        return gcd, y - (b // a) * x, x


print(egcd(26513, 32321))
'''
'''
from factordb.factordb import FactorDB
import gmpy2

c = 240986837130071017759137533082982207147971245672412893755780400885108149004760496
n = 831416828080417866340504968188990032810316193533653516022175784399720141076262857
e = 65537

f = FactorDB(n)
f.connect()
p, q = f.get_factor_list()
ph = (p-1)*(q-1)
d = gmpy2.invert(e, ph)
plaintext = pow(c, d, n)
print("Flag: {}".format(bytearray.fromhex(format(plaintext, 'x')).decode()))

def check(n):
    m = n % 10
    t = n
    while n:
        if m != 0 and t % m != 0:
            return True
        n //= 10
        m = n % 10
    return False
    
for i in range(int(input())):
    n = int(input())
    while check(n):
        n += 1
    print(n)
    '''

# print (12**65537 % 391)


#print (pow(12, 65537, 391))

#print(206^173)
#given N number of days as input. Calculate the number of years, weeks and days from N days.
'''
n=int(input())
if(n>=365):
    year=n//365
    n=n%365
    print(year)
else:
    print(0)
if(n>=7):
    week=n//7
    n=n%7
    print(week)
else:
    print(0)
print(n)
'''
#given a string if string is 34T it should print 340, if string is 34H it should print 3400, if string is 34D it should print 34000
'''
s=input()
s1=s[-1]
s=s[:-1]
if(s1=='T'):
    print(s+'0')
elif(s1=='H'):
    print(s+'00')
else:
    print(s+'000')
'''
'''
a=int(input())
print("100:" + str(a//100))
a=a%100
print("50:" + str(a//50))
a=a%50
print("10:" + str(a//10))
a=a%10
print("1:" + str(a//1))
'''

#write a program that reads string s and checks if all the given conditions are satisfied.
#the first three characters of s is NXT
#the remaining characters of s contains a number. number should be divisible by 2 or 7
'''
s=input()
if(s[:3]=='NXT'):
    s=s[3:]
    if(s.isdigit()):
        if(int(s)%2==0 or int(s)%7==0):
            print("Special String")
        else:
            print("Not a Special String")
    else:
        print("Not a Special String")
else:
    print("Not a Special String")


a=int(input())
b=a*a
a=str(a)
b=str(b)
a=a[-1]
b=b[-1]
if(a==b):
    print("Equal")
else:
    print("Not Equal")


a=int(input())
print("100:" + str(a//100))
a=a%100
print("50:" + str(a//50))
a=a%50
print("10:" + str(a//10))
a=a%10
print("1:" + str(a//1))


a = int(input())
print("500: " + str(a//500) + " 50: " + str((a%500)//50) + " 10: " + str((a%50)//10) + " 1: " + str(a%10))


g1=[1,7,13,19,25]
g2=[2,8,14,20,26]
g3=[3,9,15,21,27]
g4=[4,10,16,22,28]
g5=[5,11,17,23,29]
g6=[6,12,18,24,30]
a=int(input())
if(a in g1):
    print("Group 1")
elif(a in g2):
    print("Group 2")
elif(a in g3):
    print("Group 3")
elif(a in g4):
    print("Group 4")
elif(a in g5):
    print("Group 5")
else:
    print("Group 6")


n=int(input())
if(n>=365):
    year=n//365
    n=n%365
    print(year)
else:
    print(0)
if(n>=7):
    week=n//7
    n=n%7
    print(week)
else:
    print(0)
print(n)

n=int(input())
print(str(n//365) + " years " + str((n%365)//7) + " weeks " + str((n%365)%7) + " days")


a=int(input())
print("100 Notes: " + str(a//100))
a=a%100
print("50 Notes: " + str(a//50))
a=a%50
print("20 Notes: " + str(a//20))
a=a%20
print("10 Notes: " + str(a//10))


a = int(input())
print("2000:" + str(a//2000) + " 500:" + str((a%2000)//500) + " 200:" + str(((a%2000)%500)//200) + " 50:" + str((((a%2000)%500)%200)//50) + " 20:" + str(((((a%2000)%500)%200)%50)//20) + " 5:" + str((((((a%2000)%500)%200)%50)%20)//5) + " 2:" + str(((((((a%2000)%500)%200)%50)%20)%5)//2) + " 1:" + str(((((((a%2000)%500)%200)%50)%20)%5)%2))


#given the weekday of the first day of the month, determine the day of the week of the given date in the month.
w=input()
d=int(input())
if(w=='Monday'):
    if(d%7==1):
        print("Monday")
    elif(d%7==2):
        print("Tuesday")
    elif(d%7==3):
        print("Wednesday")
    elif(d%7==4):
        print("Thursday")
    elif(d%7==5):
        print("Friday")
    elif(d%7==6):
        print("Saturday")
    else:
        print("Sunday")
elif(w=='Tuesday'):
    if(d%7==1):
        print("Tuesday")
    elif(d%7==2):
        print("Wednesday")
    elif(d%7==3):
        print("Thursday")
    elif(d%7==4):
        print("Friday")
    elif(d%7==5):
        print("Saturday")
    elif(d%7==6):
        print("Sunday")
    else:
        print("Monday")
elif(w=='Wednesday'):
    if(d%7==1):
        print("Wednesday")
    elif(d%7==2):
        print("Thursday")
    elif(d%7==3):
        print("Friday")
    elif(d%7==4):
        print("Saturday")
    elif(d%7==5):
        print("Sunday")
    elif(d%7==6):
        print("Monday")
    else:
        print("Tuesday")
elif(w=='Thursday'):
    if(d%7==1):
        print("Thursday")
    elif(d%7==2):
        print("Friday")
    elif(d%7==3):
        print("Saturday")
    elif(d%7==4):
        print("Sunday")
    elif(d%7==5):
        print("Monday")
    elif(d%7==6):
        print("Tuesday")
    else:
        print("Wednesday")
elif(w=='Friday'):
    if(d%7==1):
        print("Friday")
    elif(d%7==2):
        print("Saturday")
    elif(d%7==3):
        print("Sunday")
    elif(d%7==4):
        print("Monday")
    elif(d%7==5):
        print("Tuesday")
    elif(d%7==6):
        print("Wednesday")
    else:
        print("Thursday")
elif(w=='Saturday'):
    if(d%7==1):
        print("Saturday")
    elif(d%7==2):
        print("Sunday")
    elif(d%7==3):
        print("Monday")
    elif(d%7==4):
        print("Tuesday")
    elif(d%7==5):
        print("Wednesday")
    elif(d%7==6):
        print("Thursday")
    else:
        print("Friday")
else:
    if(d%7==1):
        print("Sunday")
    elif(d%7==2):
        print("Monday")
    elif(d%7==3):
        print("Tuesday")
    elif(d%7==4):
        print("Wednesday")
    elif(d%7==5):
        print("Thursday")
    elif(d%7==6):
        print("Friday")
    else:
        print("Saturday")

#print n integers in python
n=int(input())
for i in range(1,n+1):
    print(i)

#rock paper scissors game in python
a=input()
b=input()
if(a=='Rock' and b=='Scissors'):
    print("Abhinav wins")
elif(a=='Rock' and b=='Paper'):
    print("Anjali wins")
elif(a=='Scissors' and b=='Rock'):
    print("Anjali wins")
elif(a=='Scissors' and b=='Paper'):
    print("Abhinav wins")
elif(a=='Paper' and b=='Rock'):
    print("Abhinav wins")
elif(a=='Paper' and b=='Scissors'):
    print("Anjali wins")
else:
    print("Draw")

n=int(input())
print("1000:" + str(n//1000))
n=n%1000
print("500:" + str(n//500))
n=n%500
print("100:" + str(n//100))
n=n%100
print("50:" + str(n//50))
n=n%50
print("20:" + str(n//20))
n=n%20
print("5:" + str(n//5))
n=n%5
print("1:" + str(n//1))
n=n%1


n=int(input())
i=1
while(i<=n):
    print(i)
    i=i+1


m=int(input())
n=int(input())
i=m
while(i<=n):
    print(i)
    i=i+1


n=int(input())
i=1
sum=0
while(i<=n):
    sum=sum+i
    i=i+1
print(sum/n)


n=int(input())
i=1
while(i<=n):
    print(i*i*i)
    i=i+1


n=int(input())
sum=0
for i in range(1,n+1):
    m=int(input())
    sum=sum+m
print(sum) 


#pattern printing reactangle
n=int(input())
m=int(input())
for i in range(1,n+1):
    for j in range(1,m+1):
        print("*",end="")
    print()


n=int(input())
i=n+1
while(i<=n+10):
    print(i)
    i=i+1


m=int(input())
n=int(input())
sum=0
for i in range(m,m+n):
    sum=sum+i

#right angle triangle
n=int(input())
for i in range(1,n+1):
    for j in range(1,i+1):
        print("*",end=" ")
    print()
print(sum)


n=int(input())
i=0
sum=0
while(i<=n):
    sum=sum+i
    i=i+1
print(sum)


n=int(input())
mul=1
for i in range(1,n+1):
    m=int(input())
    mul=mul*m
print(mul)


a=input()
for i in range (0,len(a)):
    print(a[i])


#pattern printing
n=int(input())
m=int(input())
for i in range(1,n+1):
    for j in range(1,m+1):
        print(i,end=" ")
    print() 


n=int(input())
for i in range(1,n+1):
    for j in range(1,i+1):
        print("*",end=" ")
    print()
for i in range(1,n+1):
    for j in range(1,i+1):
        print("*",end=" ")
    print()


n=int(input())
m=int(input())
mul=1
for i in range(n+1,n+m+1):
    mul=mul*i
print(mul)


n=int(input())
i=0
sum=0
for i in range(1,n+1):
    sum=sum+i*i
print(sum)


n=int(input())
for i in range(n,0,-1):
    print(i)


n=int(input())
for i in range(1,n+1):
    for j in range(1,i+1):
        print("*",end=" ")
    print() 


n=int(input())
sum=0
for i in range(1,n+1):
    m=int(input())
    sum=sum+m
print(sum)
'''
'''
   1
  22
 3 3
4  4
 3 3
  22
   1

n=int(input())
for i in range(1,n+1):
    if(i==1):
        left_spaces=" "* ((n-i)*2)
        print(left_spaces + str(i))
    else:
        left_spaces=" "* ((n-i)*2)
        middle_spaces=" "* (2*i-3)
        numbers=str(i)
        print(left_spaces + numbers + middle_spaces + numbers)

        k=n-1
for j in range(1,n):
    if j==n-1:
        left_spaces=" "* ((j)*2)
        print(left_spaces + str(1))
    else:
        left_spaces=" "* ((j)*2)
        middle_spaces=" "* (2*k-3)
        numbers=str(k)
        print(left_spaces + numbers + middle_spaces + numbers)
        k=k-1
'''


'''
    1
   1 2
  1 2 3
 1 2 3 4
1 2 3 4 5
if n=5 then print the above pattern
'''
'''
n = int(input("Enter the number of rows: "))

for i in range(1, n+1):
    for j in range(1, n-i+1):
        print(" ", end="")
    for j in range(1, i+1):
        print(j, end=" ")
    print()
'''

print(9//2)