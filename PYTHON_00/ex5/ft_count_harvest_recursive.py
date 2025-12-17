def ft_count_harvest_recursive(n1, isrun, in_p):
    if (isrun):
        in_p = input("Days until harvest: ")
        isrun = False
    if n1 > int(in_p):
        return
    print(f"Day {n1}")
    ft_count_harvest_recursive(n1 + 1, isrun, in_p)
    if n1 == int(in_p):
        print("Harvest time!")
ft_count_harvest_recursive(1, True, None)


# def ft_count_harvest_recursive(i, remain_days):
#     if remain_days == None:
#         remain_days = input("Days until harvest: ")
#     print(f"Day {i}")
#     if (i < int(remain_days)):
#         ft_count_harvest_recursive(i + 1, remain_days)
#     else:
#         print("Harvest time!")
# ft_count_harvest_recursive(1, None)