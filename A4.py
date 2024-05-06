def create_set():
    my_set = []
    choice = 'y'
    while choice[0].lower() == 'y':
        print("\n Enter The Number:")
        num = int(input())
        my_set.append(num)
        choice = input("\n Do you want to enter more numbers? (y/n)")
    return my_set

def Add_Element(A, num):
    pos = int(input("\nEnter the position at which you want to insert the element: "))
    A.insert(pos, num)
    print(A)
    
def Remove_Element(A, num):
    count = 0
    for i in range(len(A)):
        if A[i] == num:
            count += 1
    if count >= 1:
        pos = A.index(num)
        new_A = A[:pos] + A[pos+1:]
        print(new_A)
    else:
        print("Element not in the array")

def Union_Function(setA, setB):
    C = list({i: i for i in setA + setB}.values())
    print("Union set: ", C)

def Intersection_Function(setA, setB):
    C = [i for i in setA if i in setB]
    print("Intersection set: ", C)

def Difference_Function(setA, setB):
    C = [element for element in setA if element not in setB]
    print("Difference Set: ", C)

def Contains_Element(A, num):
    found = False
    for i in range(len(A)):
        if A[i] == num:
            found = True
            break
    return found

def Size_of_Set(A):
    count = len(A)
    return count

def Subset_Function(A, B):
    if all(i in A for i in B):
        print("\n Yes, Subset Exists")
    else:
        print("\n No, Subset Does not exists")

# Driver Code
A = set()
print("\n Create set A")
A = create_set()
print("A = ", A)
B = set()
print("\n Create set B")
B = create_set()
while True:
    print("Main Menu")
    print("1. Add an element to the set")
    print("2. Remove an element from the set")
    print("3. Membership Of element")
    print("4. Size of the Set")
    print("5. Union")
    print("6. Intersection")
    print("7. Difference")
    print("8. Check subset")
    print("9. Exit")
    choice = int(input("enter your choice"))
    
    if choice == 1:
        print("A= ", A)
        num = int(input("Enter element to be added in this set: "))
        Add_Element(A, num)
    elif choice == 2:
        print("A = ", A)
        num = int(input("enter number to be removed from this set:"))
        print(A)
        Remove_Element(A, num)
    elif choice == 3:
        print("A =", A)
        num = int(input("enter the number to be searched from the set:"))
        if Contains_Element(A, num):
            print("\n The element is present in the set:")
        else:
            print("\n The element is not present in the set")
    elif choice == 4:
        print("A =", A)
        print("\n The size of the set is:", Size_of_Set(A))
    elif choice == 5:
        print("A = ", A)
        print("B = ", B)
        Union_Function(A, B)
    elif choice == 6:
        print("A = ", A)
        print("B = ", B)
        Intersection_Function(A, B)
    elif choice == 7:
        print("A = ", A)
        print("B = ", B)
        Difference_Function(A, B)
    elif choice == 8:
        print("A = ", A)
        print("B = ", B)
        Subset_Function(A, B)
    else:
        print("Exiting")
        break
