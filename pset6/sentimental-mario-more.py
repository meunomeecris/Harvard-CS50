import cs50

# Get a valid number from user between 1 and 8
while True:
    height = cs50.get_int("Height: ")
    if height > 0 and height < 9:
        break

spaces = height - 1
for i in range(1, height + 1):
    print(" " * spaces, end="")
    print("#" * i, end="")
    print("  ", end="")
    print("#" * i)
    spaces -= 1
