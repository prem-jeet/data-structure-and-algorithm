from stack import Stack

s = Stack(3)


def interface():
    print("------------------")
    print("    1. Push       ")
    print("    2. Pop        ")
    print("    3. Peek       ")
    print("    4. Size       ")
    print("    5. Is Empty   ")
    print("    6. Print      ")
    print("    7. Exit       ")
    print("------------------")
    print("")


while(True):
    interface()
    choice = int(input("Enter your choice : "))

    if(choice == 1):
        data = int(input("Enter the data : "))
        s.push(data)

    elif(choice == 2):
        data = s.pop()
        print(data, " Popped")

    elif(choice == 3):
        print("Top of the stack contains ", s.peek())

    elif(choice == 4):
        print("stack contains ", s.size(), " items")

    elif(choice == 5):
        print(s.empty())

    elif(choice == 6):
        s.print()

    elif(choice == 7):  # exit
        exit()

    else:
        print("Invalid choice")
