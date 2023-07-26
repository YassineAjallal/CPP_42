/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:22:41 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/26 10:19:31 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	this->_nb_materias = 0;
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	*this = copy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	if (this != &copy)
	{
		this->_nb_materias = copy._nb_materias;
		for (int i = 0; i < 4; i++)
			if(copy._materias[i] != NULL)
			{
				if (this->_materias[i])
					delete this->_materias[i];
				this->_materias[i] = copy._materias[i]->clone();
			}
	}
	return (*this);
}


void MateriaSource::learnMateria(AMateria* m)
{
	if (m != NULL && this->_nb_materias < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i] == NULL)
			{
				this->_materias[i] = m->clone();
				delete m;
				break;
			}
		}
		this->_nb_materias++;
	}
	else
	{
		delete m;
		std::cout << "there no empty slot" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			if (this->_materias[i]->getType() == type)
				return (this->_materias[i]->clone());
	}
	return (NULL);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_materias[i] != NULL)
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
}