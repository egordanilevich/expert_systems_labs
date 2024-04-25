#include "pc_build_assist.h"
#include "ui_pc_build_assist.h"

PC_build_assist::PC_build_assist(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PC_build_assist)
{
    config = new PCConfigurations();
    ui->setupUi(this);
    QStringList targetItems = {"Другое", "Игры", "Создание контента", "Офис", "Учеба"};
    ui->comboBox_target->addItems(targetItems);
    QStringList CPUItems = {"Авто", "INTEL", "AMD"};
    ui->comboBox_CPU->addItems(CPUItems);
    temp_budget = 0;

}

PC_build_assist::~PC_build_assist()
{
    delete config;
    delete ui;
}


void PC_build_assist::on_comboBox_target_activated(int index)
{
    QStringList Items;
    ui->comboBox_RAM->clear();
    ui->comboBox_GPU->clear();
    ui->comboBox_SSD->clear();
    ui->comboBox_HDD->clear();
    switch (index) {
    case 1:

        config->userTasks = UserTasks::Gaming;
        target_key = "games";
        Items.clear();
        Items.append({"Авто", "16 Gb", "32 Gb", "64 Gb"});
        ui->comboBox_RAM->addItems(Items);
        Items.clear();
        Items.append({"Авто", "512 Gb", "1 Tb"});
        ui->comboBox_SSD->addItems(Items);
        Items.clear();
        Items.append({"Авто", "Нет Gb", "1 Тb", "2 Tb"});
        ui->comboBox_HDD->addItems(Items);
        Items.clear();
        Items.append({ "Не важно", "NVidia", "AMD"});
        ui->comboBox_GPU->addItems(Items);

        break;
    case 2:
        config->userTasks = UserTasks::ContentCreation;
        target_key = "professional";
        Items.clear();
        Items.append({"Авто","32 Gb", "64 Gb","128 Gb"});
        ui->comboBox_RAM->addItems(Items);
        Items.clear();
        Items.append({"Авто","512 Gb", "1 Tb","2 Tb"});
        ui->comboBox_SSD->addItems(Items);
        Items.clear();
        Items.append({"Авто", "1 Тb", "2 Tb","4 Tb"});
        ui->comboBox_HDD->addItems(Items);
        Items.clear();
        Items.append({"Не важно", "NVidia", "AMD"});
        ui->comboBox_GPU->addItems(Items);

        break;
    case 3:
        config->userTasks = UserTasks::OfficeTasks;
        target_key = "office";
        Items.clear();
        Items.append({"Авто","4 Gb", "8 Gb","16 Gb"});
        ui->comboBox_RAM->addItems(Items);
        Items.clear();
        Items.append({"Авто", "256 Gb", "512 Gb","1 Tb","Нет"});
        ui->comboBox_SSD->addItems(Items);
        Items.clear();
        Items.append({"Авто", "500 Gb", "1 Tb","2 Tb"});
        ui->comboBox_HDD->addItems(Items);
        Items.clear();
        Items.append({"Нет", "NVidia", "AMD", "Не важно"});
        ui->comboBox_GPU->addItems(Items);
        break;
    case 4:
        config->userTasks = UserTasks::Study;
        target_key = "study";
        Items.clear();
        Items.append({"Авто","4 Gb", "8 Gb","16 Gb","32 Gb"});
        ui->comboBox_RAM->addItems(Items);
        Items.clear();
        Items.append({"Авто", "256 Gb", "512 Gb","1 Tb","Нет"});
        ui->comboBox_SSD->addItems(Items);
        Items.clear();
        Items.append({"Авто", "500 Gb", "1 Tb","2 Tb"});
        ui->comboBox_HDD->addItems(Items);
        Items.clear();
        Items.append({"Нет", "NVidia", "AMD", "Не важно"});
        ui->comboBox_GPU->addItems(Items);
        break;
    case 0:
        config->userTasks = UserTasks::Other;
        target_key = "games";
        Items.clear();
        Items.append({"Авто","4 Gb", "8 Gb","16 Gb","32 Gb", "64 Gb", "128 Gb"});
        ui->comboBox_RAM->addItems(Items);
        Items.clear();
        Items.append({"Авто", "256 Gb", "512 Gb","1 Tb","2 Tb","Нет"});
        ui->comboBox_SSD->addItems(Items);
        Items.clear();
        Items.append({"Авто", "500 Gb", "1 Tb","2 Tb","4 Tb", "None"});
        ui->comboBox_HDD->addItems(Items);
        Items.clear();
        Items.append({"Нет", "NVidia", "AMD", "Не важно"});
        ui->comboBox_GPU->addItems(Items);
        break;
    default:
        config->userTasks = UserTasks::Other;
        ui->statusbar->showMessage("ERROR !!!");
        break;
    }
}




