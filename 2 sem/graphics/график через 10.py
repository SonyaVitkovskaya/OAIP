import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots()
fig.set(facecolor = 'blue')
x = np.linspace(-2, 2, 100)

y = lambda x: abs(x)
y1 = lambda x: x**3+x**2
y2 = lambda x: np.sin(x)

plt.plot(x,y(x))
plt.plot(x,y1(x))
plt.plot(x, y2(x))
plt.show()
