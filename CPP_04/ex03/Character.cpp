/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:59:44 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/26 10:19:09 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->_name = "Default name";
	this->_nb_materias = 0;
	this->unq_nb_materias = 0;
	for (int i = 0; i < 4; i++)
	{
		this->_slots[i] = NULL;
		this->unq_slots[i] = NULL;
	}
}

Character::Character(std::string name)
{
	this->_name = name;
	this->_nb_materias = 0;
	this->unq_nb_materias = 0;
	for (int i = 0; i < 4; i++)
	{
		this->_slots[i] = NULL;
		this->unq_slots[i] = NULL;
	}
}

Character::Character(const Character& copy)
{
	*this = copy;
}

Character& Character::operator=(const Character& copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_nb_materias = copy._nb_materias;
		this->unq_nb_materias = copy.unq_nb_materias;
		for (int i = 0; i < 4; i++)
		{
			if (copy._slots[i] != NULL)
			{
				if (this->_slots[i] != NULL)
					delete this->_slots[i];
				this->_slots[i] = copy._slots[i]->clone();
			}
			if (copy.unq_slots[i] != NULL)
			{
				if(this->unq_slots[i] != NULL)
					delete this->unq_slots[i];
				this->unq_slots[i] = copy.unq_slots[i]->clone();
			}
		}
		
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m != NULL && this->_nb_materias < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_slots[i] == NULL)
			{
				this->_slots[i] = m->clone();
				delete m;
				break;
			}
		}
		this->_nb_materias++;
	}
	else
	{
		std::cout << "there no empty slot" << std::endl;
		delete m;
	}
}

void Character::unequip(int idx)
{
	if (idx < 4 && this->unq_nb_materias < 4)
	{
		if (this->_slots[idx] == NULL)
			std::cout << "cannot unequip this index;" << std::endl;
		else
		{
			for (int i = 0; i < 4; i++)
			{
				if (this->unq_slots[i] == NULL)
				{
					this->unq_slots[i] = this->_slots[idx];
					this->_slots[idx] = NULL;
					this->_nb_materias--;
					break;
				}
			}
			this->unq_nb_materias++;
		}
	}
	else
		std::cout << "index in not valid" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4)
	{
		if (this->_slots[idx])
			this->_slots[idx]->use(target);
		else
			std::cout << "index " << idx << " is for an empty slot" << std::endl;
	}
	else
		std::cout << "index in not valid" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_slots[i])
			delete this->_slots[i];
		if(this->unq_slots[i])
			delete this->unq_slots[i];
	}
}