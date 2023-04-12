#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btn_choose_clicked();

    void on_btn_calculate_clicked();

private:
    bool pathIsValid(QString path);

    void calculateFileLines(QString filePath);

    void calculateTotalLines(QString path);

private:
    Ui::Widget *ui;


};
#endif // WIDGET_H
