import math
from typing import Any
from typing import Callable


class Student:
    def __init__(self, first_name: str, last_name: str, gpa: float):
        self._first_name = first_name
        self._last_name = last_name
        self._gpa = gpa

    def get_full_name(self):
        return self._first_name + " " + self._last_name

    def get_gpa(self):
        return self._gpa

    def get_email(self):
        return self._first_name + "_" + self._last_name + "@example.com"


s1 = Student('John', 'Doe', 4.0)

print(s1.get_full_name())
print(s1.get_gpa())
print(s1.get_email())

x = 1 - 5
print(math.fabs(2 - 4))

talking = True
hour = 6
if talking and hour in range(7, 20):
    print("False")
else:
    print("True")

a = 0
b = 9
print(a + b == 10 or a == 10 or b == 10)

u = 190
sum1 = abs(u - 100)
sum2 = abs(u - 200)
print(sum1, sum2)
if sum1 in range(11) or sum2 in range(11):
    print("True")
else:
    print("False")

str1 = "candy"
not_string = "not " + str1
if str1[0:3] == "not":
    print(str1)
else:
    print(not_string)

str3 = 'code'
n = 2
w = str3[-1] + str3[1:-1:] + str3[0]
print(w)

start = 30
end = 36
list1 = []
for x in range(start, end):
    if x % 15 == 0:
        k = "FizzBuzz"
        list1.append(k)
    elif x % 3 == 0:
        m = "Fizz"
        list1.append(m)
    elif x % 5 == 0:
        c = "Buzz"
        list1.append(c)
    else:
        list1.append(x)
print(list1)


class C:
    def __init__(self):
        self._x = None

    def getx(self):
        return self._x

    def setx(self, value):
        self._x = value

    def delx(self):
        del self._x

    x = property(getx, setx, delx, "I'm the 'x' property.")


c = C()

c.x = 10

print(c.x)


class Parrot:
    def __init__(self):
        self._voltage = None

    @property
    def voltage(self):
        return self._voltage

    @voltage.setter
    def voltage(self, value):
        self._voltage = value

    @voltage.deleter
    def voltage(self):
        del self._voltage


pp = Parrot()
pp.voltage = 100
print(pp.voltage)

names = []
while len(names) < 5:
    # names.append(input("Enter a name: "))
    print(sorted(names))
    break

numbers: list[int] = list(range(1, 11))
text: str = 'Hello, World!'

rev: slice = slice(None, None, -1)
f_five: slice = slice(None, 5)

print(numbers[f_five])
print(text[rev])

set_a: set[int] = {1, 2, 3, 4, 5}
set_b: set[int] = {4, 5, 6, 7, 8}

print(set_a | set_b)
print(set_a - set_b)
print(set_b - set_a)
print(set_a & set_b)
print(set_a ^ set_b)


class Book:
    def __init__(self, title: str, pages: int) -> None:
        self.title = title
        self.pages = pages

    def __format__(self, format_spec: Any) -> str:
        match format_spec:
            case 'time':
                return f'{self.pages / 60:.2f}h'
            case 'caps':
                return self.title.upper()
            case _:
                raise ValueError(f'Unknown specifier for Book()')


def main() -> None:
    hairy_potter = Book('Very Harry Potter', 300)
    python_daily: Book = Book('Python Daily', 20)

    print(f'{hairy_potter:caps}')
    print(f'Read time: {hairy_potter:time}')

    print(f'{python_daily:caps}')
    print(f'Read time: {python_daily:time}')


if __name__ == '__main__':
    main()

users: dict[int, str] = {0: 'Bob', 1: 'Mario'}

# Using the walrus operator removes the need to use "user: str | None = user.get(2)".
# user: str | None = user.get(2)

if user := users.get(1):
    print(f'{user} exists!')
else:
    print('User not found!')


def get_info(texts: str) -> dict:
    return {'words': (words := texts.split()),
            'word_count': len(words),
            'character_count': len(''.join(words))}


print(get_info('Bob'))
print(get_info('Hello Bob'))
print(get_info('My name is Bob'))


def multipy_setup(a: float) -> Callable:
    def multiply(b: float) -> float:
        return a * b

    return multiply


double: Callable = multipy_setup(2)
triple: Callable = multipy_setup(3)

print(double(5))
print(triple(5))
print(double(10))
print(triple(10))


def myfunc(q: int):
    return lambda a: a * n


my_doubler = myfunc(2)

print(my_doubler(11))