void PC_build_assist::on_comboBox_CPU_activated(int index)
{
    switch (index) {
    case 0:
        config->cpuMaker = CPUMaker::Auto;
        break;
    case 1:
        config->cpuMaker = CPUMaker::Intel;
        break;
    case 2:
        config->cpuMaker = CPUMaker::AMD;
        break;
    default:
        config->cpuMaker = CPUMaker::Auto;
        ui->statusbar->showMessage("ERROR !!!");
        break;
    }
}

void PC_build_assist::on_comboBox_GPU_activated(const QString &arg1)
{
    if (arg1 == "Не важно") {
        config->gpuMaker = GPUMaker::Auto;
    }
    else if (arg1 == "NVidia") {
        config->gpuMaker = GPUMaker::NVIDIA;
    }
    else if (arg1 == "AMD") {
        config->gpuMaker = GPUMaker::AMD;
    }
    else if (arg1 == "Нет") {
        config->gpuMaker = GPUMaker::None;
    }
    else
    {
        ui->statusbar->showMessage("ERROR !!!");
        config->gpuMaker = GPUMaker::Auto;
    }

}

//void PC_build_assist::on_comboBox_GPU_activated(int index)
//{
//    //  обработки выбора в comboBox_RAM
//    switch (index) {
//    case 0:
//        config->gpuMaker = GPUMaker::Auto;
//        break;
//    case 1:
//        config->gpuMaker = GPUMaker::NVIDIA;
//        break;
//    case 2:
//        config->gpuMaker = GPUMaker::AMD;
//        break;
//    case 3:
//        config->gpuMaker = GPUMaker::None;
//        break;
//    default:
//        ui->statusbar->showMessage("ERROR !!!");
//        break;
//    }
//}





void PC_build_assist::on_comboBox_RAM_activated(const QString &arg1)
{
    //  обработки выбора в comboBox_RAM
    if (arg1 == "Авто") {
        config->ramSize = RAMSize::Auto;
    } else if (arg1 == "4 Gb") {
        config->ramSize = RAMSize::GB_4;
    } else if (arg1 == "8 Gb") {
        config->ramSize = RAMSize::GB_8;
    } else if (arg1 == "16 Gb") {
        config->ramSize = RAMSize::GB_16;
    } else if (arg1 == "32 Gb") {
        config->ramSize = RAMSize::GB_32;
    } else if (arg1 == "64 Gb") {
        config->ramSize = RAMSize::GB_64;
    } else if (arg1 == "128 Gb") {
        config->ramSize = RAMSize::GB_128;
    }
}

void PC_build_assist::on_comboBox_SSD_activated(const QString &arg1)
{
    //  обработка выбора в comboBox_SSD
    if (arg1 == "Авто") {
        config->ssdSize = SSDSize::Auto;
    } else if (arg1 == "None") {
        config->ssdSize = SSDSize::None;
    } else if (arg1 == "256 Gb") {
        config->ssdSize = SSDSize::GB_256;
    } else if (arg1 == "512 Gb") {
        config->ssdSize = SSDSize::GB_512;
    } else if (arg1 == "1 Tb") {
        config->ssdSize = SSDSize::GB_1TB;
    } else if (arg1 == "2 Tb") {
        config->ssdSize = SSDSize::GB_2TB;
    }
}

