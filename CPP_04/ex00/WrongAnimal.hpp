/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:20:59 by yajallal          #+#    #+#             */
/*   Updated: 2023/07/20 18:23:17 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>
class WrongAnimal {

protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& copy);
	void setType(std::string type);
	std::string getType() const;
	void makeSound() const;
	~WrongAnimal();
};
#endif