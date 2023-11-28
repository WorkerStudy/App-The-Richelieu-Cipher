#include "shifr.h"
#include "ui_shifr.h"
#include <QDebug>
#include <QStringList>
#include <QString>
#include <QList>

Shifr::Shifr(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Shifr)
{
    ui->setupUi(this);
}

Shifr::~Shifr()
{
    delete ui;
}
void Shifr::MainLogic(){

   QString str= ui->write->toPlainText();
   QString strSH=NULL;//зашифрованая
   str=str.toUpper();
    QList<QString> keys = ui->number->text().split(";");
   QList<QString> words = str.split(" "); // запись и разделение слов
  // QList<QString> keys = key.split(";"); // запись и разделение слов
   str=nullptr;
   for(int i=0; i < words.size(); ++i){
       str+=words.at(i);
   }

  str= str.simplified();//удаляем пробелы
  qDebug() << str;
  for(int i=0;i<keys.size();i++){
  strSH+=EditWord(str,keys.at(i));
  strSH+=" ";
  str.remove(0,keys.at(i).length());//удаление символов из строки
  }




    ui->Answer->setText(strSH);

}

QString Shifr::EditWord(QString str,QString number){

    QString newstr;
    for (int i=0;i<number.length();i++ ) {
      QString ss= number.at(i);// запись числа

      if(str.length() < ss.toInt()-1){return str;};//Проверка если цифра в ключе ссылается за пределы слова

      qDebug()<< ss << "Длина:"<< number.length() << str.at(ss.toInt()-1) << "Что хранит number" << number << "str" << str;
       newstr+=str.at(ss.toInt()-1);
    }
    return newstr;
}

void Shifr::on_pushButton_clicked()
{
    MainLogic();
}