void PC_build_assist::on_comboBox_HDD_activated(const QString &arg1)
{
    //  обработки выбора в comboBox_HDD
    if (arg1 == "Авто") {
        config->hddSize = HDDSize::Auto;
    } else if (arg1 == "None") {
        config->hddSize = HDDSize::None;
    } else if (arg1 == "500 Gb") {
        config->hddSize = HDDSize::GB_500;
    } else if (arg1 == "1 Tb") {
        config->hddSize = HDDSize::GB_1000;
    } else if (arg1 == "2 Tb") {
        config->hddSize = HDDSize::GB_2000;
    } else if (arg1 == "4 Tb") {
        config->hddSize = HDDSize::GB_4000;
    }
}



void PC_build_assist::on_pushButton_search_clicked()
{

    bool ok;  // Это флаг, который указывает, успешно ли прошло преобразование
    temp_budget = ui->lineEdit_budget->text().toDouble(&ok);

    if (!ok) {
        ui->statusbar->showMessage("ERROR !!!");
        ui->textBrowser_out->append("ОШИБКА ПРЕОБРАЗОВАНИЯ ЦЕНЫ");

        return;
    }

    config->budget = temp_budget;
    ui->textBrowser_out->append("Итоговый бюджет: "+QString::number(config->budget)+" ");

    if(!Create_config()) {

        ui->statusbar->showMessage("ERROR !!!");
        ui->textBrowser_out->append("ОШИБКА СБОРКИ ПК");
        return;
    }
    else {
        target_params();
        double sum = config->budget - temp_budget;
        ui->textBrowser_out->append("Итоговая сборка: " );
        ui->textBrowser_out->append("цена: "+QString::number(sum)+ " отстаток: "+QString::number(temp_budget));

        ui->textBrowser_out->append("Процессор: " + QString::fromStdString(optimalConfigurations.processor.name));
        ui->textBrowser_out->append("ОЗУ: " + optimalConfigurations.RAM);
        ui->textBrowser_out->append("Мат. плата: " + QString::fromStdString(optimalConfigurations.motherboard.name));
        ui->textBrowser_out->append("Видеокарта: " + QString::fromStdString(optimalConfigurations.graphicsCard.name));
        ui->textBrowser_out->append("SSD: " + QString::fromStdString(optimalConfigurations.ssd.name));
        ui->textBrowser_out->append("HDD: " + QString::fromStdString(optimalConfigurations.hdd.name));
        ui->textBrowser_out->append("Рекомендуемы программы: "+optimalConfigurations.programs);
    }

    ui->textBrowser_out->append("");
    ui->textBrowser_out->append("");
}





void PC_build_assist::loadConfigurations()
{



    //    hdds = readHDDConfig(hddFile);
}

void PC_build_assist::CPU_Search(double cost)
{
    bool find = false;
    processors = JsonReader::readProcessors(readFile("Data/Processors.json"));
    if(cost > temp_budget)
    {
        optimalConfigurations.processor.name = "ERROR";
        ui->statusbar->showMessage("ERROR CPU PRICE!!!");
        return;
    }
    optimalConfigurations.processor.performanceIndex = 0;
    if(config->cpuMaker == CPUMaker::Intel)
    {
        for (auto &proc : processors)
        {
            if(proc.price <= cost and proc.vendor == "Intel")
            {
                if (std::find(proc.usage.begin(), proc.usage.end(), target_key) != proc.usage.end())
                {
                    if(proc.performanceIndex > optimalConfigurations.processor.performanceIndex)
                    {
                        find = true;
                        optimalConfigurations.processor = proc;
                    }
                }
            }
        }
    }
    else if(config->cpuMaker == CPUMaker::AMD)
    {
        for (auto &proc : processors)
        {
            if(proc.price <= cost and proc.vendor == "AMD")
            {
                if (std::find(proc.usage.begin(), proc.usage.end(), target_key) != proc.usage.end())                {
                    if(proc.performanceIndex > optimalConfigurations.processor.performanceIndex)
                    {
                        find = true;
                        optimalConfigurations.processor = proc;
                    }
                }
            }
        }
    }
    else
    {
        for (auto &proc : processors)
        {

            if (std::find(proc.usage.begin(), proc.usage.end(), target_key) != proc.usage.end())            {
                if(proc.performanceIndex > optimalConfigurations.processor.performanceIndex)
                {
                    find = true;
                    optimalConfigurations.processor = proc;
                }
            }

        }
    }
    if(!find) {
        optimalConfigurations.processor.name = "ERROR";
        ui->statusbar->showMessage("ERROR CPU SEARCH!!!");
    }
    else{
        temp_budget -= optimalConfigurations.processor.price;

    }
}

