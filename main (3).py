import numpy as np

def f(x):
    return x[0]**2 + np.exp(x[0]**2 + x[1]**2) + 4*x[0] + 3*x[1]

def grad_f(x):
    dfdx1 = 2*x[0] + 2*x[0]*np.exp(x[0]**2 + x[1]**2) + 4
    dfdx2 = 2*x[1]*np.exp(x[0]**2 + x[1]**2) + 3
    return np.array([dfdx1, dfdx2])

def gradient_descent(alpha, max_iter):
    x = np.array([0.0, 0.0]) # Начальная точка
    for _ in range(max_iter):
        x -= alpha * grad_f(x)
    return x

alpha = 0.01
max_iter = 1000
optimum = gradient_descent(alpha, max_iter)

print("птимальая точка:", optimum)
print("оптимальное значение  функции:", f(optimum))
