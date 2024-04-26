import json


class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def get_attendance_rate(self, days_present, total_days):
        return days_present / total_days


class School:
    def __init__(self):
        self.students = []

    def add_student(self, student):
        self.students.append(student)

    def get_student_name(self, index):
        return self.students[index].name

    def get_student_age(self, index):
        return self.students[index].age


def main():
    school = School()
    file_name = "students.json"
    while True:
        try:
            with open(file_name) as file:
                data = json.load(file)
        except FileNotFoundError as e:
            print(f"{type(e).__name__}, please try again.")
            file_name = input("Enter the name of the file: ")
            continue
        except json.JSONDecodeError as e:
            print(f"{type(e).__name__}, please try again.")
            file_name = input("Enter the name of the file: ")
            continue
        except PermissionError as e:
            print(f"{type(e).__name__}, please try again.")
            file_name = input("Enter the name of the file: ")
            continue
        except Exception as e:
            print(f"{type(e).__name__}, please try again.")
            file_name = input("Enter the name of the file: ")
            continue
        break

    try:
        for x in data:
            school.add_student(Student(x['Name'], x['Age']))
    except KeyError as e:
        print(f"{type(e).__name__}, file formatted incorrectly. Please try again.")
        return
    except Exception as e:
        print(f"{type(e).__name__}, please try again.")
        return

    while True:
        try:
            index = int(input("Enter the index of the student: "))
            name = school.get_student_name(index)
            age = school.get_student_age(index)
        except ValueError as e:
            print(f"{type(e).__name__}, please try again.")
            continue
        except IndexError as e:
            print(f"{type(e).__name__}, please try again.")
            continue
        except Exception as e:
            print(f"{type(e).__name__}, please try again.")
            continue
        print(name, age, '\n')

        try:
            total_days = int(input('How many days has school been in session this year?: '))
            days_present = int(input('How many days has the student attended school this year?: '))
        except ValueError as e:
            print(f"{type(e).__name__}, please try again.")
            continue
        except Exception as e:
            print(f"{type(e).__name__}, please try again.")
            continue

        try:
            print(name, "'s attendance rate is", school.students[index].get_attendance_rate(days_present, total_days))
        except ZeroDivisionError as e:
            print(f"{type(e).__name__}: 'School days' cannot be zero, please try again.")
            continue
        except Exception as e:
            print(f"{type(e).__name__}, please try again.")
            continue
        break


if __name__ == "__main__":
    main()