void PC_build_assist::MB_Search(double cost)
{
    optimalConfigurations.motherboard.performanceIndex = 0;
    bool find = false;
    motherboards = JsonReader::readMotherboards(readFile("Data/MB.json"));
    if(cost > temp_budget)
    {
        cost = temp_budget;
    }
    std::cout << "mb.start\n";
    for (auto &mb : motherboards)
    {
        std::cout << "mb.iter\n";
        if(mb.socket == optimalConfigurations.processor.socket and mb.price <= cost) {
            if (std::find(mb.usage.begin(), mb.usage.end(), target_key) != mb.usage.end()) {
                if(optimalConfigurations.motherboard.performanceIndex < mb.performanceIndex) {
                    find = true;
                    optimalConfigurations.motherboard = mb;

                    std::cout << mb.name << std::endl;
                }
            }
        }
    }
    if(!find)
    {
        optimalConfigurations.motherboard.name = "ERROR not find";
        ui->statusbar->showMessage("motherboard ERROR !!!");
    }
    else {
        temp_budget -= optimalConfigurations.motherboard.price;
    }
}

void PC_build_assist::GPU_Search(double cost)
{
    bool find = false;
    optimalConfigurations.graphicsCard.performanceIndex = 0;
    graphicsCards = JsonReader::readGraphicsCards(readFile("Data/GPU.json"));
    if(cost > temp_budget)
    {
        optimalConfigurations.graphicsCard.name = "НЕТ";
        ui->statusbar->showMessage("ERROR !!!");
        return;
    }
    if(config->gpuMaker == GPUMaker::None)
    {
        optimalConfigurations.graphicsCard.name = "НЕТ";
        return;
    }
    optimalConfigurations.graphicsCard.performanceIndex = 0;
    if(config->gpuMaker == GPUMaker::NVIDIA)
    {
        for (auto &gpu : graphicsCards)
        {
            if(gpu.price <= cost and gpu.vendor == "Nvidia")
            {
                if (std::find(gpu.usage.begin(), gpu.usage.end(), target_key) != gpu.usage.end())
                {
                    if(gpu.performanceIndex > optimalConfigurations.graphicsCard.performanceIndex)
                    {
                        find = true;
                        optimalConfigurations.graphicsCard = gpu;
                    }
                }
            }
        }
    }
    else if(config->gpuMaker == GPUMaker::AMD)
    {
        for (auto &gpu : graphicsCards)
        {
            if(gpu.price <= cost and gpu.vendor == "AMD")
            {
                if (std::find(gpu.usage.begin(), gpu.usage.end(), target_key) != gpu.usage.end())
                {
                    if(gpu.performanceIndex > optimalConfigurations.processor.performanceIndex)
                    {
                        find = true;
                        optimalConfigurations.graphicsCard = gpu;
                    }
                }
            }
        }
    }
    else
    {
        for (auto &gpu : graphicsCards)
        {

            if (std::find(gpu.usage.begin(), gpu.usage.end(), target_key) != gpu.usage.end())
            {
                if(gpu.performanceIndex > optimalConfigurations.processor.performanceIndex)
                {
                    find = true;
                    optimalConfigurations.graphicsCard = gpu;
                }

            }
        }
    }
    if(!find)
    {
        optimalConfigurations.graphicsCard.name = "ERROR";
        ui->statusbar->showMessage("GPU ERROR !!!");
    }
    else {
        temp_budget -= optimalConfigurations.graphicsCard.price;

    }
}



