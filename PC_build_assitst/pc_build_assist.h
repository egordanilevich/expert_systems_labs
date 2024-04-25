#ifndef PC_BUILD_ASSIST_H
#define PC_BUILD_ASSIST_H

#include <QMainWindow>
#include <QVector>
#include "utility.h"
#include "json_reader.h"
#include"PC_components.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PC_build_assist; }
QT_END_NAMESPACE

class PC_build_assist : public QMainWindow
{
    Q_OBJECT

public:
    PC_build_assist(QWidget *parent = nullptr);
    ~PC_build_assist();

private slots:
    void on_comboBox_target_activated(int index);

    void on_comboBox_cost_activated(int index);

    void on_comboBox_CPU_activated(int index);

    void on_comboBox_GPU_activated(int index);

    void on_comboBox_RAM_activated(int index);

    void on_comboBox_activated(int index);

    void on_comboBox_HDD_activated(int index);

    void on_comboBox_RAM_activated(const QString &arg1);

    void on_comboBox_SSD_activated(const QString &arg1);

    void on_comboBox_HDD_activated(const QString &arg1);

    void on_pushButton_search_clicked();

    void on_comboBox_GPU_activated(const QString &arg1);

private:
    PCConfigurations* config;
    Ui::PC_build_assist *ui;
//    OptimalConfiguration *pc;

    std::vector<Processor> processors;
    std::vector<GraphicsCard> graphicsCards;
    std::vector<SSD> ssds;
    std::vector<HDD> hdds;
    std::vector<Motherboard> motherboards;
    OptimalConfiguration optimalConfigurations;
    double temp_budget;
    std::string target_key;

    void loadConfigurations();
    void CPU_Search(double cost);
    void MB_Search(double cost);
    void GPU_Search(double cost);
    void SSD_Search(double cost);
    void SSD_Search_auto(double cost);
    void HDD_Search(double cost);
    void HDD_Search_auto(double cost);
    void RAM_config();
    void RAM_config_auto(double cost);
    void target_params();
    bool Create_config();
    std::string readFile(const std::string &filename);



    QString processorFile_intel = "CPU_intel.txt";
    QString graphicsCardFile_nvidia = "GPU_nvidia.txt";
    QString processorFile_AMD = "CPU_AMD.txt";
    QString graphicsCardFile_AMD = "GPU_AMD.txt";
    QString ssdFile = "SSD.txt";
    QString hddFile = "HHD.txt";
    QString motherboardFile_intel = "MB_intel.txt";
    QString motherboardFile_AMD = "MB_AMD.txt";
};
#endif // PC_BUILD_ASSIST_H
