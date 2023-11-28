#ifndef SHIFR_H
#define SHIFR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Shifr; }
QT_END_NAMESPACE

class Shifr : public QMainWindow
{
    Q_OBJECT

public:
    Shifr(QWidget *parent = nullptr);
    ~Shifr();
    void MainLogic();
    QString EditWord(QString str,QString number=NULL);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Shifr *ui;
};
#endif // SHIFR_H