void PC_build_assist::SSD_Search(double cost)
{
    if(cost > temp_budget)
    {
        optimalConfigurations.ssd.name = "ERROR";
        ui->statusbar->showMessage("ERROR !!!");
        return;
    }
    if(config->ssdSize != SSDSize::None)
    {
        optimalConfigurations.ssd.price = 0;
        ssds = JsonReader::readSSDs(readFile("Data/SSD.json"));
        if(config->ssdSize == SSDSize::GB_2TB)
        {
            for (auto &ssd : ssds){
                if(ssd.price < cost and ssd.capacity_GB >= 2000)
                {
                    optimalConfigurations.ssd = ssd;
                }
            }
        }
        else if(config->ssdSize == SSDSize::GB_1TB)
        {
            for (auto &ssd : ssds){
                if(ssd.price < cost and ssd.capacity_GB >= 1000)
                {
                    optimalConfigurations.ssd = ssd;
                }
            }
        }
        else if(config->ssdSize == SSDSize::GB_512)
        {
            for (auto &ssd : ssds){
                if(ssd.price < cost and ssd.capacity_GB == 500)
                {
                    optimalConfigurations.ssd = ssd;
                }
            }
        }
        else if(config->ssdSize == SSDSize::GB_256)
        {
            for (auto &ssd : ssds){
                if(ssd.price < cost and ssd.capacity_GB >= 240 and ssd.capacity_GB < 260)
                {
                    optimalConfigurations.ssd = ssd;
                }
            }
        }
        if (optimalConfigurations.ssd.price == 0)
            optimalConfigurations.ssd.name = "нет";
        temp_budget -= optimalConfigurations.ssd.price;
    }
    else
    {
        optimalConfigurations.ssd.name = "нет";
    }
}

void PC_build_assist::SSD_Search_auto(double cost)
{
    std::cout << "ssd auto start search\n";
    if(cost > temp_budget)
    {
        optimalConfigurations.ssd.name = "ERROR";
        ui->statusbar->showMessage("ERROR !!!");
        return;
    }
    if(config->ssdSize != SSDSize::None)
    {
        std::cout << "ssd auto start search\n";
        optimalConfigurations.ssd.price = 0;
        ssds = JsonReader::readSSDs(readFile("Data/SSD.json"));
        if(config->ssdSize == SSDSize::Auto)
        {
            for (auto &ssd : ssds){
                std::cout << "ssd auto cycle\n";
                if(ssd.price < cost)
                {
                    optimalConfigurations.ssd = ssd;
                    std::cout << ssd.name << std::endl;
                }
            }

            if (optimalConfigurations.ssd.price == 0)
                optimalConfigurations.ssd.name = "нет";
            temp_budget -= optimalConfigurations.ssd.price;

        }
        else
        {
            optimalConfigurations.ssd.name = "нет";
        }
    }
    else
    {
        optimalConfigurations.ssd.name = "нет";
    }
}
void PC_build_assist::HDD_Search(double cost)
{
    if(cost > temp_budget)
    {
        optimalConfigurations.hdd.name = "ERROR";
        ui->statusbar->showMessage("ERROR !!!");
        return;
    }
    if(config->hddSize != HDDSize::None)
    {
        optimalConfigurations.hdd.price = 0;
        hdds = JsonReader::readHDDs(readFile("Data/HDD.json"));
        if(config->hddSize == HDDSize::GB_4000)
        {
            for (auto &hdd : hdds){
                if(hdd.price < cost and hdd.capacity_GB == 4000)
                {
                    optimalConfigurations.hdd = hdd;
                }
            }
        }
        else if(config->hddSize == HDDSize::GB_2000)
        {
            for (auto &hdd : hdds){
                if(hdd.price < cost and hdd.capacity_GB == 2000)
                {
                    optimalConfigurations.hdd = hdd;
                }
            }
        }
        else if(config->hddSize == HDDSize::GB_1000)
        {
            for (auto &hdd : hdds){
                if(hdd.price < cost and hdd.capacity_GB == 1000)
                {
                    optimalConfigurations.hdd = hdd;
                }
            }
        }
        else if(config->hddSize == HDDSize::GB_500)
        {
            for (auto &hdd : hdds){
                if(hdd.price < cost and hdd.capacity_GB == 500)
                {
                    optimalConfigurations.hdd = hdd;
                }
            }
        }

        if(optimalConfigurations.hdd.price == 0)
            optimalConfigurations.hdd.name = "нет";

        temp_budget = temp_budget - optimalConfigurations.hdd.price;


    }
    else
    {
        optimalConfigurations.hdd.name = "нет";
    }}

