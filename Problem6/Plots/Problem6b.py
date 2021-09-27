import numpy as np
import matplotlib.pyplot as plt
   
# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

# We will read the data from the dense matrices.

textname = 'iterations_densematrix.txt' 

# A loop will read the data and save it in two vectors

for i in range(0,1):
    N1 = []

    it1 = []

    with open(textname , "r") as infile:
        infile.readline()
        lines= infile.readlines()
        for line in lines:
            vals = line.split()
            N1.append(float(vals[0]))
            it1.append(float(vals[1]))
    
    N = np.array(N1)
    
    it = np.array(it1)
    
    plt.plot(N, it , linewidth = 0.5 )
    plt.plot(N, it , '.' , color = 'blue' , label = 'Dense')
    
    
# Let's compare them with the previous tridiagonal matrices   
textname2 = 'iterations.txt' 



for i in range(0,1):
    N1 = []

    it1 = []

    with open(textname2 , "r") as infile:
        infile.readline()
        lines= infile.readlines()
        for line in lines:
            vals = line.split()
            N1.append(float(vals[0]))
            it1.append(float(vals[1]))
    
    N = np.array(N1)
    
    it = np.array(it1)
      
# Let's plot the results

plt.plot(N, it , linewidth = 0.5, color = 'pink' )
plt.plot(N, it , '.' , color = 'red' , label = 'Triangular')
    
plt.title("Number of required transformations vs the matrix size N", fontsize=10)
plt.legend()
plt.ylabel('Number of transformations')
plt.xlabel("N")
plt.grid(True) #Grids get painted

# The graph is saved in a .pdf file

plt.savefig("Problem6b_plot.pdf")
