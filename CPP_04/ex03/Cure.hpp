/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:03:32 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/24 18:05:00 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
class Cure : public AMateria
{
	public :
		Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &copy);
		AMateria* clone() const;
		void use(ICharacter& target);
		~Cure();
};
#endif