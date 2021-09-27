import numpy as np
import matplotlib.pyplot as plt
   
# Figure size (inches)
figwidth = 5.5
figheight = figwidth / 1.33333
plt.figure(figsize=(figwidth, figheight))

# We need to read the data from the .txt file

textname = 'iterations.txt' 

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
      
# Let's plot the results    
   
plt.plot(N, it , linewidth = 0.5 , color = 'pink')
plt.plot(N, it , '.' , color = 'red')
      
plt.title("Number of required transformations vs the matrix size N", fontsize=10)
plt.ylabel('Number of transformations')
plt.xlabel("N")
plt.grid(True) #Grids get painted

# The graph is saved in a .pdf file

plt.savefig("Problem6_plot.pdf")
