# # Results
# Runtime Graph
Note: The input points were generated using numpy.random python module.

![Graph](..\output_graphs\runtime_graph_normal.png)
![Graph](..\output_graphs\runtime_graph_circular.png)
![Graph](..\output_graphs\runtime_graph_boundary.png)

# Conclusions

Runtime analysis

1. Jarvis March runs comparitively much faster for test cases having large number of data points but less convex hull points. This is because the algorithm is output sensitive with complexity O(nh).

2. Grahm's Scan runs comparitively much faster when test cases have a large number of output convex hull points.This mis because Grahm's Scan has a complexity of O(nlogn) which is output insensitive.

3. The runtime for Quickhull algorithm depends on the distribution of input points. It runs slower than the other 2 algorithms for large test cases. This is because it has a worst case time complexity of O(n2). But for some distributions it might show faster runtime as the average case runtime for Quick Hull is O(nlogn).

4. Jarvis March is clearly better for test cases having small output whereas Grahm's Scan would be better for large test cases having large output. Quick hull should be used only for particular cases where the point distribution is suitable.

Robustness

1. All three programs are prone to floating point errors.

2. Graham's scan algorithm as given in the original paper has an issue related to calculation of angles. In this assignment, we have implemented a slight variation of the algorithm where it isnt necessary to accurately compute the angle and only relies on relative position of points. 






# # Console Output

# Circular Distribution

Test 1

Number of points : 10

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.000

 Jarvis March Algorithm
 Execution Time in seconds: 0.000

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.000

 Number of hull points : 8


Test 2

Number of points : 100

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.000

 Jarvis March Algorithm
 Execution Time in seconds: 0.001

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.000

 Number of hull points : 13


Test 3

Number of points : 1000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.001

 Jarvis March Algorithm
 Execution Time in seconds: 0.001

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.002

 Number of hull points : 41


Test 4

Number of points : 10000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.017

 Jarvis March Algorithm
 Execution Time in seconds: 0.038

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.144

 Number of hull points : 76


Test 5

Number of points : 100000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.311

 Jarvis March Algorithm
 Execution Time in seconds: 1.473

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 3.941

 Number of hull points : 222

# Normal Distribution

Test 1

Number of points : 10

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.000

 Jarvis March Algorithm
 Execution Time in seconds: 0.000

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.000

 Number of hull points : 7



Test 2

Number of points : 100

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.001

 Jarvis March Algorithm
 Execution Time in seconds: 0.000

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.001

 Number of hull points : 11



Test 3

Number of points : 1000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.001

 Jarvis March Algorithm
 Execution Time in seconds: 0.001

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.003

 Number of hull points : 15



Test 4

Number of points : 10000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.026

 Jarvis March Algorithm
 Execution Time in seconds: 0.013

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.032

 Number of hull points : 15



Test 5

Number of points : 100000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.283

 Jarvis March Algorithm
 Execution Time in seconds: 0.134

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.315

 Number of hull points : 17

# All hull points: Points lie on a circle

Test 1

Number of points : 10

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.000

 Jarvis March Algorithm
 Execution Time in seconds: 0.000

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.000

 Number of hull points : 10


Test 2

Number of points : 100

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.000

 Jarvis March Algorithm
 Execution Time in seconds: 0.000

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.002

 Number of hull points : 100


Test 3

Number of points : 1000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.001

 Jarvis March Algorithm
 Execution Time in seconds: 0.089

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 0.162

 Number of hull points : 1000


Test 4

Number of points : 10000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.013

 Jarvis March Algorithm
 Execution Time in seconds: 6.684

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 17.530

 Number of hull points : 10000


Test 5

Number of points : 20000

 Grahm's Scan Algorithm
 Execution Time in seconds: 0.048

 Jarvis March Algorithm
 Execution Time in seconds: 26.835

 QuickHull Algorithm (not ordered)
 Execution Time in seconds: 71.041

 Number of hull points : 20000