void PC_build_assist::HDD_Search_auto(double cost)
{
    if(cost > temp_budget)
    {
        optimalConfigurations.hdd.name = "ERROR";
        ui->statusbar->showMessage("ERROR !!!");
        return;
    }
    if(config->hddSize != HDDSize::None)
    {
        optimalConfigurations.hdd.price = 0;
        hdds = JsonReader::readHDDs(readFile("Data/HDD.json"));
        if(config->hddSize == HDDSize::Auto)
        {
            for (auto &hdd : hdds){
                if(hdd.price < cost)
                {
                    optimalConfigurations.hdd = hdd;
                    std::cout << hdd.name << std::endl;
                }
            }
            if(optimalConfigurations.hdd.price == 0)
                optimalConfigurations.hdd.name = "нет";

            temp_budget = temp_budget - optimalConfigurations.hdd.price;
        }
        else
        {
            optimalConfigurations.hdd.name = "нет";
        }
    }
    else
    {
        optimalConfigurations.hdd.name = "нет";
    }

}

void PC_build_assist::RAM_config()
{
    if(config->ramSize == RAMSize::GB_128){
        optimalConfigurations.RAM = "128 GB";
        temp_budget = temp_budget - 40000;
        optimalConfigurations.price +=40000;
    }
    else if(config->ramSize == RAMSize::GB_64){
        optimalConfigurations.RAM = "64 GB";
        temp_budget = temp_budget - 15000;
        optimalConfigurations.price += 15000;
    }
    else if(config->ramSize == RAMSize::GB_32){
        optimalConfigurations.RAM = "32 GB";
        temp_budget = temp_budget - 6500;
        optimalConfigurations.price += 6500;
    }
    else if(config->ramSize == RAMSize::GB_16){
        optimalConfigurations.RAM = "16 GB";
        temp_budget = temp_budget - 3200;
        optimalConfigurations.price += 3200;
    }
    else if(config->ramSize == RAMSize::GB_8){
        optimalConfigurations.RAM = "8 GB";
        temp_budget = temp_budget - 1500;
        optimalConfigurations.price += 1500;
    }
    else if(config->ramSize == RAMSize::GB_4){
        optimalConfigurations.RAM = "4 GB";
        temp_budget = temp_budget - 600;
        optimalConfigurations.price += 600;
    }
    else if(config->ramSize == RAMSize::Auto){
        optimalConfigurations.RAM = "Auto";

    }
    else{
        ui->statusbar->showMessage("ERROR !!!");
    }
}

