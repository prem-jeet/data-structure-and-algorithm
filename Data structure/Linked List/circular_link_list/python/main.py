from circularLL import circularLL

L = circularLL()


def interface():
    print()
    print("++++++++  LINKED LIST INTERFACE  ++++++++")
    print("+++                                   +++")
    print("+++       1. Insert at start          +++")
    print("+++       2. Insert at end            +++")
    print("+++       3. Insert at position       +++")
    print("+++       4. Delete from beginning    +++")
    print("+++       5. Delete from end          +++")
    print("+++       6. Delete from position     +++")
    print("+++       7. Print list               +++")
    print("+++       8. Quit                     +++")
    print("+++                                   +++")
    print("+++++++++++++++++++++++++++++++++++++++++")


while(True):
    interface()
    choice = int(input("Enter your choice : "))

    if choice == 1:
        data = int(input("Enter the data : "))
        L.insert_at_beginning(data)

    elif choice == 2:
        data = int(input("Enter the data : "))
        L.insert_at_end(data)

    elif choice == 3:
        position = int(input("Enter the position : "))
        data = int(input("Enter the data : "))
        L.insert_at_position(position, data)

    elif choice == 4:
        L.delete_from_beginning()

    elif choice == 5:
        L.delete_from_end()

    elif choice == 6:
        position = int(input("Enter the position : "))
        L.delete_from_position(position)

    elif choice == 7:
        L.print_list()

    elif choice == 8:
        exit()

    else:
        print("Invalid option")
