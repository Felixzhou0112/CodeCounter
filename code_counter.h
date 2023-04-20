#ifndef CODE_COUNTER_H
#define CODE_COUNTER_H

#include <QObject>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include "stdafx.h"

class CodeCounter : public QObject
{
    Q_OBJECT

public:
    explicit CodeCounter(QObject *parent = nullptr);
    Q_INVOKABLE void calculateFileLines(const QUrl& qurl);
};

#endif // CODE_COUNTER_H
