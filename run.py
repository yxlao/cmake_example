import sys
import os
curr_path = os.path.dirname(os.path.realpath(__file__))
sys.path.append(curr_path + "/build")
import cmake_example
print(cmake_example.add(1, 2))
