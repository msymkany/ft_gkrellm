#ifndef IMONITORDISPLAY_HPP_
# define IMONITORDISPLAY_HPP_

#include <iostream>

class IMonitorDisplay {
public:
	IMonitorDisplay();
	IMonitorDisplay(const IMonitorDisplay & rhs);
	IMonitorDisplay &operator=(const IMonitorDisplay & rhs);
	virtual ~IMonitorDisplay();

protected:
	
	bool		display;
	bool		getdisplay() const;
	void		setdisplay( bool rhs );
	
};

#endif
