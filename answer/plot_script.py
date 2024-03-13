import matplotlib.pyplot as plt
import numpy as np

print("runing python plotting the data...")

# Read the data from the file
t, y = np.loadtxt('output.txt', delimiter='\t', unpack=True)

# Plot the data
plt.figure(figsize=(10, 6))
plt.plot(t, y, label='Square Wave Approximation')
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Square Wave using Fourier Series Approximation')
plt.grid(True)
plt.legend()

# Save the plot as an image file
plt.savefig('square_wave.png', dpi=300)

print("Plot saved")
plt.show()