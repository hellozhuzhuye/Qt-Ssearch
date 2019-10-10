#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QString>
#include <QDateTime>
using namespace std;


extern "C"
{
#include "Everything.h"
}


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QString searchstr=ui->lineEdit->text();


    Everything_SetSearchW(L"ttaa");
    Everything_QueryW(TRUE);

    {
        DWORD i;

        for (i = 0; i < Everything_GetNumResults(); i++)
        {
            //获取文件名
            LPCWSTR fname=Everything_GetResultFileNameW(i);
            QString filename = QString::fromWCharArray(fname);

            //获取文件路径
            LPCWSTR lpPath=Everything_GetResultPathW(i);
            QString filepath = QString::fromWCharArray(lpPath);

            //获取文件大小
            LARGE_INTEGER size;
            Everything_GetResultSize(i,&size);
            //QString filesize=;


            //获取最后修改时间
//            FILETIME dateCreated;
//            Everything_GetResultDateCreated(i,&dateCreated);
//            //Everything_GetResultDateModified(i,&dateModified);
//            //QDateTime filemodifytime();
//            SYSTEMTIME dircreatetime;

//            FileTimeToSystemTime(&dateCreated,&dircreatetime);
//            QDateTime qdatetime;
//            qdatetime.setDate(QDate(dircreatetime.wYear, dircreatetime.wMonth, dircreatetime.wDay));
//            qdatetime.setTime(QTime(dircreatetime.wHour, dircreatetime.wMinute, dircreatetime.wSecond));
//            QString format = "yyyy-MM-dd hh:mm:ss";
//            QString str_time=qdatetime.toString(format);

//            FILETIME lpFileTime;
//            FileTimeToLocalFileTime(&dateCreated,&lpFileTime);  //第二步 将FILETIME转换为本地时间
//            FileTimeToSystemTime(&lpFileTime,&dircreatetime);




            int iRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(iRow);

            ui->tableWidget->setItem(iRow,0,new QTableWidgetItem(filename));
            ui->tableWidget->setItem(iRow,1,new QTableWidgetItem(filepath));
            ui->tableWidget->setItem(iRow,2,new QTableWidgetItem());
            ui->tableWidget->setItem(iRow,3,new QTableWidgetItem("hello4"));

        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
