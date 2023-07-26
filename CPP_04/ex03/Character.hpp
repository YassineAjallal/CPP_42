/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:43:17 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/25 16:36:12 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <cstring>

class Character : public ICharacter
{
	private:
		std::string _name;
		int _nb_materias;
		int unq_nb_materias;
		AMateria *_slots[4];
		AMateria *unq_slots[4];
	public:
		Character();
		Character(std::string name);
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character();
};

#endif