import cs50

# Get a valid number from user
while True:
    change = cs50.get_float("Change owed: ")
    if change > 0:
        print(f"change: {change}")
        break

# Calculate the numbers of coins

        # print(f"r: { remainder}")


def calculate_coins(change):
    while True:
        if change >= 0:
            remainder = int(change * 100)

            quarters = remainder // 25
            remainder -= quarters * 25

            dimes = remainder // 10
            remainder -= dimes * 10

            nickels = remainder // 5
            remainder -= nickels * 5

            pennies = remainder

            print(quarters + dimes + nickels + pennies)
            break

        else:
            print("No coins are needed")


calculate_coins(change)
