#ifndef IMONITORDISPLAY_HPP_
# define IMONITORDISPLAY_HPP_

class IMonitorDisplay {
public:
	virtual ~IMonitorDisplay() {};
	virtual void start() = 0;
};

#endif
