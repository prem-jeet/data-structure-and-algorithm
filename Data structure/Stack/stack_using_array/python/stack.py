class Stack:
    def __init__(self, n):
        self.arr = [0 for i in range(n)]
        self.top = -1
        self.capacity = n

    # Push function to insert at end
    def push(self, data):
        if(self.__isFull()):
            print("Stack full")
            return

        self.top += 1
        self.arr[self.top] = data

    # Pop functioo to remove the lst element
    def pop(self):
        if(self.__isEmpty()):
            print("Stack empty")
            return

        temp = self.arr[self.top]
        self.top -= 1
        return temp

    # Peek function to lookm at the last element
    def peek(self):
        if(self.__isEmpty()):
            print("Stack empty")
            return

        temp = self.arr[self.top]
        return temp

    # size function returns the size of the stack
    def size(self):
        return self.top+1

    # empty function returns if the stack is empty
    def empty(self):
        return self.__isEmpty()

    # print the stack
    def print(self):
        if(self.__isEmpty()):
            print("Stack empty")
            return

        for i in range(self.top, -1, -1):
            print(self.arr[i])

    # HEPLER FUNCTIONS
    def __isEmpty(self):
        return self.top == -1

    def __isFull(self):
        return self.top == self.capacity-1
