
#include <cmath>
#include <QMessageBox>
#include "Dialog.h"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_resultButton_clicked()
{
    bool ok;

    // A
    double x1 = ui->x1LineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }
    double y1 = ui->y1LineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }

    // B
    double x2 = ui->x2LineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }
    double y2 = ui->y2LineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }

    // C
    double x3 = ui->x3LineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }
    double y3 = ui->y3LineEdit->text().toDouble( &ok );
    if ( !ok ) {
        QMessageBox::information( this, tr( "Ошибка" ), tr( "Вы ввели некорректные данные" ) );
        return;
    }

    // Result
    double abDistance = std::sqrt( std::pow( x2 - x1, 2 ) + std::pow( y2 - y1, 2 ) );
    double bcDistance = std::sqrt( std::pow( x3 - x2, 2 ) + std::pow( y3 - y2, 2 ) );
    double sum = abDistance + bcDistance;

    // Output
    ui->resultLineEdit->setText( QString::number( sum ) );
}
