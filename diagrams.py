import matplotlib.pyplot as plt

n = [0.5, 1, 5, 10, 15, 20, 25, 30, 35, 40]

seq_times = [0.003, 0.004, 0.074, 0.302, 0.765, 1.17, 1.81, 2.58, 3.55, 4.66]
omp_times = [0.003, 0.003, 0.024, 0.08, 0.165, 0.23, 0.32, 0.46, 0.6, 1]

plt.plot(n, seq_times, "r", label = "Sequential")
plt.plot(n, omp_times, "g", label = "OpenMP")
plt.legend()
plt.xlabel("Size n x 10^3")
plt.ylabel("Execution Time (sec)")
plt.xlim(left=0)
plt.show()