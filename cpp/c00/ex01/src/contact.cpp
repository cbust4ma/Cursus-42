/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:05:25 by cbustama          #+#    #+#             */
/*   Updated: 2022/09/27 18:10:59 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string contact::get_firstname()
{
	return (first_name);
}

void contact::set_firstname(std::string first_name)
{
	this->first_name = first_name;
}

std::string contact::get_lastname()
{
	return (last_name);
}

void contact::set_lastname(std::string last_name)
{
	this->last_name = last_name;
}

std::string contact::get_nickname()
{
	return (nickname);
}

void contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string contact::get_phone()
{
	return (phone);
}

void contact::set_phone(std::string phone)
{
	this->phone = phone;
}

std::string contact::get_darksecret()
{
	return (darkest_secret);
}

void contact::set_darksecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

contact::~contact(void)
{
//std::cout<<"esto se elimina" << std::endl;
	return ;
}

contact::contact(void)
{
	return ;
}

