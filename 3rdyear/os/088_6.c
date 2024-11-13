/***********************************************
 * *
 * * 	Name : Hrithvik Kondalkar
 * *	Roll : 002211001088
 * *
 * * 	Assignment 6 :
 * *	getting system information from /proc
 * *
 *
 *
 * * 	Compilation command : gcc 088_6.c -o 088_6.out
 * * 	Exectution command  : ./088_6.out
 * 
 * *
 * *
 * *	Output generated : 
        Processor Information:
        Vendor ID: AuthenticAMD
        Model Name: AMD EPYC 7763 64-Core Processor
        Cache Size: 512 KB

        Kernel Information:
        Kernel Name: Linux
        Kernel Release: 6.5.0-1025-azure
        Operating System Name: Linux version 6.5.0-1025-azure (buildd@lcy02-amd64-063) (x86_64-linux-gnu-gcc-11 (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0, GNU ld (GNU Binutils for Ubuntu) 2.38) #26~22.04.1-Ubuntu SMP Thu Jul 11 22:33:04 UTC 2024

        Memory Information:
        Total Memory: 7929 MB
        Free Memory: 264 MB

        System Uptime:
        Time since last boot: 2 hours, 14 minutes, 42 seconds
 ************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void print_processor_info() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    if (cpuinfo == NULL) {
        perror("Failed to open /proc/cpuinfo");
        return;
    }

    char line[BUFFER_SIZE];
    char vendor_id[BUFFER_SIZE] = "N/A";
    char model_name[BUFFER_SIZE] = "N/A";
    int cache_size = -1;

    while (fgets(line, sizeof(line), cpuinfo)) {
        if (strstr(line, "vendor_id") == line) {
            sscanf(line, "vendor_id : %s", vendor_id);
        } else if (strstr(line, "model name") == line) {
            sscanf(line, "model name : %[^\n]", model_name);
        } else if (strstr(line, "cache size") == line) {
            sscanf(line, "cache size : %d", &cache_size);
        }
    }
    fclose(cpuinfo);

    printf("Processor Information:\n");
    printf("Vendor ID: %s\n", vendor_id);
    printf("Model Name: %s\n", model_name);
    printf("Cache Size: %d KB\n", cache_size); // cache size is in KB
}

void print_kernel_info() {
    FILE *osname = fopen("/proc/sys/kernel/ostype", "r");
    FILE *osrelease = fopen("/proc/sys/kernel/osrelease", "r");
    FILE *version = fopen("/proc/version", "r");

    if (!osname || !osrelease || !version) {
        perror("Failed to open /proc/sys/kernel files");
        return;
    }

    char kernel_name[BUFFER_SIZE];
    char kernel_release[BUFFER_SIZE];
    char os_name[BUFFER_SIZE];

    fgets(kernel_name, sizeof(kernel_name), osname);
    fgets(kernel_release, sizeof(kernel_release), osrelease);
    fgets(os_name, sizeof(os_name), version);

    printf("\nKernel Information:\n");
    printf("Kernel Name: %s", kernel_name);
    printf("Kernel Release: %s", kernel_release);
    printf("Operating System Name: %s", os_name);

    fclose(osname);
    fclose(osrelease);
    fclose(version);
}

void print_memory_info() {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char line[BUFFER_SIZE];
    unsigned long total_memory = 0, free_memory = 0;

    while (fgets(line, sizeof(line), meminfo)) {
        if (strstr(line, "MemTotal") == line) {
            sscanf(line, "MemTotal: %lu kB", &total_memory);
        } else if (strstr(line, "MemFree") == line) {
            sscanf(line, "MemFree: %lu kB", &free_memory);
        }
    }
    fclose(meminfo);

    printf("\nMemory Information:\n");
    printf("Total Memory: %lu MB\n", total_memory / 1024); // Convert KB to MB
    printf("Free Memory: %lu MB\n", free_memory / 1024);   // Convert KB to MB
}

void print_uptime() {
    FILE *uptime_file = fopen("/proc/uptime", "r");
    if (uptime_file == NULL) {
        perror("Failed to open /proc/uptime");
        return;
    }

    float uptime_seconds;
    fscanf(uptime_file, "%f", &uptime_seconds);
    fclose(uptime_file);

    int hours = (int)(uptime_seconds / 3600);
    int minutes = (int)((uptime_seconds - (hours * 3600)) / 60);
    int seconds = (int)(uptime_seconds - (hours * 3600) - (minutes * 60));

    printf("\nSystem Uptime:\n");
    printf("Time since last boot: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
}

int main() {
    // Print processor information
    print_processor_info();

    // Print kernel information
    print_kernel_info();

    // Print memory information
    print_memory_info();

    // Print system uptime
    print_uptime();

    return 0;
}