void PC_build_assist::RAM_config_auto(double cost)
{
    if(config->ramSize != RAMSize::Auto)
    {
        return;
    }
    double RAM_cost;
    if(cost < temp_budget)
    {
        RAM_cost = cost;
    }
    else
    {
        RAM_cost = temp_budget / 2;
    }

    if(RAM_cost > 40000){
        optimalConfigurations.RAM = "128 GB";
        temp_budget = temp_budget - 40000;
        optimalConfigurations.price +=40000;
    }
    else if(RAM_cost > 15000){
        optimalConfigurations.RAM = "64 GB";
        temp_budget = temp_budget - 15000;
        optimalConfigurations.price += 15000;
    }
    else if(RAM_cost > 6500){
        optimalConfigurations.RAM = "32 GB";
        temp_budget = temp_budget - 6500;
        optimalConfigurations.price += 6500;
    }
    else if(RAM_cost > 3200){
        optimalConfigurations.RAM = "16 GB";
        temp_budget = temp_budget - 3200;
        optimalConfigurations.price += 3200;
    }
    else if(RAM_cost > 1500){
        optimalConfigurations.RAM = "8 GB";
        temp_budget = temp_budget - 1500;
        optimalConfigurations.price += 1500;
    }
    else if(RAM_cost > 600){
        optimalConfigurations.RAM = "4 GB";
        temp_budget = temp_budget - 600;
        optimalConfigurations.price += 600;
    }
    else{
        optimalConfigurations.RAM = "ERROR RAM GB";

        ui->statusbar->showMessage("ERROR !!!");
    }
}

void PC_build_assist::target_params()
{
    if(config->userTasks == UserTasks::Gaming) {
        optimalConfigurations.programs = " Установите свои любимые игры";
    }
    else if(config->userTasks == UserTasks::ContentCreation) {
        optimalConfigurations.programs = "Устанавливаемые программы вам подскажет руководитель или коллеги";
    }
    else if(config->userTasks == UserTasks::Study) {
        optimalConfigurations.programs = " Пакет office, удобный вам браузер, ПО требуемое учебным заведением";
    }
    else if(config->userTasks == UserTasks::OfficeTasks) {
        optimalConfigurations.programs = "Пакет office, удобный вам браузер, 1С Бухгалтерия, иной софт требуемый организацией";
    }
    else{
        optimalConfigurations.programs = "Цели использования ПК явно не заданы";
    }
}

