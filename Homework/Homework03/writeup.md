# Homework 3

## Problem 2

Our program avoids deadlock using the "resource hierarchy solution". The idea behind this is that each philosopher picks up and *locks* the lower numbered fork first, then the higher numbered fork. By using this system, the last philosopher will always be able to pick up both forks. Once he sets down the fork, the first philosopher will then be able to pick up both forks, this pattern then circles around the table so that every philosopher is able to eat.