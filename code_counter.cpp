#include "code_counter.h"

CodeCounter::CodeCounter(QObject *parent)
    : QObject{parent}{}

QString urlToPath(const QUrl& qurl) {
    return QDir::toNativeSeparators(qurl.toLocalFile());
}

void CodeCounter::calculateFileLines(const QUrl& qurl)
{
    qDebug() << "qurl:" << qurl;
    QString path = urlToPath(qurl);
    qDebug() << "path:" << path;

    int filter_lines = 0;
    int valid_lines = 0;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file: " << file.errorString();
        return;
    }

    QTextStream i(&file);
    while (!i.atEnd())
    {
        QString line = i.readLine();
        line.trimmed().isEmpty() ? filter_lines++ : valid_lines++;
    }
    file.close();

    QFileInfo info(path);
    qDebug() << info.fileName()
             << "\t行数:" << filter_lines + valid_lines
             << "\t无效行数:" << filter_lines
             << "\t有效行数:" << valid_lines
             << "\n-------------------------";
}