bool PC_build_assist::Create_config()
{
    std::cout << "start\n";
    RAM_config();
    if(config->userTasks == UserTasks::Gaming) {
        if(config->ssdSize == SSDSize::None) {
            optimalConfigurations.ssd.name = "НЕТ";
        }
        else if(config->ssdSize != SSDSize::Auto)
        {
            SSD_Search(config->budget*0.25);
        }
        if(config->hddSize == HDDSize::None) {
            optimalConfigurations.hdd.name = "НЕТ";
        }
        else if(config->hddSize != HDDSize::Auto) {
            HDD_Search(config->budget*0.2);
        }
        double curr_budget = temp_budget;
        CPU_Search(curr_budget*0.35);
        GPU_Search(curr_budget*0.4);

        RAM_config_auto(curr_budget*0.1);
        if(config->ssdSize == SSDSize::Auto){
            SSD_Search_auto(curr_budget*0.2);
        }
        if(config->hddSize == HDDSize::Auto){
            HDD_Search_auto(curr_budget*0.2);
        }
        MB_Search(config->budget);
        return true;
    }
    else if(config->userTasks == UserTasks::ContentCreation) {
        if(config->ssdSize == SSDSize::None) {
            optimalConfigurations.ssd.name = "НЕТ";
        }
        else if(config->ssdSize != SSDSize::Auto)
        {
            SSD_Search(config->budget*0.25);
        }
        if(config->hddSize == HDDSize::None) {
            optimalConfigurations.hdd.name = "НЕТ";
        }
        else if(config->hddSize != HDDSize::Auto) {
            HDD_Search(config->budget*0.2);
        }
        double curr_budget = temp_budget;
        CPU_Search(curr_budget*0.35);
        GPU_Search(curr_budget*0.35);
        RAM_config_auto(curr_budget*0.15);
        if(config->ssdSize == SSDSize::Auto){
            SSD_Search_auto(curr_budget*0.15);
        }
        if(config->hddSize == HDDSize::Auto){
            HDD_Search_auto(curr_budget*0.15);
        }
        MB_Search(config->budget);
        return true;
    }
    else if(config->userTasks == UserTasks::Study) {
        if(config->ssdSize == SSDSize::None) {
            optimalConfigurations.ssd.name = "НЕТ";
        }
        else if(config->ssdSize != SSDSize::Auto)
        {
            SSD_Search(config->budget*0.25);
        }
        if(config->hddSize == HDDSize::None) {
            optimalConfigurations.hdd.name = "НЕТ";
        }
        else if(config->hddSize != HDDSize::Auto) {
            HDD_Search(config->budget*0.2);
        }
        double curr_budget = temp_budget;
        if(config->gpuMaker == GPUMaker::Auto)
        {
            CPU_Search(curr_budget*0.5);
            GPU_Search(curr_budget*0.1);
        }
        else if(config->gpuMaker == GPUMaker::None){
            CPU_Search(curr_budget*0.65);
            GPU_Search(0);
        }
        else{
            CPU_Search(curr_budget*0.4);
            GPU_Search(curr_budget*0.3);
        }
        RAM_config_auto(curr_budget*0.15);
        if(config->ssdSize == SSDSize::Auto){
            SSD_Search_auto(curr_budget*0.15);
        }
        if(config->hddSize == HDDSize::Auto){
            HDD_Search_auto(curr_budget*0.15);
        }
        MB_Search(config->budget);
        return true;

    }
    else if(config->userTasks == UserTasks::OfficeTasks) {
        if(config->ssdSize == SSDSize::None) {
            optimalConfigurations.ssd.name = "НЕТ";
        }
        else if(config->ssdSize != SSDSize::Auto)
        {
            SSD_Search(config->budget*0.25);
        }
        if(config->hddSize == HDDSize::None) {
            optimalConfigurations.hdd.name = "НЕТ";
        }
        else if(config->hddSize != HDDSize::Auto) {
            std::cout << "HDD_Search manual\n";
            HDD_Search(config->budget*0.2);
        }
        double curr_budget = temp_budget;

        if(config->gpuMaker == GPUMaker::Auto)
        {
            CPU_Search(curr_budget*0.6);
            GPU_Search(curr_budget*0.1);
        }
        else if(config->gpuMaker == GPUMaker::None){
            CPU_Search(curr_budget*0.65);
            GPU_Search(0);
        }
        else{
            CPU_Search(curr_budget*0.5);
            GPU_Search(curr_budget*0.2);
        }

        RAM_config_auto(curr_budget*0.15);
        if(config->ssdSize == SSDSize::Auto){
            SSD_Search_auto(curr_budget*0.15);
        }
        if(config->hddSize == HDDSize::Auto){
            std::cout << "HDD_Search auto\n";

            HDD_Search_auto(curr_budget*0.15);
        }
        MB_Search(config->budget);
        return true;
    }
    else if(config->userTasks == UserTasks::Other) {
        if(config->ssdSize == SSDSize::None) {
            optimalConfigurations.ssd.name = "НЕТ";
        }
        else if(config->ssdSize != SSDSize::Auto)
        {
            SSD_Search(config->budget*0.25);
        }
        if(config->hddSize == HDDSize::None) {
            optimalConfigurations.hdd.name = "НЕТ";
        }
        else if(config->hddSize != HDDSize::Auto) {
            HDD_Search(config->budget*0.2);
        }
        double curr_budget = temp_budget;
        CPU_Search(curr_budget*0.25);
        GPU_Search(curr_budget*0.45);
        RAM_config_auto(curr_budget*0.15);
        if(config->ssdSize == SSDSize::Auto){
            SSD_Search_auto(curr_budget*0.15);
        }
        if(config->hddSize == HDDSize::Auto){
            HDD_Search_auto(curr_budget*0.15);
        }
        MB_Search(config->budget);
        return true;
    }
    else {
        ui->statusbar->showMessage("ERROR !!!");
        return false;
    }
}

std::string PC_build_assist::readFile(const std::string &filename)
{
    std::ifstream file;
    file.open(filename);

    if (file)
    {
        std::stringstream strStream;
        strStream << file.rdbuf();
        return strStream.str();
    }
    else
    {
        std::cout << "File reading error!";
        return {};
    }
}




