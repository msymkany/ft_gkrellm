#ifndef IMONITORMODULE_HPP_
# define IMONITORMODULE_HPP_

class IMonitorModule {
public:
	IMonitorModule(){};
	virtual ~IMonitorModule() = 0 {};
	virtual void 	monitorInfo() = 0;

};

#endif
