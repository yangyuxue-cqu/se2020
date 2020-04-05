# -*- coding:utf8 -*-
import math
import decimal
import os

PI = 3.1415926

def menu_select():
    menu = input("""
       **************************************************************
                         Welcome to Snow Calculator(Python)
       **************************************************************
                                  1.sin x
                                  2.cos x
                                  3.tan x
                                  4.cot x
                                  5.Clean screen 
                                  0.to quit
       ==============================================================
                              Thanks for use.
       ==============================================================
   """)
    if str.isdigit(menu):
        menu = int(menu)
        if menu > 5 and menu < 0:
            menu = menu_select()
    else:
        print("error input! Please re-input...")
        menu = menu_select()
    return menu

def input_x():
    o = input("Please input x: ")
    o = float(o)
    x = o
    while x > 360:
        x = x - 360
    x = x * PI / 180
    return (o, x)

def myabs(x):
    if x < 0:
        return x
    else:
        return -x

def sin(x, tol=1e-15, nmax=100):
    decimal.getcontext().prec = 7
    b=0
    for i in range (nmax):
        e = (2*i+1)
        c=(math.factorial(e))
        a = (-1)**i*decimal.Decimal(x)**(e)/c
        b0 = b
        b += a
        if b0 == b:
            break
    return b
    
def cos(x):
    x = PI / 2 - x
    return sin(x)

def tan(x):
    return (sin(x) / cos(x))

def cot(x):
    return (1 / tan(x))

if __name__ == "__main__":
    menu = menu_select()
    while menu != 0:
        if menu == 1:
            (o, x) = input_x()
            result = sin(x)
            print("sin(%.2f) = %.7f" % (o, result))
            menu = menu_select()
            continue
        if menu == 2:
            (o, x) = input_x()
            result = cos(x)
            print("cos(%.2f) = %.7f" % (o, result))
            menu = menu_select()
            continue
        if menu == 3:
            (o, x) = input_x()
            if o != 0 and o / 90 % 2 != 0:
                print("tan(%.2f) is not exists." % o)
            else:
                result = tan(x)
                print("tan(%.2f) = %.7f" % (o, result))
            menu = menu_select()
            continue
        if menu == 4:
            (o, x) = input_x()
            if o / 90 % 2 == 0:
                print("cot(%.2f) is not exists." % o)
            else:
                if o % 90 == 0:
                    result = float(0)
                else:
                    result = cot(x)
                print("cot(%.2f) = %.7f" % (o, result))
            menu = menu_select()
            continue
        if menu == 5:
            os.system("cls")
            menu = menu_select()
            continue
        else:
            print("error input! Please re-input...")
            menu = menu_select()
    
    print("Thanks for use Snow Calculator(Python).")
