#ifndef TABRUNBYRUN_H
#define TABRUNBYRUN_H

#include <QWidget>
#include <QDir>
#include "TQtWidget.h"

#include "TH1.h"
#include "TH2F.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TFolder.h"

#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "ConfigGui.h"

namespace Ui {
class TabRunByRun;
}

class TabRunByRun : public QWidget
{
    Q_OBJECT

public:
    explicit TabRunByRun(QWidget *parent = 0);
    ~TabRunByRun();
    void updateRootFile(const char *file);
    void updateRootPhysicsFile(const char *file);

private slots:
    void on_pushButtonZoomIn_clicked();

    void on_pushButtonZoomOut_clicked();

    void on_pushButton_clicked();

    void on_buttonTaps1R_clicked();

    void on_buttonTaps2R_clicked();

    void on_buttonTaps3R_clicked();

    void on_buttonTaps1Plus_clicked();

    void on_buttonTaps2Plus_clicked();

    void on_buttonTaps3Plus_clicked();

    void on_buttonTaps1Minus_clicked();

    void on_buttonTaps2Minus_clicked();

    void on_buttonTaps3Minus_clicked();

public slots:
        void UpdateAllGraphics();
        void UpdateGraphicsPhysics();
        void UpdateGraphicsDetectors();
private:
    Ui::TabRunByRun *ui;
    ConfigGUI configGUI;
    int horizontalSize;
    int verticalSize;
    TFile*  file;
    TFile* PhysicsFile;

    TH2F * h2;
    void FillWidget(TQtWidget *Twidget, TFile* tfile, std::string detector, std::string filename);
};

#endif // TABRUNBYRUN_H
