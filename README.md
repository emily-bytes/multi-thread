CPSC 5042 Assignment 1: Multi-threading Program

Write a multithreaded program using C or C++ that calculates various statistical 
values for a list of numbers. First, we will pass a list of numbers to this program 
on the command line. Then the program creates three separate worker threads. 
One thread will determine the average of the numbers, the second will 
determine the maximum value, and the third will determine the minimum value. 
For example, the inputs of the program are the following integers:   
90 81 78 95 79 72 85 
The program will report:  
The average value is 82 
The minimum value is 72 
The maximum value is 95 

The variables representing the average, minimum, and maximum values will be 
stored globally. The worker threads will set these values, and the parent thread 
will output the values once the workers have exited. 
