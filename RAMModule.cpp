#include "RAMModule.hpp"

RAMModule::RAMModule() : IMonitorModule("Hostname/username module") { monitorInfo(); }
RAMModule::RAMModule(const RAMModule & rhs) { *this = rhs; }
RAMModule	&RAMModule::operator=(const RAMModule & rhs)
{
	_title = rhs._title;
	return *this;
}

RAMModule::~RAMModule() { return; }

void RAMModule::monitorInfo() {
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
										  (host_info64_t)&vm_stats, &count))
	{
		long long freeMemory = vm_stats.free_count * page_size;

		long long usedMemory = (vm_stats.active_count +
								vm_stats.inactive_count +
								vm_stats.wire_count) *  page_size;
		long long totalMemory = freeMemory + usedMemory;

		double procent = static_cast<double>(usedMemory * 100) / static_cast<double>(totalMemory);
		std::ostringstream stream;
		stream << procent;
		std::string str = stream.str();
		const char* ret = str.c_str();

		long pages = sysconf(_SC_PHYS_PAGES);
		long page_size = sysconf(_SC_PAGE_SIZE);
		std::stringstream ss;
		ss << (pages * page_size / 1073741824.0);
		std::string s = ss.str();
		_info.push_back(s  + ".0 GB");
//		std::cout << pages * page_size / 1073741824.0 << ".0 GB :total" << std::endl;
		ss.str(std::string());
		ss << (ret);
		s = ss.str();
		_info.push_back(s);
//		std::cout << ret << " :usage "<< std::endl;
		ss.str(std::string());
		ss << (static_cast<double>(freeMemory) / 1000000000.0);
		s = ss.str();
		_info.push_back(s);
//		std::cout << static_cast<double>(freeMemory) / 1000000000.0  << " :free "<< std::endl;
		ss.str(std::string());
		ss << (static_cast<double>(usedMemory) / 1000000000.0);
		s = ss.str();
		_info.push_back(s);
//		std::cout << static_cast<double>(usedMemory) / 1000000000.0 << " :usedMemory "<< std::endl;
	}
	return ;
}
