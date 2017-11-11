#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <iostream>
#include <sstream>
#include <sys/sysctl.h>
#include <sys/types.h>


//RAM
#include <unistd.h>
#include <mach/mach_host.h>
#include <sstream>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>

#define BUFFERLEN 128




void usa()
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

    std::cout << _activity << std::endl;
}

void model()
{
    size_t tes = 100;

    char cp[100];
    sysctlbyname("hw.model", &cp, &tes, NULL, 0);
    char *cpy2 = cp;
    std::cout << cpy2 << std::endl;
}

void physmem()
{
    size_t test2 = sizeof(int);

    int cpy;
    sysctlbyname("hw.memsize", &cpy, &test2, NULL, 0);
    std::ostringstream stream;
    stream << cpy;
    std::string str = stream.str();
    const char* cstr = str.c_str();
    std::cout << cstr << std::endl;
}

void ncpu()
{
    size_t test2 = sizeof(int);
    int cpy;
    sysctlbyname("hw.ncpu", &cpy, &test2, NULL, 0);
    std::ostringstream stream;
    stream << cpy;
    std::string str = stream.str();
    const char* cstr = str.c_str();
    std::cout << cstr << std::endl;
}


void usage()
{
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
        std::cout << pages * page_size / 1073741824.0 << ".0 :total" << std::endl;

        std::cout << ret << " :usage "<< std::endl;
        std::cout << static_cast<double>(freeMemory) / 1000000000.0  << " :free "<< std::endl;
        std::cout << static_cast<double>(usedMemory) / 1073741824.0 << " :usedMemory "<< std::endl;
    }
    return ;
}


int main(){


    char str[256];
    size_t size = sizeof(str);
    int ret = sysctlbyname("kern.version", &str, &size, NULL, 0);
    std::cout << str  << std::endl;


    char buffer[BUFFERLEN];
    size_t bufferlen = BUFFERLEN;
    sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
    printf("%s\n", buffer);

    ncpu();   //количество ядер

    model();        //модель

 //   physmem();      //физическая память
    usa();          //активити


    /*----------------------------------------------------------*/
    /*                 RAM                                      */
    /*----------------------------------------------------------*/

     usage();
}