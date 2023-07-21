/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:12:35 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/21 11:36:56 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_cat_brain; 
public:
	Cat();
	Cat(Cat& copy);
	Cat& operator=(const Cat& copy);
	std::string getType() const;
	void makeSound() const;
	~Cat();
};

#endif