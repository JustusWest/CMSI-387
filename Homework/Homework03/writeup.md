# Homework 3

## Problem 2

Our program avoids deadlock using the "resource hierarchy solution". The idea behind this is that each philosopher picks up and *locks* the lower numbered fork first, then the higher numbered fork. By using this system, the last philosopher will always be able to pick up both forks. Once he sets down the fork, the first philosopher will then be able to pick up both forks, this pattern then circles around the table so that every philosopher is able to eat.

## Problem 4

| file                      | size (bytes) | time (seconds) |
| ------------------------- | ------------ | -------------- |
| noX.txt                   | 0            | 0.000172       |
| x.txt                     | 1            | 0.000188       |
| beeMovie.txt              | 55,317       | 0.000200       |
| extremelyLongWithX.txt    | 15,125,684   | 0.029887       |
| extremelyLongWithOutX.txt | 15,125,682   | 0.029818       |
| longInMiddle.txt          | 15,125,683   | 0.012530       |

## Problem 5

The bounded buffer class would be good to use.

The TopicServer's receive method will not return to its caller until after all of the subscribers have received the message, but with the bounded buffer acting as an intermediate storage area we won't need to wait for all the messages.