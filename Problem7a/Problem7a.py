# -*- coding: utf-8 -*-
"""
@author: María Pérez
"""
import matplotlib.pyplot as plt
from typing import List

n: int = 10
h: float = 1/n

"""
The code opens the data file, creates three vectors, and fills them with three 
eigenvectors that corresponds to the three lowest eigenvalues
"""
with  open('Problem7a.txt', "r") as  infile:
    
    lines = infile.readlines ()

    first_eigenvector: List[float] = []
    second_eigenvector: List[float] = []
    third_eigenvector: List[float] = []
    
    for  line in  lines:
        vals = line.split()
        first_eigenvector.append(float(vals [0]))
        second_eigenvector.append(float(vals [1]))
        third_eigenvector.append(float(vals [2]))

"""
We create a vector x that will contain the values of x that are calculated
in the following loop
"""

x: List[float] = []

for i in range (0,n+1):
    x.append(0 +i*h)

#Plot
          
plt.figure()
plt.title("v_i vs x_i for the three lowest eigenvalues")
plt.plot(x, first_eigenvector, color = 'blue', label = 'Lowest solution of the differential equation')
plt.legend(loc = "lower left")
plt.ylim([-0.9,0.7])
plt.xlabel('x')
plt.ylabel('v')
plt.grid(True)

plt.plot(x, second_eigenvector, color = 'red', label = 'Second lowest solution of the differential equation')
plt.legend(loc = "lower left")
plt.ylim([-0.9,0.7])
plt.xlabel('x')
plt.ylabel('v')
plt.grid(True)

plt.plot(x, third_eigenvector, color = 'green', label = 'Third lowest solution of the differential equation')
plt.legend(loc = "lower left")
plt.ylim([-0.9,0.7])
plt.xlabel('x')
plt.ylabel('v')
plt.grid(True)
plt.show()

#The graph is saved in a PDF file

plt.savefig("Problem7a.pdf")
