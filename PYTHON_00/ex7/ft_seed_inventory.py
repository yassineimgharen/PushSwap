# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_seed_inventory.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 21:26:45 by yaimghar          #+#    #+#              #
#    Updated: 2025/12/17 21:49:10 by yaimghar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str):
    if (unit == "packets"):
        print(f"{seed_type.capitalize()} seeds: {quantity} packets available")
    elif (unit == "grams"):
        print(f"{seed_type.capitalize()} seeds: {quantity} grams total")
    elif (unit == "area"):
        print(f"{seed_type.capitalize()} seeds: covers {quantity} square meters")
    else :
        print("Unknown unit type")

# ft_seed_inventory("tomato", 15, "packets")
# ft_seed_inventory("carrot", 8, "grams")
ft_seed_inventory("lettuce", 12, "area")
    