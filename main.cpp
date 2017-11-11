// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2017/11/11 17:00:17 by msymkany          #+#    #+#             //
//   Updated: 2017/11/11 17:00:21 by msymkany         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMonitorModule.hpp"
#include "DateTimeModule.hpp"
#include "HostnameModule.hpp"
#include "OSModule.hpp"
#include "RAMModule.hpp"


int main()
{
	DateTimeModule t;
	HostnameModule h;
	OSModule	os;

	std::cout<< std::endl;
	std::cout << t.getTitle() << std::endl;
	std::cout << t.getInfo(0) << std::endl;
	std::cout<< std::endl;

	std::cout << h.getTitle() << std::endl;
	for (size_t i = 0; i < h.getSize(); i++)
	{
		std::cout << h.getInfo(i) << std::endl;
	}
	std::cout<< std::endl;

	std::cout << os.getTitle() << std::endl;
	for (size_t i = 0; i < os.getSize(); i++)
	{
		std::cout << os.getInfo(i) << std::endl;
	}
	std::cout<< std::endl;

	std::cout << "RAM info"<< std::endl;
	RAMModule ram;
	std::cout<< std::endl;
	return 0;
}