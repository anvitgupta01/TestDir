from folder1.file3 import dirty as dr
from folder1.folder2.file5 import *
import file2 as f2

class myclass:
    def func(self):
        print("yes")
        print("gupta")
    
    def func1(self):
        self.func()
        dr()

class child_class(myclass):
    def func1(self):
        super().func1()

def funcr():
    dr()

    class myclass1:
        def func4():
            mnh()

y = child_class()
y.func1()
x = f2.myfunc()