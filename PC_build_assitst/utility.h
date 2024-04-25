#ifndef UTILITY_H
#define UTILITY_H

#include <QMetaType>
#include <fstream>
#include <sstream>
#include <iostream>


// Перечисление для задач пользователя
enum class UserTasks
{
    Gaming,
    ContentCreation,
    Study,
    OfficeTasks,
    Other,
};


// Перечисление для производителя CPU
enum class CPUMaker
{
    Intel,
    AMD,
    Auto,
};

// Перечисление для производителя GPU
enum class GPUMaker
{
    NVIDIA,
    AMD,
    Auto,
    None,
};

// Перечисление для объема оперативной памяти (RAM)
enum class RAMSize
{
    Auto,
    GB_4,
    GB_8,
    GB_16,
    GB_32,
    GB_64,
    GB_128,
};

// Перечисление для объема SSD
enum class SSDSize
{
    Auto,
    None,
    GB_256,
    GB_512,
    GB_1TB,
    GB_2TB,
};

// Перечисление для объема HDD
enum class HDDSize
{
    Auto,
    None,
    GB_500,
    GB_1000,
    GB_2000,
    GB_4000,
};

struct PCConfigurations {
    UserTasks userTasks;
    double budget;
    CPUMaker cpuMaker;
    GPUMaker gpuMaker;
    RAMSize ramSize;
    SSDSize ssdSize;
    HDDSize hddSize;
};



// Регистрация перечислений для использования в сигналах и слотах Qt
Q_DECLARE_METATYPE(UserTasks)
Q_DECLARE_METATYPE(CPUMaker)
Q_DECLARE_METATYPE(GPUMaker)
Q_DECLARE_METATYPE(RAMSize)
Q_DECLARE_METATYPE(SSDSize)
Q_DECLARE_METATYPE(HDDSize)


#endif // UTILITY_H
