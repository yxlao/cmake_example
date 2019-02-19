import sys
import os
curr_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(curr_path + "/build")
import cmake_example

def dummy_func(value):
        print("inside python dummy_func:", value)
        return False

cmake_example.dummy_callback(dummy_func, 123)
print(cmake_example.add(1, 2))
