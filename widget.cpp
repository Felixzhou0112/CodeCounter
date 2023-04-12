#include "widget.h"
#include "ui_widget.h"
#include <QDir>
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btn_choose_clicked()
{
    QFileDialog* m_fileDialog = new QFileDialog(this);
    m_fileDialog->setWindowTitle(tr("Open"));
    m_fileDialog->setDirectory(".");
//    m_fileDialog->setNameFilter(tr("Files(*.*)"));
    m_fileDialog->setFileMode(QFileDialog::ExistingFiles);

//    m_fileDialog->show();
    if(m_fileDialog->exec() == QDialog::Accepted)
    {
        QStringList files = m_fileDialog->selectedFiles();

        for(int i = 0; i < files.count(); i++)
        {
            QString path = files[i];
            calculateFileLines(path);
        }
    }
}


void Widget::on_btn_calculate_clicked()
{
    auto path = ui->edt_path->text().trimmed();
    if (pathIsValid(path))
    {
        calculateTotalLines(path);
    }
}


bool Widget::pathIsValid(QString path)
{
    Q_UNUSED(path);
//    if (!path.isEmpty())
//    {

//    }

    return true;
}

void Widget::calculateFileLines(QString filePath)
{
    int allH = 0;
    int allBad = 0;
    qDebug() << "path:" << filePath;
    QStringList list;
    int eNum = 0;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly))
    {
        while (!file.atEnd())
        {
            QByteArray tmp = file.readLine();
            list << tmp;
            if(tmp.isEmpty() || tmp.split(',').first().isEmpty())
            {
                eNum++;
            }
        }
        file.close();
    }
    int gTmp = list.count() - eNum;
    allH += list.count();
    allBad += eNum;
    QFileInfo info(filePath);
    QString str = QString("%1行数: %2, 无效行数: %3, 有效行数: %4").arg(info.fileName())
            .arg(QString::number(list.count())).arg(QString::number(eNum)).arg(QString::number(gTmp));
//    qDebug() << str;
    ui->edt_result->append(str);

//    qDebug() << QString("文件\350\241\214\346\225\260: %0, \346\211\200\346\234\211\350\241\214\346\225\260: %1, \346\234\211\346\225\210\350\241\214\346\225\260: %2, \346\227\240\346\225\210\350\241\214\346\225\260: %3").arg(QString::number(allD))
//                   .arg(QString::number(allH)).arg(QString::number(allH - allBad)).arg(QString::number(allBad));
//         文件数:  , 所有行数:  , 有效行数:  , 无效行数:

}

void Widget::calculateTotalLines(QString path)
{
    QDir dir(path);
    QStringList filter;
    filter << ".h" << ".cpp";
    auto infoList = dir.entryInfoList(filter);

    for(auto item : infoList)
    {
        if(item.isFile())
        {
            calculateFileLines(item.absoluteFilePath());
        }
        else if(item.isDir())
        {
            calculateTotalLines(item.absoluteFilePath());
        }
        else
        {
            qDebug() << "something amazing";
        }
    }
}

