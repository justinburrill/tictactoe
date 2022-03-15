

from math import floor


def ask():
    pos = input("enter your number: ")

    # y = int(pos) - int(pos) % 3
    y = floor(int(pos)/3)
    x = int(pos) % 3
    print("y: ", y)
    print("x: ", x)
    ask()
ask()