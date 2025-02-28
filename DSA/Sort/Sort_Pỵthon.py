from time import *
import numpy as np

# Read Input
with open('input.inp', 'r') as file:
    lines = file.readlines()
    arrs = []
    for i in range(0, len(lines), 2):
        n = int(lines[i].strip())
        arrs.append(list(map(int, lines[i + 1].strip().split())))

# Sort and Check time
count  = 0
for arr in arrs:
    count += 1
    start_time = time()
    np.sort(arr)
    finish_time = time()

    print(f"Array {count} (Sorted in {finish_time - start_time:.6f} seconds)")