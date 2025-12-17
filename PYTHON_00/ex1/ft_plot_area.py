import math


def ft_plot_area():
    print("Enter length:", end=' ')
    length = input()
    print("Enter width:", end=' ')
    width = input()
    print(f"Plot area: {int(length) * int(width)}")
    # print("Plot area: " + str(int(length) * int(width)))
    # print("Plot area: {}". format(int(length) * int(width)))

    y = True
    while y:
        # y = input("enter a number: ")
        print("Enter a number:", end=' ')
        y = input()
        try :
            val = float(y)
            y = False
        except ValueError:
            print("That's not a number! Try again.")
    print("You entered the number:" + f"{val:.0f}")
        