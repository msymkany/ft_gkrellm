#ifndef NCURCESDISPLAY_HPP_
# define NCURCESDISPLAY_HPP_

#include <iostream>

class NCurcesDisplay {
public:
	NCurcesDisplay();
	NCurcesDisplay(const NCurcesDisplay & rhs);
	NCurcesDisplay &operator=(const NCurcesDisplay & rhs);
	virtual ~NCurcesDisplay();

};

#endif
