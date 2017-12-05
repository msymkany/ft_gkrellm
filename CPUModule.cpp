#include "CPUModule.hpp"

CPUModule::CPUModule(): IMonitor("CPU module") { monitorInfo(); }
CPUModule::CPUModule(const CPUModule & rhs) { *this = rhs; }
CPUModule	&CPUModule::operator=(const CPUModule & rhs)
{
	_title = rhs._title;
	return *this;
}

CPUModule::~CPUModule() { return; }

void CPUModule::monitorInfo() {

	std::stringstream ss;
	ss << activity();
	std::string ncp = ncpu();
	std::string tot = total();
	if (!_info.empty())
		_info.erase(_info.begin(), _info.end());
	_info.push_back("Model:      " + tot.substr(0, 29));
	_info.push_back("Clock spead:  " + tot.substr(32, 39));
	_info.push_back("Number of cores:  " + ncp);
	_info.push_back("Activity:  " + ss.str() + "%");
}

std::string CPUModule::total()
{
	char buffer[BUFFERLEN];
    size_t bufferlen = BUFFERLEN;
    sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
   	return (buffer);
}

double CPUModule::activity()
{
	std::string activity;
    static double oTotal = 0;
    static double oWork = 0;
    natural_t cpuCount;
    processor_cpu_load_info_t cpuInfo;
    mach_msg_type_number_t nbInfo;
    kern_return_t ret = host_processor_info(mach_host_self(), PROCESSOR_CPU_LOAD_INFO, &cpuCount, reinterpret_cast<processor_info_array_t *>(&cpuInfo), &nbInfo);
    if (ret != KERN_SUCCESS) {
        activity = "0";
    }

    size_t system = 0;
    size_t user = 0;
    size_t idle = 0;
    size_t totalSystemTime = 0;
    size_t totalUserTime = 0;
    size_t totalIdleTime = 0;
    for (natural_t i = 0; i < cpuCount; i++) {
        system = cpuInfo[i].cpu_ticks[CPU_STATE_SYSTEM];
        user = cpuInfo[i].cpu_ticks[CPU_STATE_USER] + cpuInfo[i].cpu_ticks[CPU_STATE_NICE];
        idle = cpuInfo[i].cpu_ticks[CPU_STATE_IDLE];

        totalSystemTime += system;
        totalUserTime += user;
        totalIdleTime += idle;
    }

    double nTotal = totalIdleTime + totalSystemTime + totalUserTime;
    double nWork = totalSystemTime + totalUserTime;

    double _activity = (nWork - oWork)/(nTotal - oTotal) * 100;
    std::stringstream activeS;
    activeS << _activity;
    activity = activeS.str();

    oTotal = nTotal;
    oWork = nWork;

    return (_activity);
}

std::string CPUModule::ncpu()
{
	size_t test2 = sizeof(int);
    int cpy;
    sysctlbyname("hw.ncpu", &cpy, &test2, NULL, 0);
    std::ostringstream stream;
    stream << cpy;
    return (stream.str());
}
