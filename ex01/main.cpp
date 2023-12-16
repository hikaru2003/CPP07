/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hikaru <hikaru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:02 by hikaru            #+#    #+#             */
/*   Updated: 2023/12/16 12:18:36 by hikaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int	main()
{
	int tab[] = {0, 1, 2, 3, 4};

	iter(tab, 5, print<const int>);

	return (0);
}