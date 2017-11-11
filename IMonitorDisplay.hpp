#ifndef IMONITORDISPLAY_HPP_
# define IMONITORDISPLAY_HPP_

#include <iostream>
#include "IMonitorModule.hpp"

class IMonitorDisplay {
public:
	IMonitorDisplay();
	IMonitorDisplay(const IMonitorDisplay & rhs);
	IMonitorDisplay &operator=(const IMonitorDisplay & rhs);
	virtual ~IMonitorDisplay();

	bool		getdisplay() const;
	void		setdisplay( bool rhs );

protected:
	bool		display;

};

#endif
