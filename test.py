"""one liners"""
# create a 2d array of 0's with 'rows' rows and 'cols' cols
cols,rows = 3,5
buckets = [[0 for col in range(cols)] for row in range(rows)]
# check membership
print(42 in [42, 43, 76])
# create an array of whole numbers
y = [x for x in range(5)]
# print customers earning >$1M
customers = [("John", 240000),("Alice", 120000),("Ann", 1100000),("Zach", 44000)] 
whales = [x for x,y in customers if y>1000000]
print(whales)
# top earners in a company (same as above, but for a dictionary)
e = {'Alice' : 100000,'Bob' : 99817,'Carol' : 122908,'Frank' : 88123,'Eve' : 93121}
top_earners = [(k, v) for k, v in e.items() if v >= 100000]
print(top_earners)
# create nested loops, for eg to print this -> [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]
print([(x, y) for x in range(3) for y in range(3)])
# check first ten square numbers if they are divisible by two
print([x ** 2 for x in range(10) if x % 2 > 0])
# lowercase a list
list1 = [x.lower() for x in ['I', 'AM', 'NOT', 'SHOUTING']]
# 2d list of words from text that are longer than 3 letters
text = '''
Call me Ishmael. Some years ago - never mind how long precisely - having
little or no money in my purse, and nothing particular to interest me
on shore, I thought I would sail about a little and see the watery part
of the world. It is a way I have of driving off the spleen, and regulating
the circulation. - Moby Dick'''
## One-Liner
w = [[x for x in line.split() if len(x)>3] for line in text.split('\n')] # list of lists for each line break
w2 = [x for x in text.split() if len(x)>3] # single list
## Result
print(w)
print(w2)

# reading from a file
filename = "FindFive.py" # this code
f = open(filename)
lines = []
for line in f:
    lines.append(line.strip())
print(lines)
f.close()
# in one line, it would be ->
print([line.strip() for line in open("FindFive.py")])

f.close()

# creating a dictionary from list using list comprehension
planets = ['Mercury', 'Venus', 'Earth', 'Mars', 'Jupiter', 'Saturn', 'Uranus', 'Neptune']
planet_to_initial = {planet: planet[0] for planet in planets}
planet_to_initial

