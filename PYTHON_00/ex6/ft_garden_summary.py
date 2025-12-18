# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_garden_summary.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaimghar <yaimghar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 20:30:02 by yaimghar          #+#    #+#              #
#    Updated: 2025/12/17 21:25:46 by yaimghar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_garden_summary():
    garden_name = input("Enter garden name: ")
    plants_number = input("Enter number of plants: ")
    status = "Growing well!"
    
    print(f"Garden: {garden_name}")
    print(f"Plants: {plants_number}")
    print(f"Status: {status}")

# ft_garden_summary()