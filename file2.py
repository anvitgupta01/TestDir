# from file1 import *

from .folder1.file3 import dirty as dr

class myclass:
    def __init__(self):
        pass
    def func(self):
        print("yes")
        print("gupta")
    
    def func1(self):
        self.func()
        dr()

def myfunc():
    print("anvit")

def main_fun():
    myfunc()
    # myclass().func()

main_fun()