from linklist import Linklist


def interface():

    print()
    print("++++++++  LINKED LIST INTERFACE  ++++++++")
    print("+++                                   +++")
    print("+++       1. Insert at start          +++")
    print("+++       2. Insert at end            +++")
    print("+++       3. Delete from beginning    +++")
    print("+++       4. Delete from end          +++")
    print("+++       5. Print list               +++")
    print("+++       6. print size of list       +++")
    print("+++       7. Insert at position       +++")
    print("+++       8. Delete from position     +++")
    print("+++       9. Clear list               +++")
    print("+++      10. Get data from position   +++")
    print("+++       0. Quit                     +++")
    print("+++                                   +++")
    print("+++++++++++++++++++++++++++++++++++++++++")


L = Linklist()
choice = 0

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
        L.delete_from_start()

    elif choice == 4:
        L.delete_from_end()

    elif choice == 5:
        Linklist.print_list(L)

    elif choice == 6:
        print("The list has ", L.size(), " elements.")

    elif choice == 7:
        position = int(input("Enter the position : "))
        data = int(input("Enter the data : "))
        L.insert_at_position(position, data)

    elif choice == 8:
        position = int(input("Enter the position : "))
        L.delete_from_position(position)

    elif choice == 9:
        Linklist.clear(L)

    elif choice == 10:
        position = int(input("Enter the position : "))
        data = L.get_data_from(position)
        if(data != None):
            print(data, "is present at position ", position)

    elif choice == 0:
        exit()

    else:
        print("Invalid option")
