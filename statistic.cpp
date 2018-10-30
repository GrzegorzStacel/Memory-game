#include "statistic.h"

#include <QFile>
#include <QDebug>

QString statistic::totalTime;
int statistic::totalCorrect;
int statistic::totalWrong;

int statistic::correct;
int statistic::wrong;
int statistic::bestTime;


statistic::statistic(){

}


void statistic::read(int value){
    //qDebug() << "read";

    QFile file;

//    switch (value) {
//        case 1: file.setFileName(":/file/files/totalTime.txt"); return;
//        case 2: file.setFileName(":/file/files/totalCorrect.txt"); return;
//        case 3: file.setFileName(":/file/files/totalWrong.txt"); return;
//    }
    file.setFileName(":/file/files/totalTime.txt");
    //qDebug() << "read2";
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        qDebug() << "read from file:" << line;
    }

    file.close();
}

void statistic::write(int value){

    QFile file;

    switch (value) {
        case 1: file.setFileName(":/file/files/totalTime.txt"); return;
        case 2: file.setFileName(":/file/files/totalCorrect.txt"); return;
        case 3: file.setFileName(":/file/files/totalWrong.txt"); return;
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;


    QTextStream out(&file);

    switch (value) {
        case 1: out << getTotalTIme(); return;
        case 2: out << getTotalCorrect(); return;
        case 3: out << getTotalWrong(); return;
    }
}
