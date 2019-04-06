# Homework 3

## Problem 2

Our program avoids deadlock using the "resource hierarchy solution". The idea behind this is that each philosopher picks up and *locks* the lower numbered fork first, then the higher numbered fork. By using this system, the last philosopher will always be able to pick up both forks. Once he sets down the fork, the first philosopher will then be able to pick up both forks, this pattern then circles around the table so that every philosopher is able to eat.

## Problem 5

The bounded buffer class would be good to use.

The TopicServer's receive method will not return to its caller until after all of the subscribers have received the message, but with the bounded buffer acting as an intermediate storage area we won't need to wait for all the messages